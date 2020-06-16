#pragma once

#include "WindowBase.h"
#include "glShader.h"

class ShaderBase {
public:
	ShaderBase(WindowBase* window);
	~ShaderBase();

	int UseShader();


private:
	WindowBase* m_window;

	const GLuint m_program;
	const GLuint m_modelviewLoc;
	const GLuint m_projectionLoc;
	const GLuint m_normalMatrixLoc;
	const GLuint m_LposLoc;
	const GLuint m_LambLoc;
	const GLuint m_LdiffLoc;
	const GLuint m_LspecLoc;

	const GLuint m_materialLoc;

};