#include "ADefineView.h"

Noon::EngineCore::ADefineView::ADefineView(AWindowBase* const window)
	:m_window(window)
{
}

void Noon::EngineCore::ADefineView::ChangeWindow(AWindowBase* window)
{
	m_window = window;
}
