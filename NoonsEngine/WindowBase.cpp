#include"WindowBase.h"




WindowBase::WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) 
	: m_window(glfwCreateWindow(width, height, title, monitor, share)),
	  m_aspect(static_cast<GLfloat>(width) / static_cast<GLfloat>(height))
{
	glfwMakeContextCurrent(m_window);
	
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "You could not Init GLEW" << std::endl;
		exit(1);
	}

	m_program = loadProgram("point.vert","point.frag");
	m_aspectLoc = glGetUniformLocation(m_program, "aspect");

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


//UseShader And Set some UniformParams
void WindowBase::UseShader() const
{
	glUseProgram(m_program);
	glUniform1f(m_aspectLoc, m_aspect);
}

void WindowBase::SwapBuffers() const{
	glfwSwapBuffers(m_window);
}

void WindowBase::SetAspect(GLfloat aspect) {
	
	m_aspect = aspect;
}


GLFWwindow* WindowBase::GetWindow() {
	return m_window;
}

GLfloat WindowBase::GetAspect()
{
	return m_aspect;
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
		instance->SetAspect(
			static_cast<GLfloat>(width) / static_cast<GLfloat>(height)
		);
	}
	glViewport(0, 0, fw, fh);

}
