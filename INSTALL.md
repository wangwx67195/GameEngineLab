# 本地Agent与多设备使用

> 本仓库已包含教学文档和Skill，无需下载旧交接压缩包覆盖文件。文档入口见[README](README.md)。

## 1. 使用已有仓库

本机实际位置是 `~/projects/GameEngineLab`。用户希望的新位置 `~/project/gameEngineLab` 可以用作其他设备的克隆目录；Linux区分大小写，不自动搬动现有代码。

进入你的实际仓库后先检查：

```bash
pwd
git status --short --branch
git remote -v
```

现有GitHub仓库为 `wangwx67195/GameEngineLab`；不同本地目录可以连接同一仓库，不需再创建同名远程仓库。本文件不代表已经执行任何同步。

新设备若尚无仓库，可以由用户使用GitHub页面提供的克隆地址克隆到选定目录，然后检查编译器及所需依赖。按课程需要配置，不一次安装全部远期工具。

## 2. 启动教学Agent

在仓库根目录启动本地Agent，并发送：

> 请读AGENTS.md、docs/LEARNING_PROGRESS.md和对应的LEARNING_PLAN.md，再读取game-engine-tutor Skill。遵循教学手册与进度维护协议，从当前未完成主题继续。讲原理、给代码目标和逐步提示、说明API参数，让我自己实现核心代码；语气轻松，技术严谨。

如果Agent未自动发现Skill，明确让它读取 `.agents/skills/game-engine-tutor/SKILL.md`。其他Agent也可直接读取这些Markdown文件，不依赖某个网页会话。

实时课次只保存在进度文档，不在启动口令里硬编码“当前Lesson09”等旧状态。

## 3. 多设备同步

离开设备时由用户操作：

1. 用git status和git diff检查改动。
2. 将本次代码、进度和改过的教学规则文档按具体路径暂存。
3. 用git diff --cached检查后提交，再git push。

另一台设备开始时，先检查工作区；无未处理本地改动时，由用户执行或明确授权Agent执行：

```bash
git pull --ff-only
```

有本地改动或分支分叉时先比较，不擅自覆盖、stash、reset或clean。同步后重新读取进度与实际课程文件，再继续。Agent自动维护文档不包含自动Git提交、push或pull的授权。

## 4. 哪些内容进入Git

提交：学生源码、shader、CMakeLists、少量测试/笔记、教学规则、学习进度及小型许可明确素材。

不提交：build、编译产物、缓存、第三方glslViewer目录、大型下载模型和生成数据。未来需要新的资源目录时再创建，不把规划树中的目录一次全部建好。

记录细则见[PROGRESS_MAINTENANCE.md](docs/PROGRESS_MAINTENANCE.md)，目录说明见[README](README.md)。
