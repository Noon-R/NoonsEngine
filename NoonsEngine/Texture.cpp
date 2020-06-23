#include "Texture.h"

Texture::Texture(GLenum level, int width, int height, const void* data, AWindowBase* const window)
	:m_textureID(0)
{
	
	ChangeTexture(level, width, height, data,window);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_textureID);
}

int Texture::BindTexture()
{

	glBindTexture(GL_TEXTURE_2D, m_textureID);
	return 0;
}

int Texture::ReleaseTexture()
{

	glBindTexture(GL_TEXTURE_2D, 0);
	return 0;
}

int Texture::ChangeTexture(GLenum level, int width, int height, const void* data, AWindowBase* const window)
{
	m_width = width;
	m_height = height;

	if (m_textureID != 0) {
		glDeleteTextures(1, &m_textureID);
	}

	window->SetWindowContext();

	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);

	//ÇÕÇ›èoÇµÇ∆Ç©ÇÃèàóùåàíË
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, level, m_width, m_height, 0, level, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, 0);

	return 0;
}
