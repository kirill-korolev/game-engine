//
// Created by Kirill Korolev on 10/05/2018.
//

#include "kengine.h"

namespace kengine{ namespace core{

    Kengine::Kengine(Window* window) {
        if(!window) return;

        this->window = window;
        input = new Input;
        camera = new Camera;
        currentTime_ = lastTime_ = glfwGetTime();

        glfwSetWindowUserPointer(window->window, input);

        modelMatrix = Mat4::id();

        glClearColor(0.1f, 0.1f, 0.3f, 0.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glEnable(GL_CULL_FACE);
    }

    Kengine::~Kengine() {
        if(window) delete window;
        if(input) delete input;
        if(camera) delete camera;
    }


    void Kengine::mainLoop() {
        while(!window->isClosed()){
            clear();
            update();
            render();
        }

    }

    void Kengine::update() {
        currentTime_ = glfwGetTime();
        GLfloat dt = GLfloat(currentTime_ - lastTime_);

        if(updateFun) updateFun(dt);

        projectionMatrix = perspective(radians(camera->fov), 4.0f / 3.0f, 0.1f, 100.0f);
        viewMatrix = lookAt(camera->position, camera->position + camera->direction(), camera->up());
        Mat4 mvp = projectionMatrix * viewMatrix * modelMatrix;
        glUniformMatrix4fv(shader->id(), 1, GL_FALSE, mvp.items);

        lastTime_ = currentTime_;
    }

    void Kengine::clear() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if(shader) shader->enable();
    }

    void Kengine::render() {
        if(renderFun) renderFun();
        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

}}