//
// Created by Kirill Korolev on 10/05/2018.
//

#include "transform.h"

namespace kengine{ namespace math{

    Mat4 ortho(GLfloat left, GLfloat top, GLfloat right, GLfloat bottom, GLfloat near, GLfloat far){
        Mat4 mat;
        mat.items[0] = 2.0f / (right - left);
        mat.items[3] = -(right + left) / (right - left);
        mat.items[5] = 2.0f / (top - bottom);
        mat.items[7] = -(top + bottom) / (top - bottom);
        mat.items[10] = -2.0f / (far - near);
        mat.items[11] = -(far + near) / (far - near);
        mat.items[15] = 1.0;
        return mat;
    }

    Mat4 translate(const Vec3& shift){
        Mat4 mat = id();
        mat.items[3] = shift.x();
        mat.items[7] = shift.y();
        mat.items[11] = shift.z();
        return mat;
    }

    Mat4 rotate(GLfloat angle, const Vec3& axis){
        Mat4 mat;
        //TODO
        return mat;
    }

    Mat4 scale(const Vec3& scalars){
        Mat4 mat;
        mat.items[0] = scalars.x();
        mat.items[5] = scalars.y();
        mat.items[10] = scalars.z();
        mat.items[15] = 1.0f;
        return mat;
    }

}}