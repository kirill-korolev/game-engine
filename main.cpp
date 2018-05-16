#include <iostream>
#include "src/core/kengine.h"
#include "src/math/math.h"

using namespace kengine::core;
using namespace kengine::graphics;
using namespace kengine::math;

int main() {
    Kengine engine(new Window("Window", 640, 480));
    engine.shader = new Shader("../src/shaders/vertex.vert", "../src/shaders/fragment.frag");
    engine.shader->enable();

    GLuint TextureID  = glGetUniformLocation(engine.shader->id(), "textureSampler");

    const GLfloat g_vertex_buffer_data[] = {
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
    };

    const GLfloat g_uv_buffer_data[] = {
            0.000059f, 0.000004f,
            0.000103f, 0.336048f,
            0.335973f, 0.335903f,
            1.000023f, 0.000013f,
            0.667979f, 0.335851f,
            0.999958f, 0.336064f,
            0.667979f, 0.335851f,
            0.336024f, 0.671877f,
            0.667969f, 0.671889f,
            1.000023f, 0.000013f,
            0.668104f, 0.000013f,
            0.667979f, 0.335851f,
            0.000059f, 0.000004f,
            0.335973f, 0.335903f,
            0.336098f, 0.000071f,
            0.667979f, 0.335851f,
            0.335973f, 0.335903f,
            0.336024f, 0.671877f,
            1.000004f, 0.671847f,
            0.999958f, 0.336064f,
            0.667979f, 0.335851f,
            0.668104f, 0.000013f,
            0.335973f, 0.335903f,
            0.667979f, 0.335851f,
            0.335973f, 0.335903f,
            0.668104f, 0.000013f,
            0.336098f, 0.000071f,
            0.000103f, 0.336048f,
            0.000004f, 0.671870f,
            0.336024f, 0.671877f,
            0.000103f, 0.336048f,
            0.336024f, 0.671877f,
            0.335973f, 0.335903f,
            0.667969f, 0.671889f,
            1.000004f, 0.671847f,
            0.667979f, 0.335851f
    };


    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);


    engine.updateFun = [&](float dt){
        auto camera = engine.camera;
        auto input = engine.input;

        double x, y;
        engine.input->getMousePosition(x, y);

        camera->horizontalAngle += camera->mouseSpeed * float(320 - x);
        camera->verticalAngle   += camera->mouseSpeed * float(240 - y);


        if(input->isKeyPressed(GLFW_KEY_UP)){
            camera->position += camera->direction() * dt * camera->speed;
        }

        if(input->isKeyPressed(GLFW_KEY_DOWN)){
            camera->position -= camera->direction() * dt * camera->speed;
        }

        if(input->isKeyPressed(GLFW_KEY_LEFT)){
            camera->position -= camera->right() * dt * camera->speed;
        }

        if(input->isKeyPressed(GLFW_KEY_RIGHT)){
            camera->position += camera->right() * dt * camera->speed;
        }
    };

    engine.renderFun = [&](){
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glUniform1i(TextureID, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
        );

        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                2,                                // size : U+V => 2
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
        );

        glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

    };

    engine.mainLoop();

    return 0;
}