#include "ShaderBase.h"

ShaderBase::ShaderBase(WindowBase* window)

: m_window(window)
, m_program(loadProgram("pointWithNormal.vert", "pointWithNormal.frag"))
, m_modelviewLoc(glGetUniformLocation(m_program, "modelview"))
, m_projectionLoc(glGetUniformLocation(m_program, "projection"))
, m_normalMatrixLoc(glGetUniformLocation(m_program, "normalMatrix"))
, m_LposLoc(glGetUniformLocation(m_program, "Lpos"))
, m_LambLoc(glGetUniformLocation(m_program, "Lamb"))
, m_LdiffLoc(glGetUniformLocation(m_program, "Ldiff"))
, m_LspecLoc(glGetUniformLocation(m_program, "Lspec"))
, m_materialLoc(glGetUniformBlockIndex(m_program, "Material"))
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
