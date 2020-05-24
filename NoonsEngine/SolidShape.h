#pragma once

#include "Shape.h"

class SolidShape
	: public Shape
{
public:

	SolidShape(WindowBase* const window, GLint size, GLsizei vertexcount, const Object::Vertex* vertex)
		: Shape(window, size, vertexcount, vertex)
	{
	}

	virtual void Execute() const {
		glDrawArrays(GL_TRIANGLES, 0, m_vertexcount);
	}

};