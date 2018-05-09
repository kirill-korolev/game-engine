//
// Created by Kirill Korolev on 09/05/2018.
//

#ifndef GLFW_APP_VEC3_H
#define GLFW_APP_VEC3_H


#include "vec.h"

namespace kengine{ namespace math{

    class Vec3: public Vec<3>{
    public:
        using Vec::Vec;
        Vec3(GLfloat x, GLfloat y, GLfloat z);
        Vec3(Vec<3>&& other);
        ~Vec3()=default;

        GLfloat x() const;
        GLfloat y() const;
        GLfloat z() const;
    };

}}

#define SUFFIX 3
#include "vecop.h"

#endif //GLFW_APP_VEC3_H
