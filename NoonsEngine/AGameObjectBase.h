#pragma once

#include "Transform.h"
#include "ShaderBase.h"

class AGameObject
{
public:
	AGameObject();
	~AGameObject();
	int DrawObject();

private:

	Transform m_transform;
	ShaderBase m_shader;

};

