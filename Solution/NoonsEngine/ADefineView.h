#pragma once

#include <iostream>

#include "AWindowBase.h"
#include "glShader.h"
#include "ShapeIndex.h"
#include "SolidShape.h"
#include "ShapeCreator.h"
#include "Texture.h"
#include "Uniform.h"
#include "Material.h"
#include "Vector.h"
#include "Matrix.h"
#include "ModelLoader.h"

namespace Noon {
	namespace NoonEngineCore {
	
		class ADefineView {

		public:
			ADefineView(AWindowBase* window);

			void ChangeWindow(AWindowBase* window);

			virtual int Init() = 0;
			virtual int Update() = 0;
			virtual int Draw() = 0;

		protected:

			AWindowBase* m_window;

		};
	}
}