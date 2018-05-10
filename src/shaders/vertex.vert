#version 330 core

layout(location = 0) in vec3 position;

uniform mat4 projection;
uniform mat4 view = mat4(1.0f);
uniform mat4 model = mat4(1.0f);

out vec4 pos;

void main(){
    gl_Position = projection * view * model * vec4(position, 1);
    pos = gl_Position;
}