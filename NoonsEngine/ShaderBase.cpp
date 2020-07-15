#include "ShaderBase.h"

ShaderBase::ShaderBase(AWindowBase* window, const char* vert, const char* frag)
	: m_window(window)
	, m_program(loadProgram(vert, frag))
{
}

ShaderBase::~ShaderBase()
{
}

int ShaderBase::UseShader()
{
	glUseProgram(m_program);
	return 0;
}



int ShaderBase::SetUniformMatrix3(const char* name, GLfloat const* data)
{
	const GLuint uniformLoc = glGetUniformLocation(m_program, name);
	glUniformMatrix3fv(uniformLoc, 1, GL_FALSE, data);
	return 0;
}

int ShaderBase::SetUniformMatrix4(const char* name, GLfloat const* data)
{
	const GLuint uniformLoc = glGetUniformLocation(m_program, name);
	glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, data);
	return 0;
}

int ShaderBase::SetUniform3f(const char* name, GLfloat const* data)
{
	const GLuint uniformLoc = glGetUniformLocation(m_program, name);
	glUniform3fv(uniformLoc, Lcount, data);
	return 0;
}

int ShaderBase::SetUniform4f(const char* name, GLfloat const* data)
{
	glUniform4fv(m_LposLoc + i, 1, (view * Lpos[i]).data());
	return 0;
}




