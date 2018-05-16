//
// Created by Kirill Korolev on 10/05/2018.
//

#ifndef GLFW_APP_KENGINE_H
#define GLFW_APP_KENGINE_H

#include <functional>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "camera.h"
#include "../graphics/window.h"
#include "../graphics/shader.h"
#include "../math/math.h"

using namespace kengine::graphics;

namespace kengine{ namespace core{

    using namespace math;

    class Kengine{
    public:
        explicit Kengine(Window* window);
        ~Kengine();

        void mainLoop();
    public:
        Shader* shader;
        Window* window;
        Input* input;
        Camera* camera;

        Mat4 projectionMatrix;
        Mat4 viewMatrix;
        Mat4 modelMatrix;

        std::function<void(float)> updateFun;
        std::function<void()> renderFun;
    private:
        double currentTime_;
        double lastTime_;
    private:
        void update();
        void clear();
        void render();
    };
}}

#endif //GLFW_APP_KENGINE_H
