#include "Transform.h"

Transform::Transform()
	: m_pos( )
	, m_rotation()
{
}

Transform::~Transform()
{
}

int Transform::Translate(float x, float y, float z)
{
	return 0;
}

int Transform::Rotatae(float x, float y, float z, float radian)
{
	return 0;
}

int Transform::SetPosition()
{
	return 0;
}

int Transform::SetRotation()
{
	return 0;
}

float* Transform::GetPosition()
{
	return nullptr;
}

float* Transform::GetRoattion()
{
	return nullptr;
}
