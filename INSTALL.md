# 将学习交接包安装到 GameEngineLab

## 文件说明

```text
AGENTS.md                                  # Codex 进入仓库时读取的短规则
docs/LEARNING_PLAN.md                      # 完整长期路线与已学习历史
docs/LEARNING_PROGRESS.md                  # 当前学习状态、每节日志模板
.agents/skills/game-engine-tutor/SKILL.md  # 可复用的教学与 Code Review 工作流
```

## 一、安装

1. 先确认学习仓库在 `~/projects/GameEngineLab`，必要时用 `pwd` 和 `git status` 检查。不要解压到 `~/projects` 的上一级或其他课程目录。
2. 在浏览器下载 `GameEngineLab_Learning_Kit.zip`，假设下载到 `~/Downloads/`。
3. **先检查压缩包内容**：

```bash
unzip -l ~/Downloads/GameEngineLab_Learning_Kit.zip
```

4. **非覆盖方式解压**到仓库根目录：

```bash
unzip -n ~/Downloads/GameEngineLab_Learning_Kit.zip -d ~/projects/GameEngineLab
```

`-n` 表示不覆盖已存在的同名文件。若原本有 `AGENTS.md` / progress，请先自行合并，避免丢失既有规则。

5. 验证：

```bash
cd ~/projects/GameEngineLab
ls -l AGENTS.md docs/LEARNING_PLAN.md docs/LEARNING_PROGRESS.md
ls -l .agents/skills/game-engine-tutor/SKILL.md
git status
```

6. 这些 Markdown 文件建议提交到你自己的 Git 仓库，以便多设备同步（执行 commit/push 前查看 diff，保护原本文件）。

## 二、在 Codex 中继续

进入 `~/projects/GameEngineLab` 后启动 Codex，在新会话中说：

> 阅读 `AGENTS.md`、`docs/LEARNING_PROGRESS.md` 和 `docs/LEARNING_PLAN.md`，并按照 `game-engine-tutor` Skill 的规则，从最近未完成课程继续教我。基础请详细解释，不要替我写完作业。当前课程是 Lesson 09。

如果新 Skill 没有被自动发现，可以**直接要求 Codex 读取** `.agents/skills/game-engine-tutor/SKILL.md`；不同版本可能需要重新启动会话后才能发现新增 Skill。

## 三、多设备学习

- 电脑 A 编辑/完成：`git status` → `git add <具体文件>` → `git diff --cached` → `git commit -m "..."` → `git push`。
- 电脑 B 开始前：在没有未处理本地改动的前提下 `git pull --ff-only`。
- 不要把本地第三方 `glslViewer/`、`build/`、编译二进制上传。建议 `.gitignore` 中至少有 `/glslViewer/`、`**/build/`。

## 四、关于“教学文件”和“源码”

本交接包仅含 Markdown 教学指令、规划和日志；它不含课程实际源码，也不会修改你的现有 `.frag` 或 `.cpp` 文件。课程源码仍在你自己的 GameEngineLab 仓库里。
