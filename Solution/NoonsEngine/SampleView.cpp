#include "SampleView.h"

#include "glShader.h"
#include "ShapeCreator.h"
#include "ModelLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

SampleView::SampleView(AWindowBase* const window)
	:AViewBase(window)
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

	//shader関連を簡単にいじれるようにしておきたいね


	glUniformBlockBinding(m_program, m_materialLoc, 0);

	unsigned char* data;
	int width;
	int height;
	int bpp;

	data = stbi_load("mochiz04.jpg", &width, &height, &bpp, 0);


	m_tex = new Noon::GraphicsCore::Texture(GL_RGB, width, height, data, window);

	static constexpr Material color[] = {
		{0.6f, 0.6f, 0.2f, 0.6f, 0.6f, 0.2f, 0.3f, 0.3f, 0.3f, 30.0f},
		{0.1f, 0.1f, 0.5f, 0.1f, 0.1f, 0.5f, 0.4f, 0.4f, 0.4f, 60.0f}
	};

	material = new Uniform<Material>(color, 2);
	std::pair<std::vector<Noon::GraphicsCore::Vertex>, int> vertexInfo = LoadObjFile("sword.obj");

	std::cout << vertexInfo.first[0].position[0] << std::endl;
	std::cout << vertexInfo.first[0].position[1] << std::endl;
	std::cout << vertexInfo.first[0].position[2] << std::endl;

	shape.reset(new SolidShape(window,3,vertexInfo.second,&vertexInfo.first[0]));
	shapeSphere.reset(CreateSolidSphere(window, 32, 16));

}

int SampleView::PreDraw()
{
	return 0;
}

int SampleView::PostDraw()
{
	return 0;
}

int SampleView::Init( )
{

	

	return 0;
}

int SampleView::Update(int time_ms)
{

	

	return 0;
}

int SampleView::Draw()
{

	m_window->SetWindowContext(); {

		glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		const GLfloat* const size(m_window->GetSize());
		const GLfloat scale(m_window->GetScale() * 2.0f);
		const GLfloat fovy(m_window->GetScale() * 0.01f);
		const GLfloat aspect(size[0] / size[1]);

		const Matrix projection(Matrix::Perspective(fovy, aspect, 1.0f, 10.0f));
		const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));
		

		const Matrix view(Matrix::LookAt(
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, -5.0f,
			0.0f, 1.0f, 0.0f
		));

		
		//下４行の関数化
		const Matrix translation(Matrix::Translate(0, 0, -5)); 
		const Matrix r(Matrix::Rotate(static_cast<GLfloat>(glfwGetTime()), 0.0f, 1.0f, 0.0f));
		const Matrix obj_scale(Matrix::Scale(1,1,1));
		const Matrix model(translation * scaling * obj_scale * r);

		const Matrix modelView(view * model);

		GLfloat normalMatrix[9];
		modelView.GetNormalMatrix(normalMatrix);

		glUseProgram(m_program);

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
		glActiveTexture(GL_TEXTURE0);  //これの必要かどうか
		m_tex->BindTexture();
		shape->Draw();
		m_tex->ReleaseTexture();

	}
	m_window->SwapBuffers();

	return 0;
}
