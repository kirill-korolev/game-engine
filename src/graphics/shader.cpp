//
// Created by Kirill Korolev on 09/05/2018.
//

#include "shader.h"
#include <iostream>
#include <vector>

namespace kengine{ namespace graphics{

    Shader::Shader(const char *vertexPath, const char *fragmentPath) {
        vertexPath_ = vertexPath;
        fragmentPath_ = fragmentPath;
        id_ = load();
    }

    Shader::~Shader(){
        glDeleteProgram(id_);
    }

    void Shader::enable() {
        if(!id_){
            std::cerr << "Cannot load shader" << std::endl;
        } else{
            glUseProgram(id_);
        }
    }

    void Shader::disable() {
        glUseProgram(NIL_PROGRAM);
    }

    GLuint Shader::id() const{
        return id_;
    }

    GLuint Shader::load() {
        GLuint program = glCreateProgram();
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertexStr = utils::readFile(vertexPath_);
        std::string fragmentStr = utils::readFile(fragmentPath_);

        const char* vertexContent = vertexStr.c_str();
        const char* fragmentContent = fragmentStr.c_str();

        GLint isCompiled = 0;

        glShaderSource(vertex, 1, &vertexContent, nullptr);
        glCompileShader(vertex);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &isCompiled);

        if(isCompiled == GL_FALSE){
            GLint maxLength = 0;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(vertex, maxLength, &maxLength, &errorLog[0]);

            std::cerr << errorLog.data() << std::endl;

            glDeleteShader(vertex);
            return 0;
        }

        glShaderSource(fragment, 1, &fragmentContent, nullptr);
        glCompileShader(fragment);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &isCompiled);

        if(isCompiled == GL_FALSE){
            GLint maxLength = 0;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> errorLog(maxLength);
            glGetShaderInfoLog(vertex, maxLength, &maxLength, &errorLog[0]);

            std::cerr << errorLog.data() << std::endl;
            glDeleteShader(fragment);
            return 0;
        }

        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        GLint isLinked = 0;

        glLinkProgram(program);
        glGetProgramiv(program, GL_LINK_STATUS, &isLinked);

        if(isLinked == GL_FALSE){
            glDeleteProgram(program);
            glDeleteShader(vertex);
            glDeleteShader(fragment);
            return 0;
        }

        //glValidateProgram(program);

        glDetachShader(program, vertex);
        glDetachShader(program, fragment);


        return program;
    }

}}
