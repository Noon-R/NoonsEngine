#version 150 core
const int Lcount = 2;
uniform vec4 Lpos[Lcount];
uniform vec3 Lspec[Lcount];
uniform sampler2D tex;
layout (std140) uniform Material{
vec3 Kamb;
vec3 Kdiff;
vec3 Kspec;
float Kshi;
};
in vec3 Idiff;
in vec3 Ispec;
in vec4 P;
in vec3 N;
in vec2 UV;
out vec4 fragment;
void main(){
	
	fragment = texture(tex, UV);
}