//
// Created by Kirill Korolev on 09/05/2018.
//

#include "mat4.h"

namespace kengine{ namespace math{

    Mat4::Mat4() {
        for(int i = 0; i < SIZE; ++i) items[i] = 0.0;
    }

    Mat4& Mat4::operator*=(const Mat4& other){
        T tmp = 0.0;

        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                tmp = 0.0;
                for(int k = 0; k < 4; ++k){
                    tmp += items[4 * i + k] * other.items[4 * k + j];
                }
                items[4 * i + j] = tmp;
            }
        }
        return *this;
    }

    Mat4 Mat4::id(){
        Mat4 mat;
        mat.items[0] = 1.0;
        mat.items[5] = 1.0;
        mat.items[10] = 1.0;
        mat.items[15] = 1.0;
        return mat;
    }


    Mat4 Mat4::ortho(T left, T top, T right, T bottom, T near, T far){
        Mat4 mat;
        mat.items[0] = 2.0 / (right - left);
        mat.items[3] = -(right + left) / (right - left);
        mat.items[5] = 2.0 / (top - bottom);
        mat.items[7] = -(top + bottom) / (top - bottom);
        mat.items[10] = -2.0 / (far - near);
        mat.items[11] = -(far + near) / (far - near);
        mat.items[15] = 1.0;
        return mat;
    }

    Mat4 Mat4::translation(const Vec3& vector){
        Mat4 mat = Mat4::id();
        mat.items[3] = vector.x();
        mat.items[7] = vector.y();
        mat.items[11] = vector.z();
        return mat;
    }

    Mat4 operator*(Mat4& left, const Mat4& right){
        left *= right;
        return left;
    }
}}