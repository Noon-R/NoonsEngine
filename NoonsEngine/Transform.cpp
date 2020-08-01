#include "Transform.h"

#include "Matrix.h"


Transform::Transform()
	: m_pos( )
	, m_rotation()
	,m_canPortation(true)
	,m_isFixing(false)
{
}

Transform::~Transform()
{
}

int Transform::Translate(float x, float y, float z)
{
	if (m_isFixing)return -1;
	m_pos[0] += x;
	m_pos[1] += y;
	m_pos[2] += z;

	return 0;
}

int Transform::Rotatae(float x, float y, float z)
{
	if (m_isFixing)return -1;

	m_rotation[0] += x;
	m_rotation[1] += y;
	m_rotation[2] += z;
	return 0;
}

int Transform::FixObject()
{
	m_isFixing = true;
	return 0;
}

int Transform::SetPosition(float x, float y, float z)
{
	if (!m_canPortation)return -1;

	m_pos[0] = x;
	m_pos[1] = y;
	m_pos[2] = z;
	return 0;
}

int Transform::SetRotation(float roll, float yaw, float pitch)
{
	if (!m_canPortation)return -1;
	m_rotation[0] = roll;
	m_rotation[1] = yaw;
	m_rotation[2] = pitch;
	return 0;
}


float const* Transform::GetPosition()
{
	return m_pos;
}

float const* Transform::GetRoattion()
{
	return m_rotation;
}
