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

	virtual int Init() override;

	virtual int Update() override;

	virtual int PreDraw() override;

	virtual int Draw() override;

	virtual int PostDraw() override;

private:

	ImGuiContext* m_uiContext;
	
	

};

