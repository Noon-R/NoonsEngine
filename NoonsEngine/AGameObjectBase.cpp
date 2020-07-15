#include "AGameObjectBase.h"

AGameObject::AGameObject(AWindowBase* window, const char* vert, const char* frag)
    :m_transform()
    , m_shader(window,vert,frag)
{
}

AGameObject::~AGameObject()
{
}


int AGameObject::DrawObject(){
    
    const float* pos = m_transform.GetPosition;
    Matrix translate(Matrix::Translate(*pos, *(pos+1), *(pos+2)));

    m_shader.UseShader();

}
