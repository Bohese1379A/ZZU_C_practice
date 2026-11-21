# 郑州大学 C 语言实验练习

这里整理了郑州大学（ZZU）电气与信息工程学院 2025 级在 2026 学期的 C 语言实验参考代码和实验资料。建议先自己完成题目，再用仓库里的实现对照思路和运行结果。

> **Codex 对照版。** 由 Codex 从基线提交 `a8c78e9` 独立改进，用于对比人工版本。修复依据、验证结果和对比方法见[改进记录](./docs/codex-review.md)。

## 目录

| 项目 | 位置 |
| --- | --- |
| 程序结构、数据类型和输入输出 | [实验一](./ZZU_C_Experiment/C_Experiment_1)、[实验二](./ZZU_C_Experiment/C_Experiment_2)、[实验三](./ZZU_C_Experiment/C_Experiment_3) |
| 选择结构和循环 | [实验四](./ZZU_C_Experiment/C_Experiment_4)、[实验五](./ZZU_C_Experiment/C_Experiment_5)、[实验六](./ZZU_C_Experiment/C_Experiment_6) |
| 一维数组与二维数组 | [实验七](./ZZU_C_Experiment/C_Experiment_7)、[实验八](./ZZU_C_Experiment/C_Experiment_8) |
| 函数和指针 | [实验九](./ZZU_C_Experiment/C_Experiment_9)、[实验十一](./ZZU_C_Experiment/C_Experiment_11) |
| 原实验资料 | [PDF](./C语言实验.pdf)、[Word](./C语言实验.docx) |
| 构建与检验工具 | [tools/check.py](./tools/check.py)、[样例](./tools/cases.py) |

共 75 道现有练习。`C_Experiment_1/1_1.c` 表示实验一第 1 题。每份 `.c` 都有独立的 `main`，按题编译。题目和仓库原有的编号保持一致。

## 从源码编译一道题

以下是 Windows PowerShell 示例。需要已经安装 GCC，并且 `gcc --version` 能显示版本。打开仓库目录后，编译实验一第 1 题并输入三个整数：

```powershell
gcc -std=c11 -Wall -Wextra .\ZZU_C_Experiment\C_Experiment_1\1_1.c -o "$env:TEMP\zzu-c-1_1.exe" -lm
'1 2 3' | & "$env:TEMP\zzu-c-1_1.exe"
```

预期输出 `6`。生成的程序在系统临时目录里。要练习其他题，按实验编号找到对应的 `.c` 文件，并用自己的样例检查结果。

## 批量构建与检查

在仓库目录运行以下命令。需要 GCC 和 Python 3.10 或更新版本，无需安装第三方 Python 包。

```powershell
python tools/check.py
```

脚本按 C11 逐个编译，把编译警告视为错误，并运行正常及边界输入样例。每道题至少有一个运行样例。随机生成的数组和矩阵检查输出是否满足题意，例如末列是否等于同行元素之和。

如果只想编译，执行 `python tools/check.py --build-only`。程序生成在 `build/C_Experiment_*/` 下。Windows 上可运行 `.\build\C_Experiment_1\1_1.exe`。`build/` 和新生成的 `.exe` 由 `.gitignore` 忽略。

## 下载历史版本

[v1.0 Release](https://github.com/Bohese1379A/ZZU_C_practice/releases/tag/v1.0) 的 `release.v1.0.2026.zip` 保留了原先的 75 个 Windows 程序。解压后可在 `ZZU_C_result/` 中按实验编号查找。要运行本分支修复后的程序，请按上面的方法从源码重新编译。
