#pragma once

#include "Transform.h"
#include "ShaderBase.h"
#include "Matrix.h"
#include "Shape.h"
#include "Material.h"
#include "Uniform.h"

class AGameObject
{
public:
	AGameObject(AWindowBase* window, Shape * shape, const char* vert, const char* frag);
	~AGameObject();
	int DrawObject(AWindowBase const * window, float const * Lpos, float const* Lamb, float const* Ldiff, float const* Lspec);

private:

	Transform m_transform;
	ShaderBase m_shader;
	Shape* m_shape;
	Uniform<Material>* m_material;
};

