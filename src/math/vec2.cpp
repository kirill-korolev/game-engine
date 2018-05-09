//
// Created by Kirill Korolev on 08/05/2018.
//

#include "vec2.h"

namespace kengine{ namespace math{

    Vec2::Vec2(T x, T y): Vec({x, y}) {

    }

    Vec2::Vec2(Vec<2>&& other): Vec(other){

    }

    T Vec2::x() const{
        return data_[0];
    }

    T Vec2::y() const{
        return data_[1];
    }


}}