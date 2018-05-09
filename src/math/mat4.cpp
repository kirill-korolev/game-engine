//
// Created by Kirill Korolev on 09/05/2018.
//

#include "mat4.h"

namespace kengine{ namespace math{

    Mat4::Mat4() {
        for(int i = 0; i < SIZE; ++i) items[i] = 0.0;
    }

    Mat4& Mat4::operator*=(const Mat4& other){
        GLfloat tmp = 0.0;

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

    Mat4 operator*(Mat4& left, const Mat4& right){
        left *= right;
        return left;
    }
}}