#pragma once

#include "Shape.h"

class SolidShape
	: public Shape
{
public:

	SolidShape(GLint size, GLsizei vertexcount, const Object::Vertex* vertex, WindowBase* const window)
		: Shape(size, vertexcount, vertex, window)
	{
	}

	virtual void Execute() const {
		glDrawArrays(GL_TRIANGLES, 0, m_vertexcount);
	}

};