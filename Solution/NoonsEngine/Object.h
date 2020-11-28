#pragma once
#include<GL/glew.h>
#include "Vertex.h"

#include "AWindowBase.h"

class Object
{

private:

	Object(const Object& o);
	Object& operator=(const Object& o);

	GLuint m_vao;

	GLuint m_vbo;

	GLuint m_ibo;


public:

	

	Object(AWindowBase* window, GLint size, GLsizei vertexcount, const Noon::GraphicsCore::Vertex* vertex, GLsizei indexcount = 0, const GLuint* index = NULL);
	virtual ~Object();

	void Bind() const;

	void Release() const;
};

