#include "ADefineView.h"

Noon::NoonEngineCore::ADefineView::ADefineView(AWindowBase* const window)
	:m_window(window)
{
}

void Noon::NoonEngineCore::ADefineView::ChangeWindow(AWindowBase* window)
{
	m_window = window;
}
