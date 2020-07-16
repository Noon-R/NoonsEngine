#pragma once

#include "Transform.h"
#include "ShaderBase.h"
#include "Matrix.h"

class AGameObject
{
public:
	AGameObject(AWindowBase* window, const char* vert, const char* frag);
	~AGameObject();
	int DrawObject(float const * Lpos,);

private:

	Transform m_transform;
	ShaderBase m_shader;

};

