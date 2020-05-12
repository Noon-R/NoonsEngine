#include"WindowBase.h"
#include<iostream>

GLuint createProgram(const char* vsrc, const char* fsrc) {

	const GLuint program(glCreateProgram());

	if (vsrc != NULL) {
		const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));

		glShaderSource(vobj, 1, &vsrc, NULL);
		glCompileShader(vobj);

		glAttachShader(program, vobj);
		glDeleteShader(vobj);
	}

	if (fsrc != NULL) {

		const GLuint fobj(glCreateShader(GL_FRAGMENT_SHADER));
		glShaderSource(fobj, 1, &fsrc, NULL);
		glCompileShader(fobj);

		glAttachShader(program, fobj);
		glDeleteShader(fobj);

	}

	glBindAttribLocation(program, 0, "position");
	glBindFragDataLocation(program, 0, "fragment");
	glLinkProgram(program);

	return program;
}

WindowBase::WindowBase(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) 
	: m_window(glfwCreateWindow(width, height, title, monitor, share))
{
	glfwMakeContextCurrent(m_window);
	
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK) {
		std::cout << "Hello" << std::endl;
	}

	m_program = createProgram(
		{
			"#version 150 core\n"
			"in vec4 position; \n"
			"void main(){\n"
			"  gl_position = position;\n"
			"}\n"
		}, {
			"#version 150 core\n"
			"out vec4 fragment; \n"
			"void main(){\n"
			"  fragment = vec4(1.0, 0.0, 0.0, 1.0);\n"
			"}\n"

		}
		);

}

int WindowBase::SetDrawFunc(int(*func) (void)) {

	draw = func;
	return 0;
}

int WindowBase::DrawUpdate() {
	if (glfwWindowShouldClose(m_window) == GL_TRUE) {
		return -1;
	}

	glfwMakeContextCurrent(m_window);
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(m_program);

	if (draw != NULL) {
		draw();
	} else {
		return -1;
	}

	glfwSwapBuffers(m_window);
	glfwPollEvents();
	return 0;
}

GLFWwindow* WindowBase::GetWindow() {
	return m_window;
}

