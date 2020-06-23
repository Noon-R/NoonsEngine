#include"WindowBase.h"




AWindowBase::AWindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) 
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
	SetSize(width, height);
	Resize(m_window, m_size[0], m_size[1]);
}

AWindowBase::~AWindowBase() {
	glfwDestroyWindow(m_window);
}


void AWindowBase::SetWindowContext() const {
	glfwMakeContextCurrent(m_window);
}

void AWindowBase::SwapBuffers() const{
	glfwSwapBuffers(m_window);
}

void AWindowBase::SetSize(GLfloat width, GLfloat height)
{
	m_size[0] = width;
	m_size[1] = height;
}

GLFWwindow* AWindowBase::GetWindow() {
	return m_window;
}

GLfloat AWindowBase::GetAspect() const
{
	return m_size[0] / m_size[1];
}

const GLfloat *AWindowBase::GetSize() const
{
	return m_size;
}

GLfloat AWindowBase::GetScale() const
{
	return m_scale;
}

AWindowBase::operator bool() const
{
	return !(glfwWindowShouldClose(m_window));

}

void AWindowBase::Resize(GLFWwindow* const window, int width, int height) {

	int fw, fh;

	glfwGetFramebufferSize(window, &fw, &fh);

	AWindowBase* const instance(static_cast<AWindowBase*>(glfwGetWindowUserPointer(window)));

	if (instance != NULL) {
		instance->SetSize(static_cast<GLfloat>(width), static_cast<GLfloat>(height));
	}
	glViewport(0, 0, fw, fh);

}
