"""Examples for each lab and regression cases for repaired behavior."""

from dataclasses import dataclass
import math
import re
from typing import Callable


@dataclass(frozen=True)
class Case:
    exercise: str
    expected: str | Callable[[str], bool]
    input_text: str = ""
    returncode: int = 0
    label: str = "题目样例"

    def matches(self, output):
        if isinstance(self.expected, str):
            return self.expected in output
        return self.expected(output)


def last_ints(line):
    return list(map(int, re.findall(r"-?\d+", line.split("：", 1)[-1])))


def random_statistics(output):
    lines = output.splitlines()
    numbers = last_ints(lines[0])
    return (
        len(numbers) == 10 and all(50 <= n <= 100 for n in numbers)
        and int(lines[1].split("：")[1]) == max(numbers)
        and int(lines[2].split("：")[1]) == min(numbers)
        and math.isclose(float(lines[3].split("：")[1]), sum(numbers) / 10)
    )


def score_bands(output):
    lines = output.splitlines()
    scores = last_ints(lines[0])
    reported = [int(line.rsplit(": ", 1)[-1]) for line in lines[2:]]
    bands = [(0, 59), (60, 69), (70, 79), (80, 89), (90, 100)]
    return len(scores) == 20 and all(0 <= n <= 100 for n in scores) and reported == [
        sum(low <= n <= high for n in scores) for low, high in bands
    ]


def sorted_random(output):
    original, result = map(last_ints, output.splitlines())
    return len(original) == 10 and all(1 <= n <= 50 for n in original) and result == sorted(original, reverse=True)


def four_rows(output):
    rows = [last_ints(line) for line in output.splitlines()[1:]]
    return len(rows) == 4 and all(len(row) == 5 and all(1 <= n <= 100 for n in row) for row in rows)


def removed_duplicates(output):
    original, result = map(last_ints, output.splitlines())
    return len(original) == 100 and all(-10 <= n <= 10 for n in original) and result == list(dict.fromkeys(original))


def matrix_sums(output):
    rows = [last_ints(line) for line in output.splitlines()[1:]]
    return len(rows) == 2 and all(len(row) == 4 and row[-1] == sum(row[:-1]) for row in rows)


def matrix_maximum(output):
    lines = output.splitlines()
    matrix = [last_ints(line) for line in lines[1:4]]
    row, col = last_ints(lines[5])
    maximum, = last_ints(lines[4])
    return 1 <= row <= 3 and 1 <= col <= 4 and matrix[row - 1][col - 1] == maximum == max(map(max, matrix))


def correct_root(output):
    match = re.search(r"近似根:\s*([-.\d]+)", output)
    if match is None:
        return False
    root = float(match.group(1))
    return -1 < root < 0 and abs(root**5 + 2 * root**3 - root**2 + root + 1) < 1e-8


def all_fragments(*fragments):
    return lambda output: all(fragment in output for fragment in fragments)


def reject(exercise, input_text, message):
    return Case(exercise, message, input_text, 1, "无效输入")


