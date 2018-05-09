#include <iostream>
#include "src/core/kengine.h"
#include "src/graphics/window.h"
#include "src/math/math.h"
#include "src/graphics/shader.h"

using namespace kengine::core;
using namespace kengine::graphics;
using namespace kengine::math;

int main() {
    Kengine engine;
    engine.createWindow(new Window("Window", 640, 480));
    engine.shader = new Shader("../src/shaders/vertex.vert", "../src/shaders/fragment.frag");
    engine.shader->enable();

    GLfloat g_vertex_buffer_data[9] = {
            -1.0f, -1.0f, 0.0f,
            1.0f, -1.0f, 0.0f,
            0.0f,  1.0f, 0.0f,
    };

    GLuint vertexbuffer;

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);


    // Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
    glGenBuffers(1, &vertexbuffer);

    // Сделаем только что созданный буфер текущим
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    // Передадим информацию о вершинах в OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    engine.updateFun = [&](float dt){

    };

    engine.renderFun = [&vertexbuffer](){
        // Указываем, что первым буфером атрибутов будут вершины
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
                3,                  // Размер
                GL_FLOAT,           // Тип
                GL_FALSE,           // Указывает, что значения не нормализованы
                0,                  // Шаг
                (void*)0            // Смещение массива в буфере
        );

// Вывести треугольник!
        glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник
        glDisableVertexAttribArray(0);
    };

    Mat4 ort = ortho(0.0, 5.0, 6.0, 0.0, -1.0, 1.0);
    //Mat4 translation = translate(Vec3(4, 3, 0));
    Vec2 light{4.0, 1.5};
    Vec4 color{0.4, 0.2, 0.7, 1.0};

    glUniformMatrix4fv(glGetUniformLocation(engine.shader->id(), "projection"), 1, GL_FALSE, ort.items);
    //glUniformMatrix4fv(glGetUniformLocation(shader.id(), "model"), 1, GL_FALSE, translation.items);
    //glUniform2f(glGetUniformLocation(shader.id(), "light_pos"), light.x(), light.y());
    //glUniform4f(glGetUniformLocation(shader.id(), "col"), color.x(), color.y(), color.z(), color.w());

    engine.mainLoop();

    return 0;
}