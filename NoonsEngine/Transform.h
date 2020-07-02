#pragma once
class Transform {
public:
	Transform();
	~Transform();

	int Translate(float x, float y, float z);
	int Rotatae(float x, float y, float z, float radian);
	int FixObject();
	int SetPosition(float x, float y,float z);
	int SetRotation(float roll, float yaw, float pitch);
	float* GetPosition();
	float* GetRoattion();
	
private:
	float m_pos[3];
	float m_rotation[3];

	bool m_canPortation;
	bool m_isFixing;

};