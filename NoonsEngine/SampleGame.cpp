#include "SampleGame.h"

Vector3 cubePos;

SampleGame::SampleGame(AWindowBase* const window)
	:ADefineView(window)
	, m_program(loadProgram("pointWithNormal.vert", "pointWithNormal.frag"))
	, m_modelviewLoc(glGetUniformLocation(m_program, "modelview"))
	, m_projectionLoc(glGetUniformLocation(m_program, "projection"))
	, m_normalMatrixLoc(glGetUniformLocation(m_program, "normalMatrix"))
	, m_LposLoc(glGetUniformLocation(m_program, "Lpos"))
	, m_LambLoc(glGetUniformLocation(m_program, "Lamb"))
	, m_LdiffLoc(glGetUniformLocation(m_program, "Ldiff"))
	, m_LspecLoc(glGetUniformLocation(m_program, "Lspec"))
	, m_materialLoc(glGetUniformBlockIndex(m_program, "Material"))

{

	glfwSetInputMode(m_window->GetWindow(), GLFW_STICKY_KEYS, GLFW_TRUE);


	glUniformBlockBinding(m_program, m_materialLoc, 0);

	static constexpr Material color[] = {
		{0.6f, 0.6f, 0.2f, 0.6f, 0.6f, 0.2f, 0.3f, 0.3f, 0.3f, 30.0f},
		{0.1f, 0.1f, 0.5f, 0.1f, 0.1f, 0.5f, 0.4f, 0.4f, 0.4f, 60.0f}
	};

	material = new Uniform<Material>(color, 2);

	shape.reset(CreateSolidCube(m_window));
}

int SampleGame::Init()
{
	return 0;
}

int SampleGame::Update()
{

	if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_W)) {
		cubePos.z += 0.1;
	} else if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_S)) {
		cubePos.z -= 0.1;
	}

	if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_A)) {
		cubePos.x += 0.1;
	}
	else if (glfwGetKey(m_window->GetWindow(), GLFW_KEY_D)) {
		cubePos.x -= 0.1;
	}

	return 0;
}

int SampleGame::Draw()
{

	m_window->SetWindowContext(); {

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(m_program);

		const GLfloat* const size(m_window->GetSize());
		const GLfloat scale(m_window->GetScale() * 2.0f);
		const GLfloat fovy(m_window->GetScale() * 0.01f);
		const GLfloat aspect(size[0] / size[1]);

		const Matrix projection(Matrix::Perspective(fovy, aspect, 1.0f, 10.0f));
		const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));
		

		const Matrix r(Matrix::Rotate(static_cast<GLfloat>(glfwGetTime()), 0.0f, 1.0f, 0.0f));
		//const Matrix model(translation * scaling);
		const Matrix model(Matrix::Translate(cubePos.x, cubePos.y, cubePos.z));

		const Matrix view(Matrix::LookAt(
			0.0f + cubePos.x, 2.0f + cubePos.y, -5.0f + cubePos.z,
			cubePos.x, cubePos.y, cubePos.z,
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
		shape->Draw();
		
		const Matrix modelview1(view * Matrix::Translate(0.0f, 0.0f, 3.0f));

		modelview1.GetNormalMatrix(normalMatrix);

		glUniformMatrix4fv(m_modelviewLoc, 1, GL_FALSE, modelview1.data());
		glUniformMatrix3fv(m_normalMatrixLoc, 1, GL_FALSE, normalMatrix);

		material->Select(0, 1);
		shape->Draw();

	}
	m_window->SwapBuffers();

	return 0;
}
