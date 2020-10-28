#pragma once

#include<GL/glew.h>
#include "AWindowBase.h"

class Texture {

public:
	Texture(GLenum level, int width, int height, const void* data, AWindowBase* const window);
	~Texture();
	int BindTexture();
	int ReleaseTexture();

	int ChangeTexture(GLenum level,int width,int height, const void* data, AWindowBase* const window);

private:

	GLuint m_textureID;
	int m_height;
	int m_width;

};