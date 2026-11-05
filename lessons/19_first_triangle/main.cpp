#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void onError(int code, const char* description) {
    std::cerr << "Failed to initialize glfw " << "GLFW Error " << code << description << '\n';
}

void onFramebufferSize(GLFWwindow*, int width, int height) {
    glViewport(0, 0, width, height);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    std::cout << "viewport size = " << viewport[2] << "x" << viewport[3] << '\n';
}

int main() {
    glfwSetErrorCallback(onError);

#if GLFW_VERSION_MAJOR > 3 || (GLFW_VERSION_MAJOR ==3 && GLFW_VERSION_MINOR >=4)
    //强制 GLFW 使用 X11 后端
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
#endif

    if (!glfwInit()) {
        std::cerr << "Failed to initialize glfw" << '\n';
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600, 600, "GameEngineLab", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create window" << '\n';
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;

    GLenum err = glewInit();

    if (err !=  GLEW_OK) {
        std::cerr << "Failed to initialize glew" << '\n';
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    int width = 0;
    int height = 0;
    glfwGetFramebufferSize(window, &width, &height);
    onFramebufferSize(window, width, height);
    glfwSetFramebufferSizeCallback(window, onFramebufferSize);

    glClearColor(0.9f, 0.25f, 0.66f, 1.0f); // 清屏颜色

    // 现在颜色只有缓冲颜色
    // 因此要在这里绘制三角形

    // 首先确定顶点
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    }; // 定义顶点，包含9个浮点数，每3个浮点数组成一个顶点，对应xyz
    // vertices是C++数组，目前在CPU侧

    // 使用VBO存放顶点数据，供后续GPU使用  将顶点数据存放在 OpenGL 管理的缓冲对象中，供后续 GPU 绘制使用
    GLuint vbo; // 保存 OpenGL 分配的对象编号
    glGenBuffers(1, &vbo); // 生成 1 个缓冲对象名称，并将其写入 vbo
    std::cout << "vbo = " << vbo << '\n';

    // opengl中的很多操作，都是“先绑定，再操作”
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // 将编号为 vbo 的缓冲区对象绑定到 OpenGL 的 GL_ARRAY_BUFFER 绑定目标上，使后续针对这个目标的操作作用于该缓冲区

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices), // 整个数组占据多少字节：3顶点x3floatx4字节 = 36字节
        vertices, // 传递的是数组首元素的地址
        GL_STATIC_DRAW // OpenGL 的使用提示，表示数据预计不会频繁修改，并主要用于绘制
    );
    // 此时顶点已经上传，但是GPU不知道“每三个 float 是一个顶点，而不是每两个或每四个” -> VAO

    // 可以认为：VBO -> 存放原始数据  VAO -> 保存读取数据的配置
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao); // 先绑定，再操作
    glVertexAttribPointer(
        0,                      // 属性编号：使用位置属性0
        // 什么是顶点属性：位置，颜色，法线等等；顶点属性编号：用于区分不同属性，例如0是位置...
        3,                      // 分量数量：一个顶点位置包含xyz
        GL_FLOAT,               // 数据类型：float
        GL_FALSE,               // 是否归一化数据：不用
        3 * sizeof(float),      // stride：每12个字节读取下一个位置：相邻两个顶点的同一属性起始地址相差 3 个 float，即通常为 12 字节
        nullptr                 // offset：从缓冲数据开头读取：位置数据从 VBO 的第 0 个字节开始
    );
    glEnableVertexAttribArray(0); // 启用编号0的顶点属性
    // 顶点生成完毕

