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
        Vec4(T x, T y, T z, T w);
        Vec4(Vec<4>&& other);
        ~Vec4()=default;

        T x() const;
        T y() const;
        T z() const;
        T w() const;
    };

}}

#define SUFFIX 4
#include "vecop.h"

#endif //GLFW_APP_VEC4_H
