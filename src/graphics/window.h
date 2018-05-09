//
// Created by Kirill Korolev on 08/05/2018.
//

#ifndef GLFW_APP_WINDOW_H
#define GLFW_APP_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../input/input.h"

namespace kengine{ namespace graphics {

    using namespace input;

    class Window{
    public:
        Window(const char* title, int width, int height);
        ~Window();
        bool isClosed();
    public:
        GLFWwindow* window;
    private:
        const char* title_;
        int width_;
        int height_;
    private:
        bool init();
        friend void resize(GLFWwindow* window, int width, int height);
    };

}}

#endif //GLFW_APP_WINDOW_H
