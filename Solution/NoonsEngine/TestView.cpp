#include "TestView.h"



#include <iostream>

TestView::TestView(AWindowBase* const window)
	:ADefineView(window)
	, m_program(loadProgram("testuv.vert", "testuv.frag"))
	, m_modelviewLoc(glGetUniformLocation(m_program, "modelview"))
	, m_projectionLoc(glGetUniformLocation(m_program, "projection"))
	, m_normalMatrixLoc(glGetUniformLocation(m_program, "normalMatrix"))
	, m_LposLoc(glGetUniformLocation(m_program, "Lpos"))
	, m_LambLoc(glGetUniformLocation(m_program, "Lamb"))
	, m_LdiffLoc(glGetUniformLocation(m_program, "Ldiff"))
	, m_LspecLoc(glGetUniformLocation(m_program, "Lspec"))
	, m_materialLoc(glGetUniformBlockIndex(m_program, "Material"))

{

	unsigned char* data;
	int width;
	int height;
	int bpp;

	//data = stbi_load("noon_moon_quad_256.png",&width, &height, &bpp,0);

	unsigned char cols[] = {
		255,255,255,255,	255,0,0,255,		0,255,0,255,		0,0,255,255,
		255,255,0,255,		200,200,200,200,    255,0,255,255,		0,255,255,255,
		125,200,200,255,	200,125,200,255,	100,100,100,100,	200,200,125,255,
		0,0,0,0,			125,125,200,255,	125,200,125,255,	0,0,0,255
	};

	m_tex = new Noon::GraphicsCore::Texture( GL_RGBA, 4,4,cols,m_window);

	//stbi_image_free(data);
	glUniformBlockBinding(m_program, m_materialLoc, 0);



	static constexpr Material color[] = {
		{0.6f, 0.6f, 0.2f, 0.6f, 0.6f, 0.2f, 0.3f, 0.3f, 0.3f, 30.0f},
		{0.1f, 0.1f, 0.5f, 0.1f, 0.1f, 0.5f, 0.4f, 0.4f, 0.4f, 60.0f}
	};
	
	material = new Uniform<Material>(color, 2);

	Object::Vertex quad[] = {
		{1.0f ,1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f},
		{-1.0f ,1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f},
		{-1.0f ,-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},
		{1.0f ,-1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f}
	};

	GLuint index[] = { 0,1,2, 2,3,0 };
	shape.reset(new SolidShapeIndex(m_window, 3, 6, quad, 6, index));
	

}

int TestView::Init()
{



	return 0;
}

int TestView::Update()
{



	return 0;
}

int TestView::Draw()
{

	m_window->SetWindowContext(); {

		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(m_program);

		const GLfloat* const size(m_window->GetSize());
		const GLfloat scale(m_window->GetScale() * 2.0f);
		const GLfloat fovy(m_window->GetScale() * 0.01f);
		const GLfloat aspect(size[0] / size[1]);

		const Matrix projection(Matrix::Orthographic(-1.5f * aspect, 1.5f * aspect, -1.5f, 1.5f, 0, 10));
		const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));
		const Matrix translation(Matrix::Translate(0, 0, 0));

		//const Matrix r(Matrix::Rotate(static_cast<GLfloat>(glfwGetTime()), 0.0f, 1.0f, 0.0f));
		//const Matrix model(translation * scaling);
		//const Matrix model(r);

		const Matrix view(Matrix::LookAt(
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		));

		GLfloat normalMatrix[9];

		const Matrix modelView(view);

		modelView.GetNormalMatrix(normalMatrix);

		glUniformMatrix4fv(m_projectionLoc, 1, GL_FALSE, projection.data());
		glUniformMatrix4fv(m_modelviewLoc, 1, GL_FALSE, modelView.data());
		glUniformMatrix3fv(m_normalMatrixLoc, 1, GL_FALSE, normalMatrix);
		for (int i = 0; i < Lcount; ++i) {
			glUniform4fv(m_LposLoc + i, 1, (view * Lpos[i]).data());
		}
		glUniform3fv(m_LambLoc, Lcount, Lamb);
		glUniform3fv(m_LdiffLoc, Lcount, Ldiff);
		glUniform3fv(m_LspecLoc, Lcount, Lspec);

		glActiveTexture(GL_TEXTURE0);
		m_tex->BindTexture();
		material->Select(0, 0);
		shape->Draw();
		m_tex->ReleaseTexture();
	}
	m_window->SwapBuffers();

	return 0;
}
