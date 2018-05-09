//
// Created by Kirill Korolev on 09/05/2018.
//

#ifndef GLFW_APP_UTILS_H
#define GLFW_APP_UTILS_H

#include <fstream>
#include <string>

namespace kengine{ namespace utils{

    inline std::string readFile(const std::string& filePath){
        std::ifstream str(filePath);
        std::string result{std::istreambuf_iterator<char>(str.rdbuf()), std::istreambuf_iterator<char>()};
        return result;
    }

}}

#endif //GLFW_APP_UTILS_H
