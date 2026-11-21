# 郑州大学 C 语言实验练习

这里整理了郑州大学（ZZU）电气与信息工程学院 2025 级在 2026 学期的 C 语言实验参考代码和实验资料。建议先自己完成题目，再用仓库里的实现对照思路和运行结果。

## 目录

| 路径 | 内容 |
| --- | --- |
| [`ZZU_C_Experiment/`](./ZZU_C_Experiment) | C 源码，按实验编号分目录。`C_Experiment_1/1_1.c` 表示实验一第 1 题。 |
| [`ZZU_C_result/`](./ZZU_C_result) | 历史编译产物。最新版 Windows 程序请见[下载版本包](#下载版本包)。 |
| [`C语言实验.pdf`](./C语言实验.pdf) 和 [`C语言实验.docx`](./C语言实验.docx) | 实验资料。 |

## 从源码编译一道题

以下是 Windows PowerShell 示例。需要已经安装 GCC，并且 `gcc --version` 能显示版本。打开仓库目录后，编译实验一第 1 题并输入三个整数：

```powershell
gcc -std=c11 -Wall -Wextra .\ZZU_C_Experiment\C_Experiment_1\1_1.c -o "$env:TEMP\zzu-c-1_1.exe"
'1 2 3' | & "$env:TEMP\zzu-c-1_1.exe"
```

预期输出 `6`。生成的程序在系统临时目录里。要练习其他题，按实验编号找到对应的 `.c` 文件，并用自己的样例检查结果。

## 下载版本包

在 [Releases 最新发布页](https://github.com/Bohese1379A/ZZU_C_practice/releases/latest) 展开 **Assets**，下载文件名以 `-windows.zip` 结尾的 Windows 版压缩包。解压后，在 `ZZU_C_result/` 中按实验编号找到对应的 `.exe`。
