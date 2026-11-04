#include <GL/glew.h> 
#include <GLFW/glfw3.h> 
#include <iostream>
using std::cout;

void onError(int code, const char* description) {
    std::cerr << "GLFW Error " << code << ": " << description << '\n';
}
// char* 指向对应字符串的第一个字符的地址

// void onFramebufferSize()
void onFramebufferSize(GLFWwindow*, int width, int height) {
    glViewport(0, 0, width, height);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    cout << viewport[2] << "x" << viewport[3] << '\n';
}

int main() {
    glfwSetErrorCallback(onError); // 注册glfw错误回调

#if GLFW_VERSION_MAJOR > 3 || (GLFW_VERSION_MAJOR ==3 && GLFW_VERSION_MINOR >=4)
    //强制 GLFW 使用 X11 后端
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
#endif

    int success = glfwInit(); // 初始化glfw
    if (success == GLFW_FALSE) {
        std::cerr << "Failed to initialize GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 设置opengl 3.3 core要求

    GLFWwindow* window = glfwCreateWindow(600, 600, "GameEngineLab", nullptr, nullptr); // 创建opengl窗口
    if (window == nullptr) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window); // 将窗口设置为当前上下文
    glfwSwapInterval(1); // 垂直同步

    glewExperimental = GL_TRUE;
    GLenum result = glewInit(); // 初始化glew
    if (result != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << glewGetErrorString(result) << '\n';
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    const GLubyte* version = glGetString(GL_VERSION);
    cout << version << '\n';

    int width = 0;
    int height = 0; // 初始化Framebuffer尺寸
    glfwGetFramebufferSize(window, &width, &height); // 检测目前的窗口尺寸，设置为framebuffer尺寸
    onFramebufferSize(window, width, height); // 设置viewport尺寸为framebuffer尺寸
    glfwSetFramebufferSizeCallback(window, onFramebufferSize); // 注册窗口缩放回调，当window的framebuffersize发生改变时，调用onFramebufferSize()

    glClearColor(0.50f, 0.18f, 0.25f, 1.0f); // 设置清屏颜色

    while (!glfwWindowShouldClose(window)) { // 主循环
        glfwPollEvents(); // 处理事件

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE); // 检测是否按下esc
        }

        glClear(GL_COLOR_BUFFER_BIT); // 清屏

        glfwSwapBuffers(window); // 交换framebuffer，显示画面
    }

    glfwDestroyWindow(window); // 销毁窗口
    glfwTerminate(); // 清理glfw

    return 0;
}

