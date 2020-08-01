#pragma once
class Transform {
public:
	Transform();
	~Transform();

	int Translate(float x, float y, float z);

	//setting x,y,z:Axis radian: angle
	int Rotatae(float x, float y, float z);
	int FixObject();
	int SetPosition(float x, float y,float z);
	int SetRotation(float roll, float yaw, float pitch);
	float const * GetPosition();
	float const * GetRoattion();
	
private:
	float m_pos[3];
	float m_rotation[3];

	bool m_canPortation;
	bool m_isFixing;

};