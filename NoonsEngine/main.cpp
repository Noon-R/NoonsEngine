#include<GL/glew.h>
#include<iostream>

#include"WindowBase.h"

int draw() {
	glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	glBegin(GL_TRIANGLES); {
		glVertex2f(0, 0.5);
		glVertex2f(-0.5, -0.5);
		glVertex2f(0.5, -0.5);
	}
	glEnd();

	return 0;
}

int main() {

	if (glfwInit() == GL_FALSE) {
		return -1;
	}

	WindowBase* window = new WindowBase(640, 480, "Noon's Engine", NULL, NULL);
	window->SetDrawFunc(draw);


	if (!window->GetWindow()) {
		glfwTerminate();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	while (glfwWindowShouldClose(window->GetWindow()) == GL_FALSE) {

		
		window->DrawUpdate();

		glfwPollEvents();

	}

	glfwTerminate(); 

	/*GLFWwindow* window = glfwCreateWindow(640,480, "Noon's Engine", NULL, NULL);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	while (glfwWindowShouldClose(window) == GL_FALSE) {

		glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		glBegin(GL_TRIANGLES); {
			glVertex2f(0, 0.5);
			glVertex2f(-0.5, -0.5);
			glVertex2f(0.5, -0.5);
		}
		glEnd();

		
		glfwPollEvents();

	}

	glfwTerminate();*/

	return 0;

}