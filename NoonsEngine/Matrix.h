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

	static Matrix Rotate(GLfloat a, GLfloat x, GLfloat y, GLfloat z);

	const GLfloat& operator[](std::size_t i) const;

	GLfloat& operator[](std::size_t i);

	Matrix operator* (const Matrix& m) const;

private:

	GLfloat m_matrix[16];

};