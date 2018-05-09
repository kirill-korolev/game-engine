//
// Created by Kirill Korolev on 08/05/2018.
//

#ifndef GLFW_APP_INPUT_H
#define GLFW_APP_INPUT_H

#include <GLFW/glfw3.h>
#include <iostream>

namespace kengine{ namespace input{

    class Input{
    public:
        Input();
        ~Input()=default;
        void setWindow(GLFWwindow* window);
        bool isKeyPressed(int keyCode);
        bool isButtonPressed(int button);
        void getMousePosition(double& x, double& y);
    private:
        static const int MAX_KEYS = 1000;
        static const int MAX_BUTTONS = 32;
    private:
        bool keys_[MAX_KEYS];
        bool buttons_[MAX_BUTTONS];
        double x_;
        double y_;
    private:
        friend void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        friend void buttonCallback(GLFWwindow* window, int button, int action, int mods);
        friend void mousePositionCallback(GLFWwindow* window, double x, double y);
    };


    inline void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
        auto* input = (Input*)glfwGetWindowUserPointer(window);
        input->keys_[key] = action != GLFW_RELEASE;
    }

    inline void buttonCallback(GLFWwindow* window, int button, int action, int mods){
        auto* input = (Input*)glfwGetWindowUserPointer(window);
        input->buttons_[button] = action != GLFW_RELEASE;
    }

    inline void mousePositionCallback(GLFWwindow* window, double x, double y){
        auto* input = (Input*)glfwGetWindowUserPointer(window);
        input->x_ = x;
        input->y_ = y;
    }
}}

#endif //GLFW_APP_INPUT_H
