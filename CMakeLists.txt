cmake_minimum_required(VERSION 3.9)
project(glfw_app)

FUNCTION(PREPEND var prefix)
    SET(listVar "")
    FOREACH(f ${ARGN})
        LIST(APPEND listVar "${prefix}/${f}")
    ENDFOREACH(f)
    SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SRC_PATH src)

set(CORE kengine.cpp)
set(GRAPHICS window.cpp shader.cpp)
set(INPUT input.cpp)
set(MATH vec2.cpp vec3.cpp vec4.cpp mat4.cpp transform.cpp)

PREPEND(CORE_SRC ${SRC_PATH}/core ${CORE})
PREPEND(GRAPHICS_SRC ${SRC_PATH}/graphics ${GRAPHICS})
PREPEND(INPUT_SRC ${SRC_PATH}/input ${INPUT})
PREPEND(MATH_SRC ${SRC_PATH}/math ${MATH})

set(SOURCE_FILES main.cpp ${CORE_SRC} ${GRAPHICS_SRC} ${INPUT_SRC} ${MATH_SRC})

find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/GLFW/include ${PROJECT_SOURCE_DIR}/GLEW/include)
link_directories(${PROJECT_SOURCE_DIR}/GLFW/lib ${PROJECT_SOURCE_DIR}/GLEW/lib)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} libglfw.3.3.dylib libGLEW.2.1.0.dylib ${OPENGL_LIBRARIES})