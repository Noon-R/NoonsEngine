#pragma once
#include <memory>
#include <GL/glew.h>

template <typename T>
class Uniform {

public:

	Uniform(const T* data = NULL) 
		: m_buffer(new UniformBuffer(data))
	{
	}

	virtual ~Uniform() {}

	void Set(const T* data) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer->ubo);
		glBufferSubData(GL_UNIFORM_BUFFER, 0,
			sizeof(T), data
			);
	}

	void Select(GLuint bp) const {
		glBindBufferBase(GL_UNIFORM_BUFFER, bp,
			m_buffer->ubo
			);
	}


private:

	struct UniformBuffer {
		GLuint ubo;

		UniformBuffer(const T* data) {
			glGenBuffers(1, &ubo);
			glBindBuffer(GL_UNIFORM_BUFFER, ubo);
			glBufferData(GL_UNIFORM_BUFFER,
				sizeof(T), data, GL_STATIC_DRAW
				);
		}

		~UniformBuffer() {
			glDeleteBuffers(1, &ubo);
		}
	};

	const std::shared_ptr<const UniformBuffer> m_buffer;

};