//
// Created by Kirill Korolev on 10/05/2018.
//

#ifndef GLFW_APP_KENGINE_H
#define GLFW_APP_KENGINE_H

#include <functional>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../graphics/window.h"
#include "../graphics/shader.h"

using namespace kengine::graphics;

namespace kengine{ namespace core{

    class Kengine{
    public:
        Kengine();
        ~Kengine();

        void createWindow(Window* window);
        void mainLoop();

        Shader* shader;
        std::function<void(float)> updateFun;
        std::function<void()> renderFun;
    private:
        Window* window_;
        Input* input_;

        double currentTime_;
        double lastTime_;
    private:
        void update();
        void clear();
        void render();
    };
}}

#endif //GLFW_APP_KENGINE_H
