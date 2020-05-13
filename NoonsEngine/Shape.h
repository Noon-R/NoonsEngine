#pragma once
#include<memory>

#include "Object.h"

class Shape{

private:
	std::shared_ptr<const Object> m_object;

protected:

	const GLsizei m_vertexcount;

public:
	Shape(GLint size, GLsizei vertexcount, const Object::Vertex *vertex)
		:m_object(new Object(size, vertexcount, vertex))
		,m_vertexcount(vertexcount)
	{
	}


	void Draw() const {
		m_object->Bind();
		Execute();
		m_object->Release();
	}

	virtual void Execute() const {
		glDrawArrays(GL_LINE_LOOP, 0, m_vertexcount);
	}

};

