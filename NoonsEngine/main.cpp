#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include "SampleView.h"

constexpr Object::Vertex cubeVertex[] = { 
	{ -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f },  // (0)
	{ -1.0f, -1.0f,  1.0f, 0.0f, 0.0f, 0.8f },  // (1)   
	{ -1.0f,  1.0f,  1.0f, 0.0f, 0.8f, 0.0f },  // (2) 
	{ -1.0f,  1.0f, -1.0f, 0.0f, 0.8f, 0.8f },  // (3)
	{  1.0f,  1.0f, -1.0f, 0.8f, 0.0f, 0.0f },  // (4) 
	{  1.0f, -1.0f, -1.0f, 0.8f, 0.0f, 0.8f },  // (5)   
	{  1.0f, -1.0f,  1.0f, 0.8f, 0.8f, 0.0f },  // (6)   
	{  1.0f,  1.0f,  1.0f, 0.8f, 0.8f, 0.8f }   // (7)
}; 


//WithIndexVertex
//constexpr Object::Vertex solidCubeVertex[] = {
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//
//	{  1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//
//	{ -1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f}
//};

//SolidCube
//constexpr Object::Vertex solidCubeVertex[] = {
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.1f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f, -1.0f,  0.1f,  0.8f, 0.1f},
//
//	{  1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.8f},
//
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//	{ -1.0f, -1.0f, -1.0f,  0.1f,  0.8f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//	{ -1.0f, -1.0f,  1.0f,  0.1f,  0.8f, 0.8f},
//
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f, -1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f, -1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f, -1.0f,  0.1f,  0.1f, 0.8f},
//	{  1.0f,  1.0f,  1.0f,  0.1f,  0.1f, 0.8f},
//
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{ -1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.1f, 0.1f},
//	{  1.0f,  1.0f, -1.0f,  0.8f,  0.1f, 0.1f},
//
//	{ -1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{ -1.0f, -1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{  1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f},
//	{ -1.0f,  1.0f,  1.0f,  0.8f,  0.8f, 0.1f}
//};




//constexpr GLuint solidCubeIndex[] = {
//	0, 1, 2, 0, 2, 3,
//	0, 3, 4, 0, 4, 5,
//	0, 5, 6, 0, 6, 1,
//	7, 6, 5, 7, 5, 4,
//	7, 4, 3, 7, 3, 2,
//	7, 2, 1, 7, 1, 6
//};

//constexpr GLuint solidCubeIndex[] = {
//	0,  1,  2,  0,  2,  3,
//	4,  5,  6,  4,  6,  7,
//	8,  9, 10,  8, 10, 11,
//   12, 13, 14, 12, 14, 15,
//   16, 17, 18, 16, 18, 19,
//   20, 21, 22, 20, 22, 23
//};

constexpr GLuint solidCubeIndex[] = {
	 0,  1,  2,  3,  4,   5,
	 6,  7,  8,  9, 10,  11,
	12, 13, 14, 15, 16,  17,
	18, 19, 20, 21, 22,  23,
	24, 25, 26, 27, 28,  29,
	30, 31, 32, 33, 34,  35,
};


// 六面体の稜線の両端点のインデックス 
constexpr GLuint wireCubeIndex[] = { 
	1, 0, // (a)  
	2, 7, // (b) 
	3, 0, // (c) 
	4, 7, // (d) 
	5, 0, // (e) 
	6, 7, // (f) 
	1, 2, // (g) 
	2, 3, // (h)  
	3, 4, // (i)  
	4, 5, // (j) 
	5, 6, // (k) 
	6, 1  // (l) 
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

	SampleView* view01 = new SampleView(window);

	

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

	SampleView* view02 = new SampleView(window02);

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