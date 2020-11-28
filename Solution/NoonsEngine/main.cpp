#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#include "NoonEnginStateManager.h"


int main() {

	

	Noon::NoonEngineCore::NoonEngineStateManager* MainManager = new Noon::NoonEngineCore::NoonEngineStateManager();

	while (MainManager->IsLoop()) {
		MainManager->CheckWindowState();
		MainManager->Update();
		MainManager->Draw();

		glfwPollEvents();
	}

	delete MainManager;
	glfwTerminate();
	return 0;

}