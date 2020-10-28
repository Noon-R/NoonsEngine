#pragma once
#include <array>
#include "Matrix.h"


typedef struct Vector3{
	double x, y, z;

	const Vector3 operator+(const Vector3& value) {
		Vector3 ret;
		ret.x = this->x + value.x;
		ret.y = this->y + value.y;
		ret.z = this->z + value.z;
		return ret;
	}

	const Vector3 operator*(double value) {
		
		Vector3 ret = {
			this->x * value,
			this->y * value,
			this->z * value
		};

		return ret;
	}

	Vector3& operator+=(const Vector3& value) {
		
		Vector3 ret = {
		this->x += value.x,
		this->y += value.y,
		this->z += value.z
		};

		return ret;
	}

}Vector3;

typedef struct Vector4{
	double x, y, z, w;

	const Vector4 operator+(const Vector4& value) {
		Vector4 ret;
		ret.x = this->x + value.x;
		ret.y = this->y + value.y;
		ret.z = this->z + value.z;
		ret.w = this->w + value.w;
		return ret;
	}

	const Vector4 operator*(double value) {

		Vector4 ret = {
			this->x * value,
			this->y * value,
			this->z * value,
			this->w * value
		};

		return ret;
	}

	const Vector4 operator*(const Vector4 value) {

		Vector4 ret = {
			this->x * value.x,
			this->y * value.y,
			this->z * value.z,
			this->w * value.w
		};

		return ret;
	}

	Vector4& operator+=(const Vector4& value) {

		Vector4 ret = {
		this->x += value.x,
		this->y += value.y,
		this->z += value.z,
		this->w += value.w
		};

		return ret;
	}


}Vector4;


using Vector = std::array<GLfloat, 4>;

Vector operator*(const Matrix& m, const Vector& v);

