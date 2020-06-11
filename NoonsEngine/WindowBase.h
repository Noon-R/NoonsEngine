#pragma once
#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

class WindowBase {
public:

	WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	~WindowBase();
	void SetWindowContext() const;
	//UseShader And Set some UniformParams
	void SwapBuffers() const;
	void SetSize(GLfloat width, GLfloat height);
	GLFWwindow* GetWindow();
	const GLfloat* GetSize() const;
	GLfloat GetAspect() const;
	GLfloat GetScale() const;
	explicit operator bool() const;
private:
	GLFWwindow* m_window;
	GLfloat m_size[2];
	GLfloat m_scale;

	static void Resize(GLFWwindow* const window, int width, int height);
};

