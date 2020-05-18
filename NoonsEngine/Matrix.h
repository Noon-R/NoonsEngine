#pragma once
#include <algorithm>
#include <cmath>
#include <GL/glew.h>

class Matrix {
public:

	Matrix() {}

	Matrix(const GLfloat* a);

	const GLfloat* data() const;

	void LoadIdentity();

	static Matrix identity();

	static Matrix Translate(GLfloat x, GLfloat y, GLfloat z);

	static Matrix Scale(GLfloat x, GLfloat y, GLfloat z);

	//a : angle , x,y,z : Axis
	static Matrix Rotate(GLfloat a, GLfloat x, GLfloat y, GLfloat z);

	static Matrix LookAt(
		GLfloat ex, GLfloat ey, GLfloat ez,
		GLfloat gx, GLfloat gy, GLfloat gz,
		GLfloat ux, GLfloat uy, GLfloat uz
		);

	static Matrix Orthographic(
		GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar
	);

	static Matrix Frustum(
		GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat zNear, GLfloat zFar
	);

	static Matrix Perspective(
		GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar
	);

	const GLfloat& operator[](std::size_t i) const;

	GLfloat& operator[](std::size_t i);

	Matrix operator* (const Matrix& m) const;

private:

	GLfloat m_matrix[16];

};