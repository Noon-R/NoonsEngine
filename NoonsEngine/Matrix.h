#pragma once
#include <algorithm>
#include <GL/glew.h>

class Matrix {
public:

	Matrix() {}

	Matrix(const GLfloat* a) {
		std::copy(a, a + 16, m_matrix);
	}

	const GLfloat& operator[](std::size_t i) const {
		return m_matrix[i];
	}

	GLfloat &operator[](std::size_t i) {
		return m_matrix[i];
	}

	const GLfloat* data() const {
		return m_matrix;
	}

private:

	GLfloat m_matrix[16];

};