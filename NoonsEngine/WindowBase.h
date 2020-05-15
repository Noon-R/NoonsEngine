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
	void UseShader() const;
	void SwapBuffers() const;
	void SetAspect(GLfloat aspect);
	GLFWwindow* GetWindow();
	GLfloat GetAspect();
	explicit operator bool() const;
private:
	GLFWwindow *const m_window;
	GLuint m_program;
	GLfloat m_aspect;
	GLint m_aspectLoc;
	static void Resize(GLFWwindow* const window, int width, int height);
};

