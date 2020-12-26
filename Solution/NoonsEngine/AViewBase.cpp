#include "AViewBase.h"


Noon::NoonEngineCore::AViewBase::AViewBase(AWindowBase* const window)
	:m_window(window)
{
}

Noon::NoonEngineCore::AViewBase::~AViewBase()
{
	delete m_window;
}

bool Noon::NoonEngineCore::AViewBase::IsCloseWindow()
{
	return !(*m_window);
}

