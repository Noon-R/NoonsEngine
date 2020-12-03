#pragma once

#include <iostream>

#include "AWindowBase.h"


namespace Noon {
	namespace NoonEngineCore {
	
		class AViewBase {

		public:
			AViewBase(AWindowBase* const window);
			~AViewBase();

			virtual int Init(AWindowBase* const window) = 0;
			virtual int Update(AWindowBase* const window) = 0;
			virtual int PreDraw(AWindowBase* const window) = 0;
			virtual int Draw(AWindowBase* const window) = 0;
			virtual int PostDraw(AWindowBase* const window) = 0;

		protected:

		};
	}
}