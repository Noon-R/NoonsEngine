#include"WindowBase.h"




WindowBase::WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) 
	: m_window(glfwCreateWindow(width, height, title, monitor, share))
{
	glfwMakeContextCurrent(m_window);
	
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "You could not Init GLEW" << std::endl;
		exit(1);
	}

	m_program = loadProgram("point.vert","point.frag");
	glfwSwapInterval(1);
}

WindowBase::~WindowBase() {
	glfwDestroyWindow(m_window);
}


void WindowBase::SetWindowContext() const {
	glfwMakeContextCurrent(m_window);
}

void WindowBase::UseShader() const
{
	glUseProgram(m_program);
}

void WindowBase::SwapBuffers() const{
	glfwSwapBuffers(m_window);
}

GLFWwindow* WindowBase::GetWindow() {
	return m_window;
}

WindowBase::operator bool() const
{
	return !(glfwWindowShouldClose(m_window));

}
