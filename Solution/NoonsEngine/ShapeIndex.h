#pragma once

#include "Shape.h"


class ShapeIndex
	: public Shape {

public:

	ShapeIndex(AWindowBase* const window, GLint size, GLsizei vertexcount, const Object::Vertex* vertex, GLsizei indexcount, const GLuint* index)
		: Shape(window, size, vertexcount, vertex,indexcount, index)
		, m_indexcount(indexcount)
	{
	}

	virtual void Execute() const{
		glDrawElements(GL_LINES, m_indexcount, GL_UNSIGNED_INT, 0);
	}

protected:
	const GLsizei m_indexcount;
};