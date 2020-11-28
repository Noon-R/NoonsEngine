#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include "NoonEnginStateManager.h"


int main() {

	//-----------------------------------OpenGl------------------------------------

	if (glfwInit() == GL_FALSE) {
		return -1;
	}
	atexit(glfwTerminate);
	

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

	//------------------------------------------------------------------------------


	
	

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

	//BackCulling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//Depth
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);



	glfwSetTime(0.0);

	Noon::NoonEngineCore::NoonEngineStateManager* MainManager = new Noon::NoonEngineCore::NoonEngineStateManager();
	while (MainManager->IsExistWindow()) {
		
		MainManager->Update();

		glfwPollEvents();
	}

	delete MainManager;
	glfwTerminate();
	return 0;

}