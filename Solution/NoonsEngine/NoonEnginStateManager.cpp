#include "NoonEnginStateManager.h"

#include "UITestView.h"

Noon::NoonEngineCore::NoonEngineStateManager::NoonEngineStateManager()
	:m_engineViews()
	,m_gameViews()
{

	Init();
}

Noon::NoonEngineCore::NoonEngineStateManager::~NoonEngineStateManager()
{
}

bool Noon::NoonEngineCore::NoonEngineStateManager::Init()
{
	AWindowBase* window = new AWindowBase(1920, 1080, "Noon's Engine", NULL, NULL);
	if (window->GetWindow()) {
		UITestView* view01 = new UITestView(window);

		m_engineViews.push_back(view01);

		return true;
	}

	return false;
	
}

void Noon::NoonEngineCore::NoonEngineStateManager::Update()
{
	for(ADefineView* view : m_engineViews)
	{
		view->Update();
	}

	for (ADefineView* view : m_gameViews)
	{
		view->Update();
	}

	for (ADefineView* view : m_engineViews)
	{
		view->Draw();
	}

	for (ADefineView* view : m_gameViews)
	{
		view->Draw();
	}
}


bool Noon::NoonEngineCore::NoonEngineStateManager::IsExistWindow() const
{
	return !m_engineViews.empty() || !m_gameViews.empty();
}
