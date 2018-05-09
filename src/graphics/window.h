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
        void tick();
    private:
        const char* title_;
        int width_;
        int height_;
        GLFWwindow* window_;
        Input input_;
    private:
        GLfloat g_vertex_buffer_data[9] = {
                -1.0f, -1.0f, 0.0f,
                1.0f, -1.0f, 0.0f,
                0.0f,  1.0f, 0.0f,
        };
        GLuint vertexbuffer;
        bool init();
        void update();
        void clear();
        void render();

        friend void resize(GLFWwindow* window, int width, int height);
    };

}}

#endif //GLFW_APP_WINDOW_H
