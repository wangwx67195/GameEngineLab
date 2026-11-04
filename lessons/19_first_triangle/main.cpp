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

    glClearColor(0.10f, 0.25f, 0.66f, 1.0f);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}