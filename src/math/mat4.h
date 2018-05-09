//
// Created by Kirill Korolev on 09/05/2018.
//

#ifndef GLFW_APP_MATRIX_H
#define GLFW_APP_MATRIX_H

#include <GL/glew.h>

namespace kengine{ namespace math{

    class Mat4{
    private:
        static const int SIZE = 4 * 4;
    public:
        Mat4();
        ~Mat4()=default;
        Mat4& operator*=(const Mat4& other);
        friend Mat4 operator*(Mat4& left, const Mat4& right);
    public:
        GLfloat items[SIZE];
    public:
        static Mat4 id();
    };
}}

#endif //GLFW_APP_MATRIX_H
