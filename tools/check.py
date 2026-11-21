"""Compile each C11 exercise with GCC and run its regression examples."""

import argparse
from concurrent.futures import ThreadPoolExecutor
import os
from pathlib import Path
import shutil
import subprocess
import sys


ROOT = Path(__file__).resolve().parents[1]


def build_exercises(compiler):
    source_dir = ROOT / "ZZU_C_Experiment"
    build_dir = ROOT / "build"
    sources = sorted(source_dir.glob("C_Experiment_*/*.c"))
    if not sources:
        raise ValueError("No exercise sources found.")

    temp_dir = build_dir / "tmp"
    temp_dir.mkdir(parents=True, exist_ok=True)
    environment = os.environ | {
        "TMP": str(temp_dir), "TEMP": str(temp_dir), "TMPDIR": str(temp_dir)
    }

    def compile_one(source):
        source.read_bytes().decode("utf-8")
        extension = ".exe" if os.name == "nt" else ""
        binary = build_dir / source.parent.name / (source.stem + extension)
        binary.parent.mkdir(parents=True, exist_ok=True)
        result = subprocess.run(
            [
                compiler, "-std=c11", "-O2", "-Wall", "-Wextra", "-Wpedantic", "-Werror",
                "-finput-charset=UTF-8", "-fexec-charset=UTF-8", str(source),
                "-o", str(binary), "-lm",
            ],
            env=environment, capture_output=True, timeout=45,
        )
        if result.returncode != 0:
            diagnostics = result.stderr.decode("utf-8", errors="replace").strip()
            raise ValueError(f"Compilation failed for {source.name}:\n{diagnostics}")
        return source.stem, binary

    with ThreadPoolExecutor(max_workers=4) as pool:
        compiled = dict(pool.map(compile_one, sources))
    if len(compiled) != len(sources):
        raise ValueError("Exercise filenames must be unique.")
    return compiled


def run_examples(compiled):
    from cases import CASES

    if set(compiled) != {case.exercise for case in CASES}:
        raise ValueError("Each exercise must have at least one example.")

    for case in CASES:
        result = subprocess.run(
            [str(compiled[case.exercise])],
            input=case.input_text.encode("utf-8"), capture_output=True, timeout=5,
        )
        stdout = result.stdout.decode("utf-8").replace("\r\n", "\n")
        stderr = result.stderr.decode("utf-8").replace("\r\n", "\n")
        try:
            if result.returncode != case.returncode:
                raise ValueError(f"Expected exit {case.returncode}, got {result.returncode}")
            if not case.matches(stdout + stderr):
                raise ValueError(f"Expected {case.expected}")
        except (ValueError, IndexError, AttributeError) as error:
            raise ValueError(
                f"{case.exercise} ({case.label}): {error}\n"
                f"  stdout={stdout!r}\n  stderr={stderr!r}"
            ) from error
    return len(CASES)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--cc", default="gcc", help="GCC executable or path (default: gcc)")
    parser.add_argument("--build-only", action="store_true", help="compile all exercises without running the examples")
    args = parser.parse_args()
    compiler = shutil.which(args.cc)
    if compiler is None:
        parser.error(f"cannot find {args.cc!r}; install GCC or pass --cc")

    try:
        compiled = build_exercises(compiler)
        print(f"Compiled {len(compiled)} exercises (C11, warnings treated as errors).", flush=True)
        if not args.build_only:
            examples = run_examples(compiled)
            print(f"Passed {examples} examples across {len(compiled)} exercises.")
    except (OSError, ValueError, subprocess.TimeoutExpired) as error:
        print(error, file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
