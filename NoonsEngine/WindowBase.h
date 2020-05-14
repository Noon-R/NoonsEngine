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
	GLFWwindow* GetWindow();
	explicit operator bool() const;
private:
	GLFWwindow *const m_window;
	GLuint m_program;

};

