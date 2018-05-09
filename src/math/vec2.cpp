//
// Created by Kirill Korolev on 08/05/2018.
//

#include "vec2.h"

namespace kengine{ namespace math{

    Vec2::Vec2(GLfloat x, GLfloat y): Vec({x, y}) {

    }

    Vec2::Vec2(Vec<2>&& other): Vec(other){

    }

    GLfloat Vec2::x() const{
        return data_[0];
    }

    GLfloat Vec2::y() const{
        return data_[1];
    }


}}