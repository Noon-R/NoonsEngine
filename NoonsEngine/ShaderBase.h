#pragma once

#include "AWindowBase.h"
#include "glShader.h"

class ShaderBase {
public:
	ShaderBase(AWindowBase* window,const char * vert, const char* flag);
	~ShaderBase();

	int UseShader();
	GLuint GetUniformLocation(const char * name);
	int SetUniformMatrix3(GLuint const *location, GLfloat const * data);
	int SetUniformMatrix4(GLuint const* location, GLfloat const* data);
	int SetUniform3f(GLuint const* location, GLfloat const *);
	int SetUniform4f(GLuint const* location, GLfloat const* data);

private:


	AWindowBase* m_window;

	const GLuint m_program;

};