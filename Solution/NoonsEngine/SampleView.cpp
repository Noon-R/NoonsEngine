#include "SampleView.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

SampleView::SampleView(AWindowBase* const window)
	:ADefineView(window)
	, m_program(loadProgram("testuv.vert", "testuv.frag"))
	,m_modelviewLoc(glGetUniformLocation(m_program, "modelview"))
	,m_projectionLoc(glGetUniformLocation(m_program, "projection"))
	,m_normalMatrixLoc(glGetUniformLocation(m_program, "normalMatrix"))
	,m_LposLoc(glGetUniformLocation(m_program, "Lpos"))
	,m_LambLoc(glGetUniformLocation(m_program, "Lamb"))
	,m_LdiffLoc(glGetUniformLocation(m_program, "Ldiff"))
	,m_LspecLoc(glGetUniformLocation(m_program, "Lspec"))
	,m_materialLoc(glGetUniformBlockIndex(m_program, "Material"))

{

	//shaderŠÖ˜A‚ðŠÈ’P‚É‚¢‚¶‚ê‚é‚æ‚¤‚É‚µ‚Ä‚¨‚«‚½‚¢‚Ë


	glUniformBlockBinding(m_program, m_materialLoc, 0);

	unsigned char* data;
	int width;
	int height;
	int bpp;

	data = stbi_load("mochiz04.jpg", &width, &height, &bpp, 0);


	m_tex = new Noon::GraphicsCore::Texture(GL_RGB, width, height, data, m_window);

	static constexpr Material color[] = {
		{0.6f, 0.6f, 0.2f, 0.6f, 0.6f, 0.2f, 0.3f, 0.3f, 0.3f, 30.0f},
		{0.1f, 0.1f, 0.5f, 0.1f, 0.1f, 0.5f, 0.4f, 0.4f, 0.4f, 60.0f}
	};

	material = new Uniform<Material>(color, 2);
	std::pair<std::vector<Object::Vertex>, int> vertexInfo = LoadObjFile("sord.obj");

	std::cout << vertexInfo.first[0].position[0] << std::endl;
	std::cout << vertexInfo.first[0].position[1] << std::endl;
	std::cout << vertexInfo.first[0].position[2] << std::endl;

	shape.reset(new SolidShape(m_window,3,vertexInfo.second,&vertexInfo.first[0]));
	shapeSphere.reset(CreateSolidSphere(m_window, 32, 16));

}

int SampleView::Init()
{

	

	return 0;
}

int SampleView::Update()
{

	

	return 0;
}

int SampleView::Draw()
{

	m_window->SetWindowContext(); {

		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(m_program);

		const GLfloat* const size(m_window->GetSize());
		const GLfloat scale(m_window->GetScale() * 2.0f);
		const GLfloat fovy(m_window->GetScale() * 0.01f);
		const GLfloat aspect(size[0] / size[1]);

		const Matrix projection(Matrix::Perspective(fovy, aspect, 1.0f, 10.0f));
		const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));
		const Matrix translation(Matrix::Translate(0, 0, 0));

		const Matrix r(Matrix::Rotate(static_cast<GLfloat>(glfwGetTime()), 0.0f, 1.0f, 0.0f));
		//const Matrix model(translation * scaling);
		const Matrix model(r);

		const Matrix view(Matrix::LookAt(
			3.0f, 1.0f, 5.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f
		));

		GLfloat normalMatrix[9];

		const Matrix modelView(view * model);

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


		material->Select(0, 0);
		glActiveTexture(GL_TEXTURE0);
		m_tex->BindTexture();
		shape->Draw();
		m_tex->ReleaseTexture();
		//shapeSphere->Draw();

		const Matrix modelview1(modelView * Matrix::Translate(0.0f, 0.0f, 3.0f));

		modelview1.GetNormalMatrix(normalMatrix);

		glUniformMatrix4fv(m_modelviewLoc, 1, GL_FALSE, modelview1.data());
		glUniformMatrix3fv(m_normalMatrixLoc, 1, GL_FALSE, normalMatrix);

		material->Select(0, 1);
		//shape->Draw();
	}
	m_window->SwapBuffers();

	return 0;
}
