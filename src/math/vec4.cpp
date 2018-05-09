//
// Created by Kirill Korolev on 09/05/2018.
//

#include "Vec4.h"

namespace kengine{ namespace math{

    Vec4::Vec4(T x, T y, T z, T w): Vec({x, y, z, w}) {

    }

    Vec4::Vec4(Vec<4>&& other): Vec(other){

    }

    T Vec4::x() const{
        return data_[0];
    }

    T Vec4::y() const{
        return data_[1];
    }

    T Vec4::z() const{
        return data_[2];
    }

    T Vec4::w() const{
        return data_[3];
    }

}}