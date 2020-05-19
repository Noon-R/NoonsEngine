#pragma once
#include<vector>
#include<iostream>
#include <fstream>
#include <GL/glew.h>


bool readShaderSource(const char* name, std::vector<GLchar>& buffer);
GLboolean printShaderInfoLog(GLuint shader, const char* str);
GLboolean printProgramInfoLog(GLuint program);
GLuint createProgram(const char* vsrc, const char* fsrc);
GLuint loadProgram(const char* vert, const char* frag);