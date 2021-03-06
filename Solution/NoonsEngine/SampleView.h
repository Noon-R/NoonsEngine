#pragma once

#include "AViewBase.h"

#include "Vector.h"
#include "Uniform.h"
#include "Material.h"
#include "Shape.h"
#include "Texture.h"

class SampleView
	:public Noon::NoonEngineCore::AViewBase
{	
public:

	SampleView(AWindowBase* const window);

	virtual int Init() override;
	virtual int Update(int time_ms) override;
	virtual int Draw() override;
	virtual int PreDraw() override;
	virtual int PostDraw() override;

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
	static constexpr Vector Lpos[2] = { {0.0f, 0.0f, -5.0f, 1.0f},{ 8.0f, 0.0f, 0.0f, 1.0f } };
	static constexpr GLfloat Lamb[] = { 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f };
	static constexpr GLfloat Ldiff[] = { 0.8f, 0.8f, 0.8f, 0.9f, 0.9f, 0.9f };
	static constexpr GLfloat Lspec[] = { 1.0f, 0.5f, 0.5f, 0.9f, 0.9f, 0.9f };

	Uniform<Material>* material;
	std::unique_ptr<Shape> shape;
	std::unique_ptr<Shape> shapeSphere;

	Noon::GraphicsCore::Texture* m_tex;


};