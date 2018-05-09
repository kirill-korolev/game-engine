#include <iostream>
#include "src/graphics/window.h"
#include "src/math/math.h"
#include "src/graphics/shader.h"

using namespace kengine::graphics;
using namespace kengine::math;

int main() {
    Window window("Window", 640, 480);
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    GLfloat vertices[] = {
            0.0, 0.0, 0.0,
            8.0, 3.0, 0.0,
            3.0, 8.0, 0.0,

            3.0, 8.0, 0.0,
            0.0, 0.0, 0.0,
            0.0, 3.0, 0.0
    };

    Shader shader{"../src/shaders/vertex.vert", "../src/shaders/fragment.frag"};
    shader.enable();

    GLuint vbo;

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    Mat4 ortho = Mat4::ortho(0.0, 9.0, 16.0, 0.0, -1.0, 1.0);
    Mat4 translation = Mat4::translation(Vec3(4, 3, 0));
    Vec2 light{4.0, 1.5};
    Vec4 color{0.4, 0.2, 0.7, 1.0};

    glUniformMatrix4fv(glGetUniformLocation(shader.id(), "projection_matrix"), 1, GL_FALSE, ortho.items);
    glUniformMatrix4fv(glGetUniformLocation(shader.id(), "model_matrix"), 1, GL_FALSE, translation.items);
    glUniform2f(glGetUniformLocation(shader.id(), "light_pos"), light.x(), light.y());
    glUniform4f(glGetUniformLocation(shader.id(), "col"), color.x(), color.y(), color.z(), color.w());



    while(!window.isClosed()){
        window.tick();
    }

    return 0;
}