#include"WindowBase.h"




WindowBase::WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) 
	: m_window(glfwCreateWindow(width, height, title, monitor, share)),
	  m_scale(100)
{
	glfwMakeContextCurrent(m_window);
	
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "You could not Init GLEW" << std::endl;
		exit(1);
	}

	glfwSwapInterval(1);

	glfwSetWindowUserPointer(m_window, this);

	glfwSetWindowSizeCallback(m_window, Resize);
}

WindowBase::~WindowBase() {
	glfwDestroyWindow(m_window);
}


void WindowBase::SetWindowContext() const {
	glfwMakeContextCurrent(m_window);
}

void WindowBase::SwapBuffers() const{
	glfwSwapBuffers(m_window);
}

void WindowBase::SetSize(GLfloat width, GLfloat height)
{
	m_size[0] = width;
	m_size[1] = height;
}


const GLFWwindow* WindowBase::GetWindow() {
	return m_window;
}

GLfloat WindowBase::GetAspect() const
{
	return m_size[0] / m_size[1];
}

const GLfloat *WindowBase::GetSize() const
{
	return m_size;
}

GLfloat WindowBase::GetScale() const
{
	return m_scale;
}

WindowBase::operator bool() const
{
	return !(glfwWindowShouldClose(m_window));

}

void WindowBase::Resize(GLFWwindow* const window, int width, int height) {

	int fw, fh;

	glfwGetFramebufferSize(window, &fw, &fh);

	WindowBase* const instance(static_cast<WindowBase*>(glfwGetWindowUserPointer(window)));

	if (instance != NULL) {
		instance->SetSize(static_cast<GLfloat>(width), static_cast<GLfloat>(height));
	}
	glViewport(0, 0, fw, fh);

}
