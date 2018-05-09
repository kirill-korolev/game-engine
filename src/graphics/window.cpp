//
// Created by Kirill Korolev on 08/05/2018.
//

#include "window.h"

namespace kengine{ namespace graphics{

    void resize(GLFWwindow *window, int width, int height) {
        glViewport(0, 0, width, height);
    }

    Window::Window(const char *title, int width, int height) {
        title_ = title;
        width_ = width;
        height_ = height;
        if(!init()) glfwTerminate();
    }

    Window::~Window() {
        glfwTerminate();
    }

    bool Window::isClosed() {
        return glfwWindowShouldClose(window) == 1;
    }

    bool Window::init() {

        if(!glfwInit()){
            std::cerr << "Cannot initialize GLFW" << std::endl;
            glfwTerminate();
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        window = glfwCreateWindow(width_, height_, title_, nullptr, nullptr);

        if(!window){
            std::cerr << "Cannot create window" << std::endl;
            glfwTerminate();
            return false;
        }

        glfwMakeContextCurrent(window);
        glewExperimental = GL_TRUE;

        glfwSetFramebufferSizeCallback(window, &resize);
        glfwSetKeyCallback(window, &keyCallback);
        glfwSetMouseButtonCallback(window, &buttonCallback);
        glfwSetCursorPosCallback(window, &mousePositionCallback);

        if(glewInit() != GLEW_OK){
            std::cerr << "Cannot initialize GLEW" << std::endl;
            return false;
        }

        return true;
    }


}}