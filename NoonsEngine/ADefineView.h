#pragma once

#include <iostream>

#include "WindowBase.h"
#include "glShader.h"
#include "ShapeIndex.h"
#include "SolidShape.h"
#include "ShapeCreator.h"
#include "Texture.h"
#include "Uniform.h"
#include "Material.h"
#include "Vector.h"
#include "Matrix.h"

class ADefineView {

public :
	ADefineView(WindowBase* const window);
	virtual int Init() = 0;
	virtual int Update() = 0;
	virtual int Draw() = 0;

protected:

	WindowBase* const m_window;

};