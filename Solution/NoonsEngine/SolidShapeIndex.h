#pragma once

#include "ShapeIndex.h"

class SolidShapeIndex
	: public ShapeIndex 
{
public:

	SolidShapeIndex(AWindowBase* const window, GLint size, GLsizei vertexcount, const Noon::GraphicsCore::Vertex* vertex, GLsizei indexcount, const GLuint* index)
		: ShapeIndex(window, size, vertexcount, vertex, indexcount,index)
	{
	}

	virtual void Execute() const {
		glDrawElements(GL_TRIANGLES, m_indexcount, GL_UNSIGNED_INT, 0);
	}

};