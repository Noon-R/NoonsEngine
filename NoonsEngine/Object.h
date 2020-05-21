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

	GLuint m_ibo;

public:

	struct Vertex {
		GLfloat position[3];
		GLfloat normal[3];
	};

	Object(GLint size, GLsizei vertexcount, const Vertex* vertex, WindowBase* window,GLsizei indexcount = 0, const GLuint *index = NULL) {

		window->SetWindowContext();

		glGenVertexArrays(1, &m_vao);
		glBindVertexArray(m_vao);

		
		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER,
			vertexcount * sizeof(Vertex), vertex, GL_STATIC_DRAW
			);

		glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<Vertex * >(0) -> position);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), static_cast<Vertex*>(0)->normal);
		glEnableVertexAttribArray(1);


		glGenBuffers(1, &m_ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			indexcount * sizeof(GLuint), index, GL_STATIC_DRAW
		);

		glBindVertexArray(0);

	}
	virtual ~Object() {

		glDeleteVertexArrays(1, &m_vao);

		glDeleteBuffers(1, &m_vbo);
		glDeleteBuffers(1, &m_ibo);

	}

	void Bind() const {
		glBindVertexArray(m_vao);
	}

	void Release() const {
		glBindVertexArray(0);
	}
};

