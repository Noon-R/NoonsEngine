#pragma once

#include "AWindowBase.h"
#include "glShader.h"

class ShaderBase {
public:
	ShaderBase(AWindowBase* window,const char * vert, const char* flag);
	~ShaderBase();

	int UseShader();
	int SetUniformMatrix3(const char* name, GLfloat const * data);
	int SetUniformMatrix4(const char* name, GLfloat const* data);
	int SetUniform3f(const char* name, GLfloat const * data);
	int SetUniform4f(const char* name, GLfloat const* data);

private:


	AWindowBase* m_window;

	const GLuint m_program;

};