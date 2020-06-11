#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include "SampleView.h"
#include "TestView.h"
#include "UITestView.h"


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

	//SampleView* view01 = new SampleView(window);

	UITestView* view01 = new UITestView(window);

	//BackCulling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//Depth
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	//FloatingWindow
	//glfwWindowHint(GLFW_FLOATING, GL_TRUE);
	//No Frame
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);


	WindowBase* window02 = new WindowBase(960, 540, "Noon's Engine02", NULL, NULL);
	if (!window02->GetWindow()) {
		return -1;
	}

	TestView* view02 = new TestView(window02);

	//BackCulling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//Depth
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);



	glfwSetTime(0.0);


	while (*window) {
	
		window->SetWindowContext();
		view01->Draw();
		
		window02->SetWindowContext();
		view02->Draw();

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}