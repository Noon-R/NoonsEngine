#pragma once
#include <algorithm>
#include <GL/glew.h>

class Matrix {
public:

	Matrix() {}

	Matrix(const GLfloat* a) {
		std::copy(a, a + 16, m_matrix);
	}

	const GLfloat* data() const {
		return m_matrix;
	}

	void LoadIdentity() {
		std::fill(m_matrix, m_matrix + 16, 0.0f);
		m_matrix[0] = m_matrix[5] = m_matrix[10] = m_matrix[15] = 1.0f;
	}

	static Matrix identity() {
		Matrix t;
		t.LoadIdentity();
		return t;
	}

	const GLfloat& operator[](std::size_t i) const {
		return m_matrix[i];
	}

	GLfloat& operator[](std::size_t i) {
		return m_matrix[i];
	}
private:

	GLfloat m_matrix[16];

};