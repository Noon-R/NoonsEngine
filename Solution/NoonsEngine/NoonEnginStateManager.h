#pragma once

#include<vector>
#include "AViewBase.h"

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

			std::vector<AViewBase*> m_engineViews;
			std::vector<AViewBase*> m_gameViews;

			bool m_isLoop;

		};

	
	}
}