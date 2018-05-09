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
        clear();
        render();
        update();
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

        window_ = glfwCreateWindow(width_, height_, title_, nullptr, nullptr);

        if(!window_){
            std::cerr << "Cannot create window" << std::endl;
            glfwTerminate();
            return false;
        }

        input_.setWindow(window_);

        glfwMakeContextCurrent(window_);

        glewExperimental = GL_TRUE;

        glfwSetFramebufferSizeCallback(window_, &resize);
        glfwSetKeyCallback(window_, &keyCallback);
        glfwSetMouseButtonCallback(window_, &buttonCallback);
        glfwSetCursorPosCallback(window_, &mousePositionCallback);

        if(glewInit() != GLEW_OK){
            std::cerr << "Cannot initialize GLEW" << std::endl;
            return false;
        }

        GLuint VertexArrayID;
        glGenVertexArrays(1, &VertexArrayID);
        glBindVertexArray(VertexArrayID);


// Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
        glGenBuffers(1, &vertexbuffer);

// Сделаем только что созданный буфер текущим
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

// Передадим информацию о вершинах в OpenGL
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

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
        // Указываем, что первым буфером атрибутов будут вершины
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
                3,                  // Размер
                GL_FLOAT,           // Тип
                GL_FALSE,           // Указывает, что значения не нормализованы
                0,                  // Шаг
                (void*)0            // Смещение массива в буфере
        );

// Вывести треугольник!
        glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник
        glDisableVertexAttribArray(0);
    }

}}