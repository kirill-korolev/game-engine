//
// Created by Kirill Korolev on 09/05/2018.
//

#ifndef GLFW_APP_SHADER_H
#define GLFW_APP_SHADER_H

#include <GL/glew.h>
#include "../utils/utils.h"

namespace kengine{ namespace graphics{

    class Shader{
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();
        void enable();
        void disable();
        GLuint id() const;
    private:
        GLuint load();
    private:
        static const int NIL_PROGRAM = 0;
    private:
        GLuint id_;
        const char* vertexPath_;
        const char* fragmentPath_;
    };

}}

#endif //GLFW_APP_SHADER_H
