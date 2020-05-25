#pragma once

#include <iostream>

#include "WindowBase.h"


class ADefineView {

public :
	ADefineView(WindowBase* const window);
	virtual int Init() = 0;
	virtual int Update() = 0;
	virtual int Draw() = 0;

protected:

	WindowBase* const m_window;

};