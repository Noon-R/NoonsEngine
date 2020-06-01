﻿#version 150 core
uniform mat4 projection;
uniform mat4 modelview;
uniform mat3 normalMatrix;
const int Lcount = 2;
uniform vec4 Lpos[Lcount];
uniform vec3 Lamb[Lcount];
uniform vec3 Ldiff[Lcount];
uniform vec3 Lspec[Lcount];
layout (std140) uniform Material{
	vec3 Kamb;
	vec3 Kdiff;
	vec3 Kspec;
	float Kshi;
};
in vec4 position;
in vec3 normal;
in vec4 color;
in vec2 uv;
out vec3 Idiff;
out vec4 P;
out vec3 N;
out vec2 UV;
void main(){

P = modelview * position;
N = normalize(normalMatrix * normal);
vec3 V = -normalize(P.xyz);
//vec3 R = reflect(-L, N);

Idiff = vec3(0.0);
for (int i = 0; i < Lcount; ++i){
	vec3 L = normalize((Lpos[i] *P.w - P * Lpos[i].w).xyz);
	vec3 Iamb = Kamb * Lamb[i];
	Idiff += max(dot(N, L),0.0) * Kdiff * Ldiff[i] + Iamb;
}

gl_Position = projection * P;
UV = uv;
}