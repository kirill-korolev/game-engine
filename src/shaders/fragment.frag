#version 330 core

out vec3 color;

uniform sampler2D textureSampler;

in vec4 pos;
in vec2 UV;

void main(){
    color = texture(textureSampler, UV).rgb;
}