# GameEngineLab

通过原理推导、亲手编程与代码 Review 学习图形学和游戏引擎算法 :D

使用 C++17、GLSL 与 OpenGL；以完整主题组织代码目标、数学原理、渐进提示、API 方法和可验证成果。Agent 指导与审查，学生实现核心代码。

## 从哪里开始

| 文档 | 用途 |
|---|---|
| [学习进度](docs/LEARNING_PROGRESS.md) | 当前学到哪里、待办和实际验收证据；每次继续前先读 |
| [学习路线](docs/LEARNING_PLAN.md) | 长期主题、算法实践主线、近期课程衔接 |
| [教学手册](docs/TEACHING_GUIDE.md) | 教师如何讲原理、给提示、解释API与Review |
| [进度维护](docs/PROGRESS_MAINTENANCE.md) | Agent如何更新状态、记录证据、处理跨设备交接 |
| [Agent入口](AGENTS.md) | 本仓库的教学约束与操作边界 |
| [本地与多设备使用](INSTALL.md) | 目录位置、Agent启动和Git同步说明 |

## 目录组织

```text
GameEngineLab/
├── AGENTS.md
├── README.md
├── INSTALL.md
├── .agents/skills/game-engine-tutor/SKILL.md
├── docs/                         # 规划、进度与教学/记录手册
├── lessons/
│   ├── 01_hello_shader/
│   ├── ...                       # 已有课程，保留原编号与代码
│   └── 14_multi_file/
│       ├── 01_02_multi_file/      # 学生整理的前两小节三文件
│       └── 03_member_split/      # 成员函数拆分练习
├── assets/                       # 后续需要时创建，仅放小型自制/许可明确素材
├── build/                        # 编译生成，不提交
└── glslViewer/                   # 若本地有此第三方目录，不提交
```

上图包含规划条目，不代表目录已经全部存在。早期单文件练习不搬动；新的主题可在本课目录内分实验子目录。每个独立程序使用自己的构建目标，避免将多个main链接到一起。

每个完整主题建议由学生写简短的README或notes，记录问题、原理、如何构建/运行、预期与实际结果、一个边界情况。少量结果截图可放在该课的results目录；大量生成数据和大型模型不提交。

## 继续学习与同步

本机现有仓库是 `/home/wwx/projects/GameEngineLab`；其他设备可克隆到 `~/project/gameEngineLab`。目录名称不决定远程仓库身份，先用pwd和git remote -v确认，不需要重复创建GitHub仓库。

新Agent先读AGENTS、进度和对应计划，再使用教学Skill。教学/Review后自动记录真实进度，不自动改练习代码或commit/push。

离开设备前，自己检查差异，提交本次代码与更新文档并push；另一台设备先检查工作区，干净时pull --ff-only，再重读进度。具体流程见进度维护手册。
