#include"WindowBase.h"

WindowBase::WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) : m_window(glfwCreateWindow(width, height, title, monitor, share)){
}

int WindowBase::SetDrawFunc(int(*func) (void)) {

	draw = func;
	return 0;
}

int WindowBase::DrawUpdate() {
	
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);

	if (draw != NULL) {
		draw();
	} else {
		return -1;
	}

	glfwSwapBuffers(m_window);
	return 0;
}

GLFWwindow* WindowBase::GetWindow() {
	return m_window;
}