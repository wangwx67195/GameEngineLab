#include <iostream>
#include <GL/glew.h> // 必须先包含glew.g，再包含glfw3.h;原因是 GLFW 头文件可能会间接包含 OpenGL 头文件，而 GLEW 要求在其他 OpenGL 头文件之前包含
#include <GLFW/glfw3.h>

void onError(int code, const char* description) {
    std::cerr << "GLFW Error " << code << ": "<< description << '\n';
    return;
}

void onFramebufferSize(GLFWwindow*, int width, int height) {
    glViewport(0, 0, width, height);
    return;
}

int main() {
    glfwSetErrorCallback(onError);
#if GLFW_VERSION_MAJOR > 3 || (GLFW_VERSION_MAJOR ==3 && GLFW_VERSION_MINOR >=4)
    //强制 GLFW 使用 X11 后端
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
#endif
    if (!glfwInit()) {
        std::cerr << "Failed to initializer GLFW " << '\n';
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
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << '\n';
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    int width = 0;
    int height = 0;
    glfwGetFramebufferSize(window, & width, & height);
    onFramebufferSize(window, width, height);
    glfwSetFramebufferSizeCallback(window, onFramebufferSize); // 注册回调函数，需要指定window

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

    float vertices[] = {
        -0.1f, 0.1f, 0.0f,
        0.6f, 0.8f, 0.0f,
        0.4f, -0.7f, 0.0f,
        0.6f, 0.2f, 0.0f,
        -0.4f, 0.5f, 0.0f
    };
    GLuint vbo, vao;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // 必须在glVertexAttribPointer之前进行绑定
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        3 * sizeof(float),
        (void*)0
    ); // glVertexAttribPointer只是在配置，不会立刻读取顶点数据，只要vbo已经绑定，那么即使没有glBufferData，这里也不会报错(当然后续glDrawArrays()会读取顶点数据，这时候就会报错了= =)
    glEnableVertexAttribArray(0);

    const char* vertexSource = R"GLSL(
    #version 330 core
    layout(location = 0) in vec3 position;
    void main() {
        gl_Position = vec4(position, 1.0);
    }
    )GLSL"; // position类似于循环的调用方式；location=0指的是顶点属性0
    const char* fragmentSource = R"GLSL(
    #version 330 core
    layout(location = 0) out vec4 fragmentColor;
    void main() {
        fragmentColor = vec4(0.6, 0.9, 0.3, 1.0);
    }
    )GLSL"; // location=0指的是颜色输出位置0，通常映射到当前帧缓冲区的第一个颜色附件或默认帧缓冲区的绘制缓冲区
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, nullptr); // 把源代码交给Shader，四个参数分别是 shader：Shader对象编号/count：源代码字符串数量/string：字符串指针数组/length：每个字符串的长度,nullptr使用字符串的\0结束符判断长度
    glCompileShader(vertexShader);
    GLint success_vertex = 0;
    glGetShaderiv(
        vertexShader,       // shader：查询哪个shader
        GL_COMPILE_STATUS,  // pname：查询编译状态
        &success_vertex     // params：把查询结果写入变量；这里通过指针修改success_vertex，编译成功，success_vertex = GL_TRUE
    ); // 检查编译结果：提供变量的地址，让函数把结果写进去
    if (success_vertex == GL_FALSE) {
        char infoLog[1024]; // 创建一个能够容纳1024字节的数组：OpenGL返回的错误日志是文本
        glGetShaderInfoLog(
            vertexShader,       // 查询哪个Shader
            sizeof(infoLog),    // 指定日志缓冲区的最大容量
            nullptr,            // 允许你获取实际写入的日志长度：因为不需要获取实际写入的字符数量，所以使用nullptr，表示不需要接收长度信息
            infoLog             // 接收日志的字符数组：为什么不是&infoLog？因为数组名infoLog传递给函数时，通常会转换为指向第一个元素的指针，即infoLog相对&infoLog[0]，OpenGL 通过这个指针将错误日志写进数组
        ); // 获取编译信息
        std::cerr << "vertexShader Compile Failed " << infoLog << '\n';
    }
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    glCompileShader(fragmentShader);
    GLint success_fragment = 0;
    glGetShaderiv(
        fragmentShader,
        GL_COMPILE_STATUS,
        &success_fragment
    );
    if (success_fragment == GL_FALSE) {
        char infoLog[1024];
        glGetShaderInfoLog(
            fragmentShader,
            sizeof(infoLog),
            nullptr,
            infoLog
        );
        std::cerr << "fragmentShader Compile Failed " << infoLog << '\n';
    }

    GLuint program = glCreateProgram(); // Shader -> Shader Program对象，才可以工作
    glAttachShader(program, vertexShader); // 把Shader附加到Program
    glAttachShader(program, fragmentShader);
    glLinkProgram(program); // 将多个Shader阶段组合为可以使用的Program
    GLint success_program = 0;
    glGetProgramiv(
        program,
        GL_LINK_STATUS,
        &success_program
    );
    if (success_program == GL_FALSE) {
        char infoLog[1024];
        glGetProgramInfoLog(
            program,
            sizeof(infoLog),
            nullptr,
            infoLog
        );
        std::cerr << "Program Create Failed " << infoLog << '\n';
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBindVertexArray(vao);
        glDrawArrays(
            GL_TRIANGLE_FAN,    // mode：如何将顶点组织成图元；GL_TRAINGLE_FAN：3个共享顶点0的三角形
            0,                  // first：从第几个顶点开始读取
            5                   // count：读取多少个顶点
        );

        glfwSwapBuffers(window);
    }

    glDeleteProgram(program);
    glDeleteBuffers(1, &vbo); // 1:删除1个vbo，&vbo：提供vbo编号所在的地址
    glDeleteVertexArrays(1, &vao);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}