//
// Created by Kirill Korolev on 09/05/2018.
//


#ifdef SUFFIX
#define cmb(a, b) __cmb(a, b)
#define __cmb(a, b) a##b
#define VEC cmb(Vec, SUFFIX)

namespace kengine{ namespace math {

    inline VEC operator+(const VEC& lhs, const VEC& rhs){
        auto vec = const_cast<VEC&>(lhs);
        vec += rhs;
        return vec;
    }

    inline VEC operator-(const VEC& lhs, const VEC& rhs){
        auto vec = const_cast<VEC&>(lhs);
        vec -= rhs;
        return vec;
    }

    inline VEC operator*(const VEC& lhs, const VEC& rhs){
        auto vec = const_cast<VEC&>(lhs);
        vec *= rhs;
        return vec;
    }

    inline VEC operator/(const VEC& lhs, const VEC& rhs){
        auto vec = const_cast<VEC&>(lhs);
        vec /= rhs;
        return vec;
    }

    inline VEC operator*(const VEC& lhs, GLfloat scalar){
        auto vec = const_cast<VEC&>(lhs);
        vec *= scalar;
        return vec;
    }

}}

#endif

