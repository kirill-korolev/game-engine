#version 330 core

layout (location = 0) out vec4 color;

uniform vec2 light_pos;
uniform vec4 col;

in vec4 pos;

void main(){
    float intensity = 1.0 / length(pos.xy - light_pos);
    color = col * intensity;
}