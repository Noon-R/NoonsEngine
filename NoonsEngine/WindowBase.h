#pragma once
#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include "glShader.h"

class WindowBase {
public:

	WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	~WindowBase();
	void SetWindowContext() const;
	//UseShader And Set some UniformParams
	void UseShader() const;
	void SwapBuffers() const;
	void SetSize(GLfloat width, GLfloat height);
	const GLFWwindow* GetWindow();
	GLfloat GetAspect() const;
	const GLfloat* GetSize() const;
	GLfloat GetScale() const;
	explicit operator bool() const;
private:
	GLFWwindow *const m_window;
	GLuint m_program;

	GLint m_sizeLoc;
	GLint m_scaleLoc;

	//0: width, 1: height
	GLfloat m_size[2]; 
	GLfloat m_scale;
	static void Resize(GLFWwindow* const window, int width, int height);
};

