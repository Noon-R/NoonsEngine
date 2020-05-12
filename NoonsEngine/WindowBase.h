#pragma once
#include<vector>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

class WindowBase {
public:

	WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	int SetDrawFunc(int(*func) (void));
	int DrawUpdate();
	GLFWwindow* GetWindow();
private:
	GLFWwindow* m_window;
	int (*draw) () = NULL;
	GLuint m_program;

};

