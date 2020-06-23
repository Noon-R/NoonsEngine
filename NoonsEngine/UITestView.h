#pragma once

#include "ADefineView.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class UITestView
	:public ADefineView
{
public:
	UITestView(AWindowBase* const window);
	~UITestView();

	virtual int Init();
	virtual int Update();
	virtual int Draw();

private:

};

