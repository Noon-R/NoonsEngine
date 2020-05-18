#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

#include"WindowBase.h"
#include "glShader.h"
#include"Shape.h"
#include "Matrix.h"


constexpr Object::Vertex rectangleVertex[] = {
	{ -0.5f, -0.5f,0},
	{  0.5f, -0.5f,0},
	{  0.5f,  0.5f,0},
	{ -0.5f,  0.5f,0}
};



int main() {

	if (glfwInit() == GL_FALSE) {
		return -1;
	}
	atexit(glfwTerminate);
	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	WindowBase* window = new WindowBase(1920, 1080, "Noon's Engine", NULL, NULL);
	if (!window->GetWindow()) {
		return -1;
	}

	//glfwWindowHint(GLFW_FLOATING, GL_TRUE); 
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);


	GLuint m_program(loadProgram("point.vert", "point.frag"));
	GLuint modelLoc(glGetUniformLocation(m_program, "model"));

	WindowBase* window02 = new WindowBase(640, 480, "Noon's Engine02", NULL, NULL);

	if (!window02->GetWindow()) {
		return -1;
	}

	std::unique_ptr<Shape> shape(new Shape(3, 4, rectangleVertex,window));


	while (*window) {
		
		window02->SetWindowContext(); {
			glClearColor(0.2f, 0.5f, 0.2f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}
		window02->SwapBuffers();
		
		window->SetWindowContext(); {
			
			glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			
			glUseProgram(m_program);
			
			const GLfloat *const size(window->GetSize());
			const GLfloat scale(window->GetScale() * 2.0f);
			const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));

			const Matrix translation(Matrix::Translate(0.5,0,0));

			const Matrix model(translation * scaling);

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.data());

			shape->Draw();
		}
		window->SwapBuffers();
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}