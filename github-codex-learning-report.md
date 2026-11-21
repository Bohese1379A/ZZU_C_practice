# GitHub 与 Codex 实操学习报告

这次我把自己的 C 语言实验仓库 `ZZU_C_practice` 当作练习项目。我的目标是学会在 GitHub 上独立管理一个小项目，同时摸索怎样向 Codex 交代任务、审查它的改动、验收它做出的东西。到发布 `v1.0.3` 时，我已经走过了从记录问题、提交修改到生成和发布下载包的完整流程。[项目仓库](https://github.com/Bohese1379A/ZZU_C_practice) · [v1.0.3 发布页](https://github.com/Bohese1379A/ZZU_C_practice/releases/tag/v1.0.3)

## 一、从改一个 README 开始

刚开始，我对页面上的几个按钮分不清楚。后来我在网页上修改 README，建了一个文档分支，打开 PR，再点进 **Files changed（文件变更）**看具体改了哪几行。这个小练习让我理解了三步之间的关系。**Commit（提交）**记录一次修改，**Branch（分支）**让我可以在一条独立的线上继续改，**Pull Request（拉取请求）**让我在合并前查看这些改动。[README 的第一个 PR](https://github.com/Bohese1379A/ZZU_C_practice/pull/1)

我也把几个工具的用途区分开了。Git 管分支、提交和历史，GitHub 提供 Issue、PR、Actions 和 Releases。GitHub Desktop 给本地 Git 操作提供图形界面。用命令行时，可以用 `git` 查历史和差异，也可以用 GitHub CLI 的 `gh` 查看 PR、工作流和发布。我的顺序是先在网页上认清每一步，再学对应的命令。

后来我整理了仓库简介、主题标签和下载入口。练习 Markdown 表格与相对链接时，我决定先跳过逐题索引。这个仓库已经按实验编号分好目录，首页优先说明如何阅读源码、如何下载程序和去哪里看实验资料，打开时更容易找到入口。[当前 README](https://github.com/Bohese1379A/ZZU_C_practice/blob/main/README.md)

## 二、用同一个仓库练习两次完整改动

第一次是修实验 8.5 的矩阵尺寸。我先把问题写进 Issue #2，并列出可以实际检查的条件。行列数都要在 1 到 10 之间，输入无效要退出，输入 2 行 3 列时仍要输出最大值和位置。Codex 帮我读懂输入检查和数组访问，再给出修改方案。我在修复分支上提交后，用 PR #3 确认改动范围，合并后回到 `main` 查看结果。对我来说，验收标准最有用的地方是，它能把「这个程序要改好」变成几个具体可检查的结果。[Issue #2](https://github.com/Bohese1379A/ZZU_C_practice/issues/2) · [PR #3](https://github.com/Bohese1379A/ZZU_C_practice/pull/3)

第二次是整理旧的 Windows 程序。我加过 `.gitignore`，之后才明白，Git 已经跟踪的 75 个 `.exe` 需要通过一次提交移除。我为这件事建了 Issue #4，加上 `enhancement` 标签，从 Issue 创建清理分支，在同一个 PR 里删除旧程序并更新 README 的下载链接。合并后，我按结果勾选验收项，再删除已合并的分支。这次也练会了用标签筛选待办，以及在 PR 说明里用 `Closes #4` 把合并和关闭 Issue 连起来。[Issue #4](https://github.com/Bohese1379A/ZZU_C_practice/issues/4) · [PR #5](https://github.com/Bohese1379A/ZZU_C_practice/pull/5)

## 三、从手动发 ZIP 到让 GitHub 打包

我在发布 `v1.0.1` 时练习了写发布说明、上传 ZIP 和选定 Tag。理解 Tag 时，我把一次提交看作项目的一个「截面」。`main` 会随着后续提交往前走，Tag 让我以后还能找到当初发布的那份源码。Release 提供这个版本的说明和下载入口。[v1.0.1 发布页](https://github.com/Bohese1379A/ZZU_C_practice/releases/tag/v1.0.1)

我原本考虑用 Actions 自动打包源码，后来想到 GitHub 网页已经可以下载源码 ZIP，仓库也已有 Windows 发布包。真正重复的工作，是改完 C 源码后再手动编译并组装 Windows 下载包。于是我让 Codex 通过 PR #6 加了一个工作流。C 源码更新进入 `main` 后，GitHub 会编译 Windows 程序并生成 ZIP，我可以在那次运行的 **Artifacts（运行产物）** 中找到它。[工作流 PR #6](https://github.com/Bohese1379A/ZZU_C_practice/pull/6)

下一次更新正好验证了这套流程。我把逐题补充知识点、解题思路和代码注释的工作交给 Codex，也明确要求通过 PR 进入 `main`。PR #7 合并后，GitHub Actions 自动生成了包含 75 份源码和 75 个 Windows 程序的 ZIP。Codex 核对了运行记录、打包提交和 ZIP 校验值，再把同一份文件发布到 `v1.0.3`。[PR #7](https://github.com/Bohese1379A/ZZU_C_practice/pull/7) · [实际运行记录](https://github.com/Bohese1379A/ZZU_C_practice/actions/runs/44903889178)

## 四、我怎么练习使用 Codex

当我要学习操作时，我会请 Codex 从我当前的页面开始，写清楚点哪个菜单、填哪个字段、保存后应该看到什么。对分支名、Tag、工作流和 YAML 这些新概念，我会先问它们在这一次操作里起什么作用，再决定要不要继续。问清楚以后，我自己就能判断「要不要做一个新的源码 ZIP」「这一条待办应该怎么验收」。

当我把批量修改和发布交给 Codex 时，我会说明走哪个流程、允许改什么、最后怎样验收。例如这次我要求「走 PR 进行修改」，完成后可以直接看 PR 的文件差异、Actions 的运行记录和 Release 的附件。我也发现，粘贴双语说明后先看一眼预览很实用。我有一次把说明标题的一部分也贴进了 Issue 正文，GitHub 仍然可以保存，实际打开正文才看得出多了字。

下次我想自己从 **Actions** 页面手动运行一次，把触发条件、日志和下载产物从头走通。命令行也可以从熟悉的操作学起，先把网页上的分支、提交和差异对应到 `git switch`、`git log` 和 `git diff`。这样下一次换一个项目，我也能自己走完同样的流程，并知道哪一步值得请 Codex 帮忙。
