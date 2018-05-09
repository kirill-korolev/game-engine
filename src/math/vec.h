//
// Created by Kirill Korolev on 08/05/2018.
//

#ifndef GLFW_APP_VEC_H
#define GLFW_APP_VEC_H

#include <GL/glew.h>
#include <cstdlib>
#include <array>

namespace kengine{ namespace math {

    template<size_t N>
    class Vec {
    public:
        Vec()=default;
        Vec(const std::array<GLfloat, N>& data);
        virtual ~Vec() = default;

        Vec &operator+=(const Vec &other);
        Vec &operator-=(const Vec &other);
        Vec &operator*=(const Vec &other);
        Vec &operator/=(const Vec &other);


        friend bool operator==(Vec& lhs, const Vec& rhs);
        friend bool operator!=(Vec& lhs, const Vec& rhs);
        
    protected:
        std::array<GLfloat, N> data_;
    };
}}

namespace kengine{ namespace math {


    template<size_t N>
    Vec<N>::Vec(const std::array<GLfloat, N>& data){
        for(size_t i = 0; i != N; ++i){
            data_[i] = data[i];
        }
    }


    template<size_t N>
    Vec<N>& Vec<N>::operator+=(const Vec &other){
        for(size_t i = 0; i != N; ++i){
            data_[i] += other.data_[i];
        }
        return *this;
    }

    template<size_t N>
    Vec<N>& Vec<N>::operator-=(const Vec &other){
        for(size_t i = 0; i != N; ++i){
            data_[i] -= other.data_[i];
        }
        return *this;
    }

    template<size_t N>
    Vec<N>& Vec<N>::operator*=(const Vec &other){
        for(size_t i = 0; i != N; ++i){
            data_[i] *= other.data_[i];
        }
        return *this;
    }

    template<size_t N>
    Vec<N>& Vec<N>::operator/=(const Vec &other){
        for(size_t i = 0; i != N; ++i){
            data_[i] /= other.data_[i];
        }
        return *this;
    }


    template<size_t N>
    inline bool operator==(Vec<N>& lhs, const Vec<N>& rhs){
        for(size_t i = 0; i != N; ++i){
            if(lhs.data_[i] != rhs.data_[i]) return false;
        }
        return true;
    }

    template<size_t N>
    inline bool operator!=(Vec<N>& lhs, const Vec<N>& rhs){
        return !(lhs == rhs);
    }    
        
}}

#endif //GLFW_APP_VEC_H
