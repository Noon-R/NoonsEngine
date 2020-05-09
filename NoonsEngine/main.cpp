#include<GLFW/glfw3.h>
#include<iostream>

int main() {

	if (glfwInit() == GL_FALSE) {
		return -1;
	}

	GLFWwindow* window = glfwCreateWindow(640,480, "Noon's Engine", NULL, NULL);

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

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();

	return 0;

}