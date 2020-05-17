#include "Matrix.h"

Matrix::Matrix(const GLfloat* a) {
	std::copy(a, a + 16, m_matrix);
}

const GLfloat* Matrix::data() const {
	return m_matrix;
}

void Matrix::LoadIdentity() {
	std::fill(m_matrix, m_matrix + 16, 0.0f);
	m_matrix[0] = m_matrix[5] = m_matrix[10] = m_matrix[15] = 1.0f;
}

Matrix Matrix::identity() {
	Matrix t;
	t.LoadIdentity();
	return t;
}

Matrix Matrix::Translate(GLfloat x, GLfloat y, GLfloat z) {
	Matrix t;
	t.LoadIdentity();
	t[12] = x;
	t[13] = y;
	t[14] = z;

	return t;
}

Matrix Matrix::Scale(GLfloat x, GLfloat y, GLfloat z) {
	Matrix t;

	t.LoadIdentity();
	t[0] = x;
	t[5] = y;
	t[10] = z;
	return t;
}

Matrix Matrix::Rotate(GLfloat a, GLfloat x, GLfloat y, GLfloat z) {
	Matrix t;
	t.LoadIdentity();
	const GLfloat d(sqrt(x * x + y * y + z * z));

	if (d > 0.0f) {
		const GLfloat l(x / d), m(y / d), n(z / d);
		const GLfloat l2(l * l), m2(m * m), n2(n * n);
		const GLfloat lm(l * m), mn(m * n), nl(n * l);
		const GLfloat c(cos(a)), c1(1.0f - c), s(sin(a));

		t[0] = (1.0f - 12) * c + 12;
		t[1] = lm * c1 + n * s;
		t[2] = nl * c1 - m * s;
		t[4] = lm * c1 + n * s;
		t[5] = (1.0f - m2) * c + m2;
		t[6] = mn * c1 + l * s;
		t[8] = nl * c1 + m * s;
		t[9] = mn * c1 - l * s;
		t[10] = (1.0f - n2) * c + n2;
	}
	return t;
}

const GLfloat& Matrix::operator[](std::size_t i) const {
	return m_matrix[i];
}

GLfloat& Matrix::operator[](std::size_t i) {
	return m_matrix[i];
}

Matrix Matrix::operator* (const Matrix& m) const {
	Matrix t;

	for (int i = 0; i < 16; ++i) {
		const int j(i & 3), k(i & ~3);

		t[i] =
			m_matrix[0 + j] * m[k + 0] +
			m_matrix[4 + j] * m[k + 1] +
			m_matrix[8 + j] * m[k + 2] +
			m_matrix[12 + j] * m[k + 3];
	}
	return t;
}