#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

#include"WindowBase.h"
#include"Shape.h"


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


	


	WindowBase* window02 = new WindowBase(640, 480, "Noon's Engine02", NULL, NULL);

	if (!window02->GetWindow()) {
		return -1;
	}

	std::unique_ptr<Shape> shape(new Shape(3, 4, rectangleVertex,window));


	while (*window) {
		
		window02->SetWindowContext(); {
			glClearColor(0.2f, 0.5f, 0.2f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			window02->UseShader();
		}
		window02->SwapBuffers();
		
		window->SetWindowContext(); {
			
			glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			window->UseShader();
			shape->Draw();
		}
		window->SwapBuffers();
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}