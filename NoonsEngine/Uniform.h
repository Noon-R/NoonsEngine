#pragma once
#include <memory>
#include <GL/glew.h>

template <typename T>
class Uniform {

public:

	Uniform(const T* data = NULL, unsigned int count = 1) 
		: m_buffer(new UniformBuffer(data,count))
	{
	}

	virtual ~Uniform() {}

	void Set(const T* data, unsigned int start = 0, unsigned int count = 1) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_buffer->ubo);
		for (unsigned int i = 0; i < count; ++i) {
			glBufferSubData(GL_UNIFORM_BUFFER, (start + i) * m_buffer->blocksize,
				sizeof(T), data + i
			);
		}
	}

	void Select(GLuint bp, unsigned int i = 0) const {
		glBindBufferRange(GL_UNIFORM_BUFFER, bp,
			m_buffer->ubo, i * m_buffer->blocksize, sizeof(T)
			);
	}


private:

	struct UniformBuffer {
		GLuint ubo;
		GLsizeiptr blocksize;

		UniformBuffer(const T* data, unsigned int count) {

			GLint alignment;
			glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &alignment);
			blocksize = (((sizeof(T) - 1) / alignment) + 1) * alignment;

			glGenBuffers(1, &ubo);
			glBindBuffer(GL_UNIFORM_BUFFER, ubo);
			glBufferData(GL_UNIFORM_BUFFER,
				count * blocksize , NULL, GL_STATIC_DRAW
				);
			for (unsigned int i = 0; i < count; i++) {
				glBufferSubData(GL_UNIFORM_BUFFER, i * blocksize,
					sizeof(T), data + i
					);
			}
		}

		~UniformBuffer() {
			glDeleteBuffers(1, &ubo);
		}
	};

	const std::shared_ptr<const UniformBuffer> m_buffer;

};