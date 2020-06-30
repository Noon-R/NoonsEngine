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

GLuint ShaderBase::GetUniformLocation(const char* name)
{
	return glGetUniformLocation(m_program,name);
	
}


