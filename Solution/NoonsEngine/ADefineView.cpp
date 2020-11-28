#include "ADefineView.h"

Noon::NoonEngineCore::ADefineView::ADefineView(AWindowBase* const window)
	:m_window(window)
{
}

Noon::NoonEngineCore::ADefineView::~ADefineView()
{
	delete m_window;
}

void Noon::NoonEngineCore::ADefineView::ChangeWindow(AWindowBase* window)
{
	m_window = window;
}

bool Noon::NoonEngineCore::ADefineView::ShouldOpenWindow() const
{
	return (*m_window).operator bool();
}
