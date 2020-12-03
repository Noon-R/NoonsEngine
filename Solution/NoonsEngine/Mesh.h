#pragma once
#include<GL/glew.h>
#include "Vertex.h"

#include "AWindowBase.h"

class Mesh
{

private:

	Mesh(const Mesh& o);
	Mesh& operator=(const Mesh& o);

	GLuint m_vao;

	GLuint m_vbo;

	GLuint m_ibo;


public:

	

	Mesh(AWindowBase* window, GLint size, GLsizei vertexcount, const Noon::GraphicsCore::Vertex* vertex, GLsizei indexcount = 0, const GLuint* index = NULL);
	virtual ~Mesh();

	void Bind() const;

	void Release() const;
};

