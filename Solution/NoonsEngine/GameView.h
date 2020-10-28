#pragma once

#include "ADefineView.h"

class GameView
	:public ADefineView {

public:
	GameView(WindowBase* const window);

	virtual int Init();
	virtual int Update();
	virtual int Draw();

private:

	const GLuint m_program;
	const GLuint m_modelviewLoc;
	const GLuint m_projectionLoc;
	const GLuint m_normalMatrixLoc;
	const GLuint m_LposLoc;
	const GLuint m_LambLoc;
	const GLuint m_LdiffLoc;
	const GLuint m_LspecLoc;

	const GLuint m_materialLoc;

	static constexpr int Lcount = 2;
	static constexpr Vector Lpos[2] = { {0.0f, 0.0f, 5.0f, 1.0f},{ 8.0f, 0.0f, 0.0f, 1.0f } };
	static constexpr GLfloat Lamb[] = { 0.2f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f };
	static constexpr GLfloat Ldiff[] = { 0.2f, 0.1f, 0.1f, 0.9f, 0.9f, 0.9f };
	static constexpr GLfloat Lspec[] = { 1.0f, 0.5f, 0.5f, 0.9f, 0.9f, 0.9f };

	Uniform<Material>* material;
	std::unique_ptr<Shape> shape;
	std::unique_ptr<Shape> shapeSphere;

	Texture* m_tex;
};