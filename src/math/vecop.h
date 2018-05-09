//
// Created by Kirill Korolev on 09/05/2018.
//


#ifdef SUFFIX
#define combine(a, b) __combine(a, b)
#define __combine(a, b) a##b
#define VEC combine(Vec, SUFFIX)

namespace kengine{ namespace math {
    inline VEC operator+(VEC& lhs, const VEC& rhs){
        lhs += rhs;
        return lhs;
    }

    inline VEC operator-(VEC& lhs, const VEC& rhs){
        lhs -= rhs;
        return lhs;
    }

    inline VEC operator*(VEC& lhs, const VEC& rhs){
        lhs *= rhs;
        return lhs;
    }

    inline VEC operator/(VEC& lhs, const VEC& rhs){
        lhs /= rhs;
        return lhs;
    }
}}

#endif

