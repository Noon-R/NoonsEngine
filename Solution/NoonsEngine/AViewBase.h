#pragma once

#include <iostream>

#include "AWindowBase.h"


namespace Noon {
	namespace NoonEngineCore {
	
		class AViewBase {

		public:
			AViewBase(AWindowBase* const window);
			~AViewBase();

			bool IsCloseWindow();

			virtual int Init() = 0;
			virtual int Update() = 0;
			virtual int PreDraw() = 0;
			virtual int Draw() = 0;
			virtual int PostDraw() = 0;

		protected:
			
			AWindowBase* const m_window;

		};
	}
}