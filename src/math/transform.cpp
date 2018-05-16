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
        Mat4 mat = Mat4::id();
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

    Mat4 lookAt(const Vec3& eye, const Vec3& center, const Vec3& up){
        Mat4 mat;
        Vec3 x, y, z;

        z = eye - center;
        z.normalize();

        y = up;

        x = y.cross(z);
        y = z.cross(x);

        x.normalize();
        y.normalize();

        mat.items[0 + 0 * 4] = x.x();
        mat.items[0 + 1 * 4] = x.y();
        mat.items[0 + 2 * 4] = x.z();
        mat.items[0 + 3 * 4] = -x.dot(eye);

        mat.items[1 + 0 * 4] = y.x();
        mat.items[1 + 1 * 4] = y.y();
        mat.items[1 + 2 * 4] = y.z();
        mat.items[1 + 3 * 4] = -y.dot(eye);

        mat.items[2 + 0 * 4] = z.x();
        mat.items[2 + 1 * 4] = z.y();
        mat.items[2 + 2 * 4] = z.z();
        mat.items[2 + 3 * 4] = -z.dot(eye);

        mat.items[3 + 3 * 4] = 1.0;

        return mat;
    }

    Mat4 perspective(GLfloat fovy, GLfloat aspectRatio, GLfloat near, GLfloat far){
        Mat4 result;
        GLfloat half = tan(fovy / 2.0f);
        result.items[0] = 1.0 / aspectRatio / half;
        result.items[5] = 1.0  / half;
        result.items[10] = -(far + near) / (far - near);
        result.items[11] = 1.0f;
        result.items[14] = -2.0f * far * near / (far - near);
        return result;
    }

}}