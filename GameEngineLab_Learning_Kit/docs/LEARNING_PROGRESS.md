# GameEngineLab 学习进度与交接日志

> 最后整理：2026-10-10；此文件应随着课程持续更新。  
> **状态约定**：`通过` / `已讲解` / `练习中` / `待Review` / `需复习` / `未开始`。  
> 若实际仓库文件或用户最新说明与此表矛盾，以最新事实为准并更新。**严禁根据旧记忆冒充新进度**。

## 1. 当前状态

- **正在进行：Lesson 09 — C++ 函数、参数、返回值与作用域**。
- 该课程内容已讲解，但作业**尚未在对话中验收**。
- 用户最明确的长期目标：自己编写 shader → 高质量复杂 shader → 完整可维护的游戏引擎。
- 教学语言：中文；基础语法详细解释；少量片段，不给整份可复制答案。

| 课程 | 状态 | 依据与备注 |
|---|---|---|
| 01 GLSL Hello Shader | 通过 | 成功修复 undeclared variable，绘制纯色 |
| 02 坐标与渐变 | 通过 | 水平/垂直/灰度/双色渐变、`mix` |
| 03 圆形与圆环 | 通过 | 距离 `length`、`if/else`、外边框 |
| 04 宽高比 | 通过 | 不同归一化方案、椭圆修正 |
| 05 `smoothstep` | 通过 | 独立 `radius/ring_width/aa_width`，双平滑边界 |
| 06 动态 Shader | 通过 | 三个 `.frag`，sin/cos、周期、圆周运动 |
| 07 C++ 入门 | 已讲解；理论通过；编程文件未全部验收 | 3 个早期 `.cpp` 文件的提交未确认；IO 对比练习出现过 `<cstudio>` 拼写错误并已解释 |
| 08 C++ 控制流 | 通过 | 已提交 conditions/loops/movement，得到逐段代码 Review；可以适时补 while 变式 |
| **09 C++ 函数** | **已讲解，待实践** | 尚需三个 cpp 作业与四道思考题 |
| 10 及以后 | 未开始 | 详见 LEARNING_PLAN.md |

## 2. Lesson 09 待完成

- [ ] `lessons/09_functions/01_calculator.cpp`：`add(int,int)`、`square(double)`、`maximum(double,double)`。
- [ ] `lessons/09_functions/02_health_functions.cpp`：`printHealthStatus(int)`，选做 `isAlive(int)`。
- [ ] `lessons/09_functions/03_movement_functions.cpp`：`updatePosition(...)` 和 `updateVelocity(...)`，比较值传递与赋回结果。
- [ ] 回答 Lesson 09 思考题（函数名/类型；值传递；void；封装利弊）。
- [ ] 在本机 `g++ -std=c++17 -Wall -Wextra -pedantic` 编译并测试。
- [ ] Code Review；用户自行修复问题；通过后标记完成。

## 3. 上一次对话留下的关键提醒

- C++ 文件内的 `#include <cstdio>` 切勿误写 `<cstudio>`。
- `std::printf("%f", ...)` 需要匹配 double 类型的实参；`std::cout` 通过 C++ 输出流接口工作。
- 前一节运动模拟：将 `delta_time` 从 1.0 改为 0.5，**单次位移减半**，相同 12 次循环时**总模拟时间减半**。
- 用户已正确理解 `std::` 为 C++ 标准库命名空间，`::` 为作用域解析运算符；建议优先显式书写 `std::`。
- 课程 09 的重点是函数的输入/输出/作用域与值传递；不要在本课额外塞进完整指针/智能指针课程。

## 4. 更新日志模板（每节新增一条）

复制下方模板，在每节完成后填入具体信息；不要覆盖旧日志。

```md
### YYYY-MM-DD — Lesson NN：课程名称
- 状态：练习中 / 待Review / 通过 / 需复习
- 本节我独立完成：
- 已编译/运行的证据（命令、样例输入输出）：
- 我遇到的错误和真正原因：
- 我能解释的核心概念：
- 仍然不理解的问题：
- Git commit（可选，真实存在才填写）：
- 下一步：
```

## 5. 新 Agent 进入项目后的核验步骤

```bash
pwd
ls -la
git status
git remote -v
tree -L 3 lessons 2>/dev/null
```

这些命令只用于核实当前状态。不要根据文档断言 GitHub 远程一定已经配置，或新电脑已经安装 glslViewer。不得未经用户允许替其删除文件、修改源码或推送仓库。
