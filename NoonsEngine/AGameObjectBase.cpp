#include "AGameObjectBase.h"

AGameObject::AGameObject(AWindowBase* window, Shape* shape, const char* vert, const char* frag)
    :m_transform()
    , m_shader(window, vert, frag)
    , m_shape(shape)
    
{

    Material mat = { 0.6f, 0.6f, 0.2f, 0.6f, 0.6f, 0.2f, 0.3f, 0.3f, 0.3f, 30.0f };
    m_material = new Uniform<Material>(&mat, 1);


}

AGameObject::~AGameObject()
{
}

int AGameObject::DrawObject(float const* Lpos, float const* Lamb, float const* Ldiff)
{
    const float* pos = m_transform.GetPosition();
    Matrix translate(Matrix::Translate(*pos, *(pos + 1), *(pos + 2)));


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

	m_shader.SetUniformMatrix4("projection", projection.data());
	m_shader.SetUniformMatrix4("modelview", modelView.data());
	m_shader.SetUniformMatrix3("normalMatrix", normalMatrix);
	for (int i = 0; i < Lcount; ++i) {
		m_shader.SetUniform4f("Lpos", (view * Lpos[i]).data());

	}
	glUniform3fv(m_LambLoc, Lcount, Lamb);
	glUniform3fv(m_LdiffLoc, Lcount, Ldiff);
	glUniform3fv(m_LspecLoc, Lcount, Lspec);




    m_shader.UseShader();

    m_material->Select(0,0);
    m_shape->Draw();
    return 0;
}
, m_program(loadProgram("pointWithNormal.vert", "pointWithNormal.frag"))
, m_modelviewLoc(glGetUniformLocation(m_program, "modelview"))
, m_projectionLoc(glGetUniformLocation(m_program, "projection"))
, m_normalMatrixLoc(glGetUniformLocation(m_program, "normalMatrix"))
, m_LposLoc(glGetUniformLocation(m_program, "Lpos"))
, m_LambLoc(glGetUniformLocation(m_program, "Lamb"))
, m_LdiffLoc(glGetUniformLocation(m_program, "Ldiff"))
, m_LspecLoc(glGetUniformLocation(m_program, "Lspec"))
, m_materialLoc(glGetUniformBlockIndex(m_program, "Material"))

