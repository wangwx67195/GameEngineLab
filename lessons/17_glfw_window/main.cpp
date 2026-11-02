#include <GL/glew.h> 
#include <GLFW/glfw3.h> 
#include <iostream>

void onError(int code, const char* description) {
    std::cerr << "GLFW Error" << code << ": " << description << '\n';
}
// char* 指向对应字符串的第一个字符的地址

int main() {
    glfwSetErrorCallback(onError);

    int success = glfwInit();
    if (success == GLFW_FALSE) {
        std::cerr << "Failed to initialize GLFW\n";
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(600, 600, "GameEngineLab", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    GLenum result = glewInit();
    if (result != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << glewGetErrorString(result) << '\n';
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1;
    }

    glClearColor(0.50f, 0.18f, 0.25f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
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

