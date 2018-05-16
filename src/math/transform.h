//
// Created by Kirill Korolev on 09/05/2018.
//

#ifndef GLFW_APP_TRANSFORM_H
#define GLFW_APP_TRANSFORM_H

#include "vec3.h"
#include "mat4.h"

namespace kengine{ namespace math{

    Mat4 translate(const Vec3& shift);
    Mat4 rotate(GLfloat angle, const Vec3& axis);
    Mat4 scale(const Vec3& scalars);

    Mat4 ortho(GLfloat left, GLfloat top, GLfloat right, GLfloat bottom, GLfloat near, GLfloat far);
    Mat4 lookAt(const Vec3& eye, const Vec3& center, const Vec3& up);
    Mat4 perspective(GLfloat fovy, GLfloat aspectRatio, GLfloat near, GLfloat far);

}}

#endif //GLFW_APP_TRANSFORM_H
