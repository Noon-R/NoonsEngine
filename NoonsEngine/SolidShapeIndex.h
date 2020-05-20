#pragma once

#include "ShapeIndex.h"

class SolidShapeIndex
	: public ShapeIndex 
{
public:

	SolidShapeIndex(GLint size, GLsizei vertexcount, const Object::Vertex* vertex, GLsizei indexcount, const GLuint* index, WindowBase * const window)
		: ShapeIndex(size, vertexcount, vertex,window, indexcount,index)
	{
	}

	virtual void Execute() const {
		glDrawElements(GL_TRIANGLES, m_indexcount, GL_UNSIGNED_INT, 0);
	}

};