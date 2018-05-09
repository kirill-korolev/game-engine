//
// Created by Kirill Korolev on 09/05/2018.
//

#include "Vec4.h"

namespace kengine{ namespace math{

    Vec4::Vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w): Vec({x, y, z, w}) {

    }

    Vec4::Vec4(Vec<4>&& other): Vec(other){

    }

    GLfloat Vec4::x() const{
        return data_[0];
    }

    GLfloat Vec4::y() const{
        return data_[1];
    }

    GLfloat Vec4::z() const{
        return data_[2];
    }

    GLfloat Vec4::w() const{
        return data_[3];
    }

}}