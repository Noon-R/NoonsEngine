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
			void Draw();
			void CheckWindowState();

			bool IsExistWindow() const;
			bool IsLoop() const;

		private:

			std::vector<ADefineView*> m_engineViews;
			std::vector<ADefineView*> m_gameViews;

			bool m_isLoop;

		};

	
	}
}