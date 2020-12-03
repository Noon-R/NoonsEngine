#pragma once

#include "AViewBase.h"

#include "Texture.h"
#include "Vector.h"
#include "Uniform.h"
#include "Material.h"
#include "Shape.h"

class TestView
	:public Noon::NoonEngineCore::AViewBase
{
public:

	TestView(AWindowBase* const window);

	virtual int Init(AWindowBase* const window) override;
	virtual int Update(AWindowBase* const window) override;
	virtual int Draw(AWindowBase* const window) override;
	virtual int PreDraw(AWindowBase* const window) override;
	virtual int PostDraw(AWindowBase* const window) override;

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

	Noon::GraphicsCore::Texture*  m_tex;

	static constexpr int Lcount = 2;
	static constexpr Vector Lpos[2] = { {0.0f, 0.0f, 5.0f, 1.0f},{ 8.0f, 0.0f, 0.0f, 1.0f } };
	static constexpr GLfloat Lamb[] = { 0.2f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f };
	static constexpr GLfloat Ldiff[] = { 0.2f, 0.1f, 0.1f, 0.9f, 0.9f, 0.9f };
	static constexpr GLfloat Lspec[] = { 1.0f, 0.5f, 0.5f, 0.9f, 0.9f, 0.9f };

	Uniform<Material>* material;
	std::unique_ptr<Shape> shape;


};