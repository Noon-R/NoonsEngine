#pragma once

#include "Transform.h"
#include "ShaderBase.h"
#include "Matrix.h"
#include "Shape.h"

class AGameObject
{
public:
	AGameObject(AWindowBase* window, Shape * shape, const char* vert, const char* frag);
	~AGameObject();
	int DrawObject(float const * Lpos, float const* Lamb, float const* Ldiff);

private:

	Transform m_transform;
	ShaderBase m_shader;
	Shape m_shape;
};

