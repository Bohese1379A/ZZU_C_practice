# C 语言实验仓库的三版对比

这份记录比较 `ZZU_C_practice` 的初版、我跟着 Codex 练习 GitHub 后发布的版本，以及 Codex 独立改进的对照分支。三个版本都按同一套 100 分标准评价。评分依据是可查看的仓库内容、代表性源码、工作流日志和发布附件，权重侧重这个项目的教学、维护和下载使用。

## 对比对象

| 对象 | 对照版本 | 在这个项目中的用途 |
| --- | --- | --- |
| 初版 1.0.0 | 仓库里的实际标签是 [`v1.0`](https://github.com/Bohese1379A/ZZU_C_practice/releases/tag/v1.0)，提交 `1b87943` | 最早的源码和 Windows 实验程序合集 |
| 引导下改进的 1.0.3 | [`v1.0.3`](https://github.com/Bohese1379A/ZZU_C_practice/releases/tag/v1.0.3)，提交 `f849d6f` | 我练习 Issue、分支、PR 和发布，Codex 协助修改源码和配置自动打包后形成的正式版本 |
| Codex 独立对照版 | [`codex/completed-review`](https://github.com/Bohese1379A/ZZU_C_practice/tree/codex/completed-review)，以提交 `cf5dce7` 为准 | 从 `a8c78e9` 分出，用于对比独立改进方式的分支 |

## 评分

| 维度 | 满分 | 初版 `v1.0` | 引导版 `v1.0.3` | Codex 独立对照版 |
| --- | ---: | --- | --- | --- |
| README 与上手 | 15 | **7**　有项目简介和实验材料，首页缺少目录说明和编译步骤 | **13**　给出源码、资料和最新版下载入口，有一道可照做的编译示例 | **14**　按实验主题给出目录，还说明了单题编译和批量检查 |
| GitHub 流程与追溯 | 20 | **8**　有提交、版本标签和下载页，改动缘由主要靠上传历史追溯 | **19**　实际走过 Issue、验收、分支、PR、合并和发布，关键改动有记录 | **17**　独立分支区分了编码、修正、构建说明和 CI 提交，附有对照记录 |
| 源码讲解与可读性 | 20 | **9**　按实验编号组织，多数文件有题目简介，部分中文在网页 Diff 中难读 | **19**　75 份 C 源码均有知识点、解题思路和代码逻辑，难点有行内注释 | **15**　UTF-8、题目说明和共用输入函数提高了可读性，逐题讲解的深度仍可补足 |
| 输入边界与关键实现 | 15 | **8**　有基本实现，抽查发现占位输出和输入边界没有覆盖的情况 | **12**　修正了图案、公式和一批边界问题，部分题目的整数输入仍可收紧 | **14**　共用读入函数覆盖完整数字、范围和超长输入，检验样例更系统 |
| 自动构建与验证 | 15 | **2**　发布时已有编译结果，构建和验证需要手工执行 | **12**　Actions 从指定提交构建 75 个 Windows 程序并打包，部分行为在发布前有本地抽查 | **14**　Actions 严格编译 75 道练习并运行 117 个样例，当前工作流重点是回归检查 |
| 版本发布与下载 | 15 | **12**　已有正式 ZIP，仓库也追踪 75 个 `.exe`，下载入口分散 | **15**　正式发布 ZIP 可从 README 直达，标签、构建提交和发布附件可以对应 | **10**　README 讲清了重建方法，现成下载仍指向初版，分支修订的程序需要自己构建 |
| **总分** | **100** | **46** | **90** | **84** |

`v1.0.3` 的优势是逐题教学说明和可直接下载的正式版本。Codex 对照版的优势是可重复运行的回归检查和一致的输入处理。两次 Actions 运行验证的事情不同，正式版运行验证 Windows ZIP 能构建和上传，对照版运行验证严格编译和 117 个已定义样例。[v1.0.3 打包记录](https://github.com/Bohese1379A/ZZU_C_practice/actions/runs/44903889178) · [Codex 对照版检查记录](https://github.com/Bohese1379A/ZZU_C_practice/actions/runs/44905010559)

## 问题与改善

| 对象 | 发现的问题 | 具体改善 |
| --- | --- | --- |
| 初版 | 首页只介绍了项目身份，读者需要自己寻找题目、源码和可运行程序。 | 用短 README 提供源码、实验资料、Windows 下载三个入口，加上一条编译示例。 [初版 README](https://github.com/Bohese1379A/ZZU_C_practice/blob/v1.0/README.md) |
| 初版 | Git 追踪 75 个编译产物，同时又有独立的 Release ZIP。源码和程序更新容易不同步。 | 在主线用单独 PR 移除已跟踪的 `.exe`，把 ZIP 放到 Releases，README 指向最新版下载。引导版已完成这一项。 [PR #5](https://github.com/Bohese1379A/ZZU_C_practice/pull/5) |
| 初版 | 实验六 `6_3.c` 用固定字符串输出三行，题目要求的循环和第四行没有体现。 | 用外层控制行数，内层分别生成空格、递增部分和递减部分。两个改进版都改成了循环。 [初版源码](https://github.com/Bohese1379A/ZZU_C_practice/blob/v1.0/ZZU_C_Experiment/C_Experiment_6/6_3.c) |
| 引导版 | 打包工作流能确认程序编译并生成 ZIP，正常和边界行为的验证还主要靠本地样例。 | 用一个小 PR 加入回归检查，先覆盖实验 8.2、8.5 等现有案例。采用对照分支的检查思路，并以主线的输入输出约定编写预期结果。 [主线打包配置](https://github.com/Bohese1379A/ZZU_C_practice/blob/v1.0.3/.github/workflows/build-windows-package.yml) |
| 引导版 | 实验 8.2 用 `scanf("%d", &n)` 读阶数，像 `2.5` 这样的输入会被读成整数前缀 `2`。 | 沿用 8.5 的完整整数解析思路，先验证整个输入，再校验范围。给这项改动补一条拒绝小数的用例。 [8.2 源码](https://github.com/Bohese1379A/ZZU_C_practice/blob/v1.0.3/ZZU_C_Experiment/C_Experiment_8/8_2.c) |
| 引导版 | 合并和发布已有追溯记录，少数 README 小改动曾直接提交到 `main`。 | 对跨文件或会影响下载的变更，继续用 PR 预览差异，并在发布说明里链接对应 PR。 [PR #7](https://github.com/Bohese1379A/ZZU_C_practice/pull/7) |
| Codex 独立对照版 | 输入解析集中在共用头文件，初学者在单题里看到 `lab_read_int` 时，需要跳转才能理解它怎样校验输入。 | 给调用点加一句用途说明，并在共用头文件解释「读取完整输入、验证转换、写回结果」三个步骤。 [共用输入头文件](https://github.com/Bohese1379A/ZZU_C_practice/blob/cf5dce733736405c9c17c25dfdbaf79c596ba6cb/ZZU_C_Experiment/common/lab_input.h) |
| Codex 独立对照版 | 对照版有详尽的改进记录，但逐题文件较多保留简短题目说明。 | 优先给二维数组、递归和指针题加文件开头的三段讲解，让读者在代码旁就能理解步骤。 [独立改进记录](https://github.com/Bohese1379A/ZZU_C_practice/blob/cf5dce733736405c9c17c25dfdbaf79c596ba6cb/docs/codex-review.md) |
| Codex 独立对照版 | README 的下载入口提供的是初版 Windows 包，运行对照版需要本地重编。 | 若要给同学发对照版，先为该分支单独生成带短提交号的 Windows ZIP，并在 README 说明它对应的提交。 [对照版 README](https://github.com/Bohese1379A/ZZU_C_practice/blob/cf5dce733736405c9c17c25dfdbaf79c596ba6cb/README.md) |

下一次练习可以选一个小的回归 PR。用 Issue 写清「8.2 应拒绝 `2.5`」等验收要求，修改后在 PR 的 **Checks** 看样例结果，合并后在 **Actions** 查看 Windows ZIP。这样能把对照版的自动验证带进主线，同时保留我已经练熟的发布流程。
