#pragma once

#include "WindowBase.h"
#include "glShader.h"

class ShaderBase {
public:
	ShaderBase(WindowBase* window,const char * vert, const char* flag);
	~ShaderBase();

	int UseShader();
	GLuint GetUniformLocation(const char * name);
	int SetUniformMatrix3(GLuint const *location, GLfloat const * data);
	int SetUniformMatrix4(GLuint const* location, GLfloat const* data);
	int SetUniform3f(GLuint const* location, GLfloat const *);
	int SetUniform4f(GLuint const* location, GLfloat const* data);

private:


	WindowBase* m_window;

	const GLuint m_program;

};