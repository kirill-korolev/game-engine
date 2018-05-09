//
// Created by Kirill Korolev on 10/05/2018.
//

#include "kengine.h"

namespace kengine{ namespace core{

    Kengine::Kengine() {
        input_ = new Input;
        currentTime_ = lastTime_ = glfwGetTime();
    }

    Kengine::~Kengine() {
        if(window_) delete window_;
        if(input_) delete input_;
    }

    void Kengine::createWindow(Window* window){
        if(!window) return;
        window_ = window;
        auto* win = window_->window;
        glfwSetWindowUserPointer(win, input_);
    }

    void Kengine::mainLoop() {
        while(!window_->isClosed()){
            clear();
            render();
            update();
        }
    }

    void Kengine::update() {

        currentTime_ = glfwGetTime();
        float delta = float(currentTime_ - lastTime_);

        if(input_->isKeyPressed(GLFW_KEY_UP)){

        }

        if(input_->isKeyPressed(GLFW_KEY_DOWN)){

        }

        if(input_->isKeyPressed(GLFW_KEY_LEFT)){

        }

        if(input_->isKeyPressed(GLFW_KEY_RIGHT)){

        }

        if(updateFun) updateFun(delta);

        glfwSwapBuffers(window_->window);
        glfwPollEvents();

        lastTime_ = currentTime_;
    }

    void Kengine::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Kengine::render() {
        if(renderFun) renderFun();
    }

}}