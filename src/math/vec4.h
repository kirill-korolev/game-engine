//
// Created by Kirill Korolev on 09/05/2018.
//

#ifndef GLFW_APP_VEC4_H
#define GLFW_APP_VEC4_H

#include "vec.h"

namespace kengine{ namespace math{

    class Vec4: public Vec<4>{
    public:
        using Vec::Vec;
        Vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
        Vec4(Vec<4>&& other);
        ~Vec4()=default;

        GLfloat x() const;
        GLfloat y() const;
        GLfloat z() const;
        GLfloat w() const;
    };

}}

#undef SUFFIX
#define SUFFIX 4
#include "vecop.h"

#endif //GLFW_APP_VEC4_H