/*     // 接下来是shader部分：GPU应该怎样处理顶点？
    // Vertex shader：计算顶点位置
    #version 330 core // 指定glsl的版本，GLSL 3.3对应OpenGL3.3
    
    layout (location = 0) in vec3 position; 
    // layout：指定变量的布局信息
    // location = 0：指定顶点属性位置编号为0 -> 前文在glVertexAttribPointer()中定义过
    // in：表示这是着色其的输入变量
    // 声明一个名为 position 的三维浮点向量
    // 可以理解为“声明一个名为 position 的三维向量输入变量，它从顶点属性位置 0 接收数据”

    void main() { // 顶点着色器的 main()：会针对参与绘制的每个顶点执行；例如绘制一个包含三个顶点的三角形，顶点着色器就会产生三次顶点着色器调用，分别处理三个顶点
        gl_Position = vec4(position, 1.0); // gl_Position是 GLSL 顶点着色器提供的一个内置输出变量
    }

    // fragment shader：确定片段颜色
    #version 330 core

    layout(location = 0) out vec4 fragmentColor; // 声明一个名为 fragmentColor 的四维向量，用于输出片段颜色

    void main() {
        fragmentColor = vec4(1.0, 0.5, 0.2, 1.0);
    } */

    // 编译/链接shader
    const char* vertexSource = R"GLSL(
    #version 330 core // 指定glsl的版本，GLSL 3.3对应OpenGL3.3
            
    layout (location = 0) in vec3 position; 
    // layout：指定变量的布局信息
    // location = 0：指定顶点属性位置编号为0 -> 前文在glVertexAttribPointer()中定义过
    // in：表示这是着色其的输入变量
    // 声明一个名为 position 的三维浮点向量
    // 可以理解为“声明一个名为 position 的三维向量输入变量，它从顶点属性位置 0 接收数据”

    void main() { // 顶点着色器的 main()：会针对参与绘制的每个顶点执行；例如绘制一个包含三个顶点的三角形，顶点着色器就会产生三次顶点着色器调用，分别处理三个顶点
        gl_Position = vec4(position, 1.0); // gl_Position是 GLSL 顶点着色器提供的一个内置输出变量
    }
    )GLSL";
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* fragmentSource = R"GLSL(
    // fragment shader：确定片段颜色
    #version 330 core

    layout(location = 0) out vec4 fragmentColor; // 声明一个名为 fragmentColor 的四维向量，用于输出片段颜色

    void main() {
        fragmentColor = vec4(1.0, 0.5, 0.2, 1.0);
    }
    )GLSL";

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glCompileShader(vertexShader);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);

    GLint success_vertex = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success_vertex);
    if (success_vertex == GL_FALSE) {
        char infoLog[1024];

        glGetShaderInfoLog(
            vertexShader,
            sizeof(infoLog),
            nullptr,
            infoLog
        );

        std::cerr << "Vertex Shader Compile Failed: " << infoLog << '\n';
    }

    GLint success_fragment = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success_fragment);
    if (success_fragment == GL_FALSE) {
        char infoLog[1024];

        glGetShaderInfoLog(
            fragmentShader,
            sizeof(infoLog),
            nullptr,
            infoLog
        );

        std::cerr << "Fragment Shader Compile Failed: " << infoLog << '\n';
    }

    // 链接shader program
    GLuint program = glCreateProgram();

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);
    GLint success_program = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &success_program); // 检查链接结果
    if (success_program == GL_FALSE) {
        char infoLog[1024];

        glGetProgramInfoLog(
            program,
            sizeof(infoLog),
            nullptr,
            infoLog
        );

        std::cerr << "Fragment Shader Compile Failed: " << infoLog << '\n';
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); // 将不再需要的独立shader对象删除；已经成功链接的 Program 仍然能够使用这些 Shader 阶段
    // shader program创建完毕


    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents(); // 处理堆积的事件

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE); // SetWindowShouldClose
        }

        glClear(GL_COLOR_BUFFER_BIT); // 把颜色缓冲设定成指定颜色

        // opengl执行绘制
        glUseProgram(program); // 选择program
        glBindVertexArray(vao); // 选择本次绘制的顶点输入配置
        glDrawArrays(GL_TRIANGLES, 0, 3); // 发出真正的绘制命令
        // GL_TRIANGLES：每三个顶点组成一个独立三角形
        // 0：从第0个顶点开始
        // 3:读取3个顶点

        glfwSwapBuffers(window); // 呈现绘制画面
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteProgram(program);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}