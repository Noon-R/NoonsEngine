#pragma once
class Transform {
public:
	Transform();
	~Transform();

	int Translate(float x, float y, float z);
	int Rotatae(float x, float y, float z, float radian);
	int SetPosition(float x, float y,float z);
	int SetRotation(float x, float y, float z);
	float* GetPosition();
	float* GetRoattion();
	
private:
	float m_pos[3];
	float m_rotation[3];


};