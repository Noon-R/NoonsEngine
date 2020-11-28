#pragma once

#include<vector>
#include "ADefineView.h"

namespace Noon {
	namespace NoonEngineCore {

		class NoonEngineStateManager
		{
		public:
			NoonEngineStateManager();
			~NoonEngineStateManager();

			bool Init();
			void Update();
			bool IsExistWindow() const;

		private:

			std::vector<ADefineView*> m_engineViews;
			std::vector<ADefineView*> m_gameViews;

		};

	
	}
}