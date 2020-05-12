#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

#include"WindowBase.h"
#include"Shape.h"


constexpr Object::Vertex rectangleVertex[] = {
	{ -0.5f, -0.5f},
	{  0.5f, -0.5f},
	{  0.5f,  0.5f},
	{ -0.5f,  0.5f}
};



int main() {

	if (glfwInit() == GL_FALSE) {
		return -1;
	}
	int a = atexit(glfwTerminate);
	std::cout << a << std:: endl;
	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	WindowBase* window = new WindowBase(640, 480, "Noon's Engine", NULL, NULL);
	if (!window->GetWindow()) {
		return -1;
	}

	glfwWindowHint(GLFW_FLOATING, GL_TRUE); 
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);

	

	WindowBase* window02 = new WindowBase(640, 480, "Noon's Engine02", NULL, NULL);

	if (!window02->GetWindow()) {
		return -1;
	}


	std::unique_ptr<Shape> shape(new Shape(2, 4, rectangleVertex));


	while (*window) {
		
		window->SetWindowContext(); {
			glClearColor(1.0,1.0,1.0,1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			window->UseShader();
			shape->draw();
		}
		window->SwapBuffers();

		window02->SetWindowContext(); {
			glClearColor(0.2f, 0.5f, 0.2f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			window02->UseShader();
		}
		window02->SwapBuffers();
		
		
		glfwPollEvents();
	}


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
	glfwTerminate();
	return 0;

}