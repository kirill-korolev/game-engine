//
// Created by Kirill Korolev on 08/05/2018.
//

#include "input.h"

namespace kengine{ namespace input{

    Input::Input() {
        for(int i = 0; i < MAX_KEYS; ++i) keys_[i] = false;
        for(int i = 0; i < MAX_BUTTONS; ++i) buttons_[i] = false;
    }


    bool Input::isKeyPressed(int keyCode){
        if(keyCode >= MAX_KEYS) return false;
        return keys_[keyCode];
    }

    bool Input::isButtonPressed(int button){
        if(button >= MAX_BUTTONS) return false;
        return buttons_[button];
    }

    void Input::getMousePosition(double& x, double& y){
        x = x_;
        y = y_;
    }
}}