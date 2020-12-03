#include "Mesh.h"

#include "AWindowBase.h"

Mesh::Mesh(AWindowBase* window, GLint size, GLsizei vertexcount, const Noon::GraphicsCore::Vertex* vertex, GLsizei indexcount, const GLuint* index) {

	//window->SetWindowContext();

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);


	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER,
		vertexcount * sizeof(Noon::GraphicsCore::Vertex), vertex, GL_STATIC_DRAW
	);

	glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, sizeof(Noon::GraphicsCore::Vertex), static_cast<Noon::GraphicsCore::Vertex* >(0)->position);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Noon::GraphicsCore::Vertex), static_cast<Noon::GraphicsCore::Vertex*>(0)->normal);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Noon::GraphicsCore::Vertex), static_cast<Noon::GraphicsCore::Vertex*>(0)->color);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Noon::GraphicsCore::Vertex), static_cast<Noon::GraphicsCore::Vertex*>(0)->uv);
	glEnableVertexAttribArray(3);

	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
		indexcount * sizeof(GLuint), index, GL_STATIC_DRAW
	);


	glBindVertexArray(0);

}

Mesh::~Mesh() {

	glDeleteVertexArrays(1, &m_vao);

	glDeleteBuffers(1, &m_vbo);
	glDeleteBuffers(1, &m_ibo);

}

void Mesh::Bind() const {
	glBindVertexArray(m_vao);
}

void Mesh::Release() const {
	glBindVertexArray(0);
}
