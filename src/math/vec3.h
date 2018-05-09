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
        Vec3(T x, T y, T z);
        Vec3(Vec<3>&& other);
        ~Vec3()=default;

        T x() const;
        T y() const;
        T z() const;
    };

}}

#define SUFFIX 3
#include "vecop.h"

#endif //GLFW_APP_VEC3_H
