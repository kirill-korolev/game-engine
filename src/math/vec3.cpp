//
// Created by Kirill Korolev on 09/05/2018.
//

#include "vec3.h"

namespace kengine{ namespace math{

    Vec3::Vec3(GLfloat x, GLfloat y, GLfloat z): Vec({x, y, z}) {

    }

    Vec3::Vec3(Vec<3>&& other): Vec(other){

    }

    GLfloat Vec3::x() const{
        return data_[0];
    }

    GLfloat Vec3::y() const{
        return data_[1];
    }

    GLfloat Vec3::z() const{
        return data_[2];
    }

    Vec3 Vec3::cross(const Vec3 &other) const{
        Vec3 vec;
        vec.data_[0] = this->data_[1] * other.data_[2] - this->data_[2] * other.data_[1];
        vec.data_[1] = this->data_[2] * other.data_[0] - this->data_[0] * other.data_[2];
        vec.data_[2] = this->data_[0] * other.data_[1] - this->data_[1] * other.data_[0];
        return vec;
    }


}}