fib = "1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765"
CASES = [
    Case("1_1", "6\n", "1 2 3\n"),
    Case("1_2", all_fragments("sum=9", "diff=3", "prod=18", "quot=2"), "6 3\n"),
    Case("1_3", "55.000000\n", "1 2 3 4 5\n"),
    Case("1_4", "6.000000\n", "1 4 9\n"),
    Case("1_5", all_fragments("area=12.566371", "circumference=12.566371"), "2\n"),
    Case("1_6", "What a beautiful campus!\nI wish you every success!\n"),
    Case("2_1", "15.652480\n"),
    Case("2_2", "prod=27\nquot=3 remainder=0\n", "9 3\n"),
    Case("2_3", "100.00\n", "212\n"),
    Case("2_4", "circumference=15.431490\narea=18.949870\n"),
    Case("2_5", "c = 3.123457\n"),
    Case("2_6", "0\n"),
    Case("3_1", "a=      3 b=      4 c=      5\nx=  1.414 y=  1.732 z=  2.712\n"),
    Case("3_2", "a=3 b=4 c=5\nx=1.414 y=1.732 z=2.712\n", "3\n4\n5\n1.414\n1.732\n2.712\n"),
    Case("3_3", "x1=a+b+c=3+4+5=12\nx2=a-b-c=3-4-5=-6\n", "3 4 5\n"),
    Case("3_4", "65 66 67 68\n", "A B C D\n"),
    Case("3_5", "< = > ?\n"),
    Case("3_6", "m=12345678 n=3456789\n"),
    Case("3_7", all_fragments("20 -> octal=24 hex=14", "64 -> octal=100 hex=40", "127 -> octal=177 hex=7F")),
    Case("3_8", "  1.41   1.73   2.71\n"),
    Case("3_9", "0.333333%\n"),
    Case("3_10", "a\nb\nc\n", "A B\nC\n"),
    Case("4_1", "9\n", "2 9 -3\n"),
    Case("4_2", "19.000000\n", "10\n"),
    Case("4_3", "B\n", "89\n"),
    Case("4_4", "digits=3\n1 3 5\n531\n", "135\n"),
    Case("4_5", "x1=2.000000 x2=1.000000\n", "1 -3 2\n"),
    Case("5_1", "5050\n"),
    Case("5_2", "4037913\n"),
    Case("5_3", "0.8639904324\n"),
    Case("5_4", "digits=10 letters=10 others=10\n", "0123456789abcdefghij!!!!!!!!!!\n"),
    Case("5_5", fib),
    Case("6_1", "4037913\n"),
    Case("6_2", all_fragments("1*1= 1", "8*9=72", "9*9=81")),
    Case("6_3", "   1\n  121\n 12321\n1234321\n"),
    Case("6_4", "   A\n  BBB\n CCCCC\nDDDDDDD\n"),
    Case("6_5", "   *\n  *+*\n *+*+*\n*+*+*+*\n"),
    Case("6_6", "cock=0 hen=25 chick=75\ncock=4 hen=18 chick=78\ncock=8 hen=11 chick=81\ncock=12 hen=4 chick=84\n"),
    Case("6_7", "171700\n"),
    Case("6_8", "x=2, y=3, z=1\n"),
    Case("6_9", "需要 15 年"),
    Case("6_10", "997, 991, 983"),
    Case("7_1", random_statistics),
    Case("7_2", score_bands),
    Case("7_3", sorted_random),
    Case("7_4", four_rows),
    Case("7_5", removed_duplicates, "100\n"),
    Case("7_6", all_fragments("最高成绩：90", "最低成绩：60", "平均成绩：80.00", "高于平均成绩的人数：2"), "3 90 60 90\n"),
    Case("7_7", "0 1 1 2 4 7 13 24 44 81 149 274 504 927 1705 3136 5768 10609 19513 35890"),
    Case("7_8", "反序后：66 98 76 89 67"),
    Case("8_1", "   1   2   3\n   4   5   6\n   7   8   9\n"),
    Case("8_2", "   1   2\n   3   4\n", "2\n"),
    Case("8_3", "   1   0   0\n   0   1   0\n   0   0   1\n", "3\n"),
    Case("8_4", matrix_sums, "2 3\n"),
    Case("8_5", matrix_maximum, "3 4\n"),
    Case("8_6", all_fragments("录取分数线: 80", "考号: 103, 成绩: 96\n考号: 101, 成绩: 80"), "3 101 80 102 60 103 96 2\n"),
    Case("9_1", "C(5,2) = 10\n", "5 2\n"),
    Case("9_2", "= 4037913\n"),
    Case("9_3", "2332 是回文数\n", "2332\n"),
    Case("9_4", all_fragments("FS: 17710", "V: 885.500000")),
    Case("9_5", all_fragments("s1: 4.935", "s2: 4.935")),
    Case("9_6", "数字字符的个数: 5\n", "SD234.6FGtt5\n"),
    Case("9_7", all_fragments("最大公约数: 6", "最小公倍数: 36"), "12 18\n"),
    Case("9_8", "两个实根: x1 = 2.000000, x2 = 1.000000\n", "1 -3 2\n"),
    Case("9_9", correct_root),
    Case("9_10", "1到10之间所有素数之和: 17\n", "1 10\n"),
    Case("9_11", all_fragments(fib, "前20项的和: 17710")),
    Case("11_1", "从小到大排序: -1 2 3\n", "3 -1 2\n"),
    Case("11_2", "逆序后: 2.50 -1.00 3.00", "3 3 -1 2.5\n"),
    Case("11_3", "交换后: x=7, y=2\n", "2 7\n"),
    Case("11_4", "月份名: December\n", "12\n"),
    Case("11_5", "排序后(降序): 9 8 7 6 5 4 3 2 1 0", "0 1 2 3 4 5 6 7 8 9\n"),
    Case("11_6", "输入的字符串: abc def\n", "abc def\n"),
    Case("11_7", "字符串长度: 7\n", "abc def\n"),
    Case("11_8", "出现次数: 3\n", "aaaa\naa\n"),
    Case("1_1", "6442450941\n", "2147483647 2147483647 2147483647\n", label="求和不溢出"),
    reject("1_1", "2147483648 0 0\n", "Input error"),
    reject("1_3", "1 2\n", "Input error"),
    Case("1_2", "divide by zero", "8 0\n", label="除数为零"),
    Case("2_2", "prod=2147483648\nquot=2147483648 remainder=0\n", "-2147483648 -1\n", label="整数边界"),
    reject("3_2", "1 2 3 4 bad 6\n", "Input error"),
    reject("4_2", "3.5\n", "expected an integer"),
    reject("4_3", "101\n", "from 0 to 100"),
    reject("4_4", "123456\n", "at most five digits"),
    reject("4_4", "12x\n", "at most five digits"),
    Case("4_4", "digits=3\n1 2 0\n021\n", "120\n", label="逆序输出保留零"),
    Case("4_5", "complex roots: 0.000000+1.000000i and 0.000000-1.000000i", "-1 0 -1\n", label="负二次系数的共轭根"),
    Case("4_5", "x=2.000000\n", "1 -4 4\n", label="重根"),
    Case("4_5", all_fragments("Not a quadratic equation", "one root: 2.000000"), "0 2 -4\n", label="退化为一次方程"),
    reject("5_4", "abc", "expected 30 characters"),
    reject("7_5", "101\n", "元素个数"),
    reject("7_6", "0\n", "学生人数"),
    reject("7_6", "2 80 x\n", "成绩应为"),
    reject("8_2", "0\n", "方阵边长"),
    reject("8_3", "11\n", "方阵边长"),
    reject("8_4", "2 -1\n", "列数必须"),
    reject("8_5", "0 3\n", "行数必须"),
    reject("8_5", "2 bad\n", "列数必须"),
    reject("8_6", "1 1001 90 0\n", "录取人数"),
    Case("9_1", "C(20,10) = 184756", "20 10\n", label="阶乘范围上限"),
    Case("9_1", "C(0,0) = 1", "0 0\n", label="零元素"),
    reject("9_1", "4 5\n", "0 <= m <= n <= 20"),
    reject("9_1", "21 1\n", "0 <= m <= n <= 20"),
    Case("9_3", "2147483647 不是回文数", "2147483647\n", label="反转后超过 int"),
    Case("9_6", "数字字符的个数: 3", "甲1 2 x3\n", label="含空格及 UTF-8 字符"),
    Case("9_7", "最小公倍数: 2500050000", "50000 50001\n", label="超过 int 的最小公倍数"),
    reject("9_8", "nan 0 1\n", "需要三个有限的数"),
    Case("9_10", ": 2147483647\n", "2147483647 2147483647\n", label="INT_MAX 区间端点"),
    reject("11_2", "0\n", "数组长度"),
    reject("11_2", "2 1 bad\n", "需要指定数量"),
    reject("11_4", "13\n", "1-12"),
    reject("11_5", "1 2\n", "需要 10 个整数"),
    Case("11_6", "输入的字符串: last line\n", "last line", label="最后一行没有换行"),
    Case("11_7", "字符串长度: 1023\n", "x" * 1023 + "\r\n", label="缓冲区边界和 CRLF"),
    reject("11_7", "x" * 1024 + "\n", "1023"),
    Case("11_8", "出现次数: 0\n", "abc\nmissing\n", label="子串不存在"),
    Case("11_8", "出现次数: 0\n", "abc\n\n", label="空子串"),
]
