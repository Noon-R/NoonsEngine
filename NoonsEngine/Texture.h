#pragma once

#include<GL/glew.h>
#include "WindowBase.h"

class Texture {

public:
	Texture(GLenum level, int width, int height, const void* data);
	~Texture();
	int BindTexture();
	int ReleaseTexture();

	int ChangeTexture(GLenum level,int width,int height, const void* data);

private:

	GLuint m_textureID;
	int m_height;
	int m_width;

};