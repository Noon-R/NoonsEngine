#pragma once
#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

class AWindowBase {
public:

	AWindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	~AWindowBase();
	
	void SetSize(GLfloat width, GLfloat height);

	void SetWindowContext() const;
	void SwapBuffers() const;
	GLFWwindow* GetWindow() const;
	GLfloat GetAspect() const;
	GLfloat GetScale() const;

	const GLfloat* GetSize() const;

	explicit operator bool() const;
private:
	GLFWwindow* m_window;
	GLfloat m_size[2];
	GLfloat m_scale;

	static void Resize(GLFWwindow* const window, int width, int height);
};

