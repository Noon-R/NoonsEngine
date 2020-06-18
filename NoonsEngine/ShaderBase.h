#pragma once

#include "WindowBase.h"
#include "glShader.h"

class ShaderBase {
public:
	ShaderBase(WindowBase* window,const char * vert, const char* flag);
	~ShaderBase();

	int UseShader();
	GLuint GetUniformLocation(const char * name);
	int SetUniformMatrix3();
	int SetUniformMatrix4();
	int SetUniform3f();
	int SetUniform4f();

private:


	WindowBase* m_window;

	const GLuint m_program;

};