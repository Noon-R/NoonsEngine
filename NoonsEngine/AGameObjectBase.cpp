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

int AGameObject::DrawObject(AWindowBase const * window, float const* Lpos, float const* Lamb, float const* Ldiff, float const* Lspec)
{
    const float* pos = m_transform.GetPosition();
    Matrix translate(Matrix::Translate(*pos, *(pos + 1), *(pos + 2)));


	const GLfloat* const size(window->GetSize());
	const GLfloat scale(window->GetScale() * 2.0f);
	const GLfloat fovy(window->GetScale() * 0.01f);
	const GLfloat aspect(size[0] / size[1]);

	const Matrix projection(Matrix::Perspective(fovy, aspect, 1.0f, 10.0f));
	const Matrix scaling(Matrix::Scale(scale / size[0], scale / size[1], 1.0f));


	const Matrix r(Matrix::Rotate(static_cast<GLfloat>(glfwGetTime()), 0.0f, 1.0f, 0.0f));
	//const Matrix model(translation * scaling);
	float const* position = m_transform.GetPosition();
	const Matrix model(Matrix::Translate(*position, *(position + 1), *(position + 2)));

	const Matrix view(Matrix::LookAt(
		0.0f , 2.0f , -5.0f ,
		0, 0, 0,
		0.0f, 1.0f, 0.0f
	));

	GLfloat normalMatrix[9];

	const Matrix modelView(view * model);

	modelView.GetNormalMatrix(normalMatrix);

	int Lcount = 2;

	m_shader.SetUniformMatrix4("projection", 1,projection.data());
	m_shader.SetUniformMatrix4("modelview", 1,modelView.data());
	m_shader.SetUniformMatrix3("normalMatrix", 1, normalMatrix);

	m_shader.SetUniform4f("Lpos", Lcount, Lpos);
	m_shader.SetUniform3f("Lamb", Lcount, Lamb);
	m_shader.SetUniform3f("Ldiff", Lcount, Ldiff);
	m_shader.SetUniform3f("Lspec", Lcount, Lspec);

    m_shader.UseShader();

    m_material->Select(0,0);
    m_shape->Draw();
    return 0;
}

// m_materialLoc(glGetUniformBlockIndex(m_program, "Material"))

