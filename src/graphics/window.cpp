//
// Created by Kirill Korolev on 08/05/2018.
//

#include "window.h"
#include <iostream>

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
        return glfwWindowShouldClose(window_) == 1;
    }

    void Window::tick() {
        update();
        clear();
        render();
    }

    bool Window::init() {

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        if(!glfwInit()){
            std::cerr << "Cannot initialize GLFW" << std::endl;
            glfwTerminate();
            return false;
        }

        window_ = glfwCreateWindow(width_, height_, title_, nullptr, nullptr);

        if(!window_){
            std::cerr << "Cannot create window" << std::endl;
            glfwTerminate();
            return false;
        }

        input_.setWindow(window_);

        glfwMakeContextCurrent(window_);
        glfwSwapInterval(1);
        glfwSetFramebufferSizeCallback(window_, &resize);
        glfwSetKeyCallback(window_, &keyCallback);
        glfwSetMouseButtonCallback(window_, &buttonCallback);
        glfwSetCursorPosCallback(window_, &mousePositionCallback);

        if(glewInit() != GLEW_OK){
            std::cerr << "Cannot initialize GLEW" << std::endl;
            return false;
        }

        return true;
    }

    void Window::update() {
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }

    void Window::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::render() {
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

}}