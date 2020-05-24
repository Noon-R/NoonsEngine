#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include "WindowBase.h"
#include "glShader.h"
#include "Shape.h"
#include "ShapeIndex.h"
#include "SolidShapeIndex.h"
#include "SolidShape.h"
#include "SphereShape.h"
#include "Uniform.h"
#include "Material.h"
#include "Vector.h"
#include "Matrix.h"

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

constexpr Object::Vertex solidCubeVertex[] = {

	{ -1.0f, -1.0f, -1.0f,  -1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f,  1.0f,  -1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  -1.0f, 0.0f, 0.0f},
	{ -1.0f, -1.0f, -1.0f,  -1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  -1.0f, 0.0f, 0.0f},
	{ -1.0f,  1.0f, -1.0f,  -1.0f, 0.0f, 0.0f},

	{  1.0f, -1.0f, -1.0f,  0.0f, 0.0f, -1.0f},
	{ -1.0f, -1.0f, -1.0f,  0.0f, 0.0f, -1.0f},
	{ -1.0f,  1.0f, -1.0f,  0.0f, 0.0f, -1.0f},
	{  1.0f, -1.0f, -1.0f,  0.0f, 0.0f, -1.0f},
	{ -1.0f,  1.0f, -1.0f,  0.0f, 0.0f, -1.0f},
	{  1.0f,  1.0f, -1.0f,  0.0f, 0.0f, -1.0f},

	{ -1.0f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f},
	{  1.0f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  0.0f, -1.0f, 0.0f},
	{ -1.0f, -1.0f, -1.0f,  0.0f, -1.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  0.0f, -1.0f, 0.0f},
	{ -1.0f, -1.0f,  1.0f,  0.0f, -1.0f, 0.0f},

	{  1.0f, -1.0f,  1.0f,  1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f, -1.0f,  1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f},
	{  1.0f, -1.0f,  1.0f,  1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  1.0f, 0.0f, 0.0f},

	{ -1.0f,  1.0f, -1.0f,  0.0f, 1.0f, 0.0f},
	{ -1.0f,  1.0f,  1.0f,  0.0f, 1.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 1.0f, 0.0f},
	{ -1.0f,  1.0f, -1.0f,  0.0f, 1.0f, 0.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 1.0f, 0.0f},
	{  1.0f,  1.0f, -1.0f,  0.0f, 1.0f, 0.0f},

	{ -1.0f, -1.0f,  1.0f,  0.0f, 0.0f, 1.0f},
	{  1.0f, -1.0f,  1.0f,  0.0f, 0.0f, 1.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f},
	{ -1.0f, -1.0f,  1.0f,  0.0f, 0.0f, 1.0f},
	{  1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f},
	{ -1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f}
};


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

	//FloatingWindow
	//glfwWindowHint(GLFW_FLOATING, GL_TRUE);

	//Without Frame
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);

	//BackCulling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//Depth
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	const GLuint m_program(loadProgram("pointWithNormal.vert", "pointWithNormal.frag"));
	const GLuint modelviewLoc(glGetUniformLocation(m_program, "modelview"));
	const GLuint projectionLoc(glGetUniformLocation(m_program, "projection"));
	const GLuint normalMatrixLoc(glGetUniformLocation(m_program, "normalMatrix"));
	const GLuint LposLoc(glGetUniformLocation(m_program, "Lpos"));
	const GLuint LambLoc(glGetUniformLocation(m_program, "Lamb"));
	const GLuint LdiffLoc(glGetUniformLocation(m_program, "Ldiff"));
	const GLuint LspecLoc(glGetUniformLocation(m_program, "Lspec"));
	const GLint materialLoc(glGetUniformBlockIndex(m_program, "Material"));

	glUniformBlockBinding(m_program, materialLoc, 0);

	static constexpr int Lcount(2);
	static constexpr Vector Lpos[] = { 0.0f, 0.0f, 5.0f, 1.0f, 8.0f, 0.0f, 0.0f, 1.0f };
	static constexpr GLfloat Lamb[] = { 0.2f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f };
	static constexpr GLfloat Ldiff[] = { 0.2f, 0.1f, 0.1f, 0.9f, 0.9f, 0.9f };
	static constexpr GLfloat Lspec[] = { 1.0f, 0.5f, 0.5f, 0.9f, 0.9f, 0.9f };

	static constexpr Material color[] = {
		{0.6f, 0.6f, 0.2f, 0.6f, 0.6f, 0.2f, 0.3f, 0.3f, 0.3f, 30.0f},
		{0.1f, 0.1f, 0.5f, 0.1f, 0.1f, 0.5f, 0.4f, 0.4f, 0.4f, 60.0f}
	};

	const Uniform<Material> material(color, 2);

	std::unique_ptr<Shape> shape(new SolidShape(window, 3, 36, solidCubeVertex));

	

	std::unique_ptr<const Shape> shapeSphere(CreateSolidSphere(window, 32, 16));

	glfwSetTime(0.0);

	while (*window) {
	
		
		window->SetWindowContext(); {
			
			glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			glUseProgram(m_program);
			
			const GLfloat *const size(window->GetSize());
			const GLfloat scale(window->GetScale() * 2.0f);
			const GLfloat fovy(window->GetScale() * 0.01f);
			const GLfloat aspect(size[0] / size[1]);



			const Matrix projection(Matrix::Perspective( fovy, aspect, 1.0f, 10.0f));
			const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));
			const Matrix translation(Matrix::Translate(0,0,0));

			const Matrix r(Matrix::Rotate(static_cast<GLfloat>(glfwGetTime()), 0.0f, 1.0f, 0.0f));
			//const Matrix model(translation * scaling);
			const Matrix model(r);

			const Matrix view(Matrix::LookAt(
				 3.0f,  4.0f,  5.0f,
				 0.0f,  0.0f,  0.0f,
				 0.0f,  1.0f,  0.0f
			));

			GLfloat normalMatrix[9];

			const Matrix modelView( view * model);

			modelView.GetNormalMatrix(normalMatrix);

			glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection.data());
			glUniformMatrix4fv(modelviewLoc, 1, GL_FALSE, modelView.data());
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, normalMatrix);
			for (int i = 0; i < Lcount; ++i) {
				glUniform4fv(LposLoc + i, 1, (view * Lpos[i]).data());
			}
			glUniform3fv(LambLoc, Lcount, Lamb);
			glUniform3fv(LdiffLoc, Lcount, Ldiff);
			glUniform3fv(LspecLoc, Lcount, Lspec);
			
			//shape->Draw();
			material.Select(0,0);
			shapeSphere->Draw();

			const Matrix modelview1(modelView * Matrix::Translate(0.0f, 0.0f, 3.0f));

			modelview1.GetNormalMatrix(normalMatrix);

			glUniformMatrix4fv(modelviewLoc, 1, GL_FALSE, modelview1.data());
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, normalMatrix);

			material.Select(0,1);
			shape->Draw();
		}
		window->SwapBuffers();
		
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;

}