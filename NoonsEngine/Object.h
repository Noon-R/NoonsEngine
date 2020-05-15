#pragma once
#include<GL/glew.h>
#include "WindowBase.h"

class Object
{

private:

	Object(const Object& o);
	Object& operator=(const Object& o);

	GLuint m_vao;

	GLuint m_vbo;

public:

	struct Vertex {
		GLfloat position[2];
	};

	Object(GLint size, GLsizei vertexcount, const Vertex* vertex, WindowBase *window) {

		window->SetWindowContext();

		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		
		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER,
			vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW
			);

		glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);

	}
	virtual ~Object() {

		glDeleteVertexArrays(1, &m_vao);

		glDeleteBuffers(1, &m_vbo);

	}

	void Bind() const {
		glBindVertexArray(m_vao);
	}

	void Release() const {
		glBindVertexArray(0);
	}
};

