//
// Created by Kirill Korolev on 08/05/2018.
//

#ifndef GLFW_APP_VEC2_H
#define GLFW_APP_VEC2_H

#include "vec.h"

namespace kengine{ namespace math{

    class Vec2: public Vec<2>{
    public:
        using Vec::Vec;
        Vec2(T x, T y);
        Vec2(Vec<2>&& other);
        ~Vec2()=default;

        T x() const;
        T y() const;
    };

}}

#define SUFFIX 2
#include "vecop.h"

#endif //GLFW_APP_VEC2_H
