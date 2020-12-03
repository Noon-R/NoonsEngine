#pragma once

#include "AViewBase.h"

#include "imgui.h"
#include "imgui_internal.h"

class UITestView
	:public Noon::NoonEngineCore::AViewBase
{
public:
	UITestView(AWindowBase* const window);
	~UITestView();

	virtual int Init(AWindowBase* const window) override;

	virtual int Update(AWindowBase* const window) override;

	virtual int PreDraw(AWindowBase* const window) override;

	virtual int Draw(AWindowBase* const window) override;

	virtual int PostDraw(AWindowBase* const window) override;

private:

	ImGuiContext* m_uiContext;
	
	

};

