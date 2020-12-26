#include "NoonEnginStateManager.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "UITestView.h"
#include "SampleGame.h"

Noon::NoonEngineCore::NoonEngineStateManager::NoonEngineStateManager()
	:m_engineViews()
	,m_gameViews()
	,m_isLoop(Init())
{
	

}

Noon::NoonEngineCore::NoonEngineStateManager::~NoonEngineStateManager()
{



}

bool Noon::NoonEngineCore::NoonEngineStateManager::Init()
{

	bool isComplete = false;

	//-----------------------------------OpenGl------------------------------------

	if (glfwInit() == GL_FALSE) {
		return false;
	}
	atexit(glfwTerminate);


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);



	//FloatingWindow
	//glfwWindowHint(GLFW_FLOATING, GL_TRUE);
	//No Frame
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);



	glfwSetTime(0.0);
	//------------------------------------------------------------------------------

	
	for (int i = 0; i < 3; i++) {

		AWindowBase* window = new AWindowBase(500, 500, "Noon's Engine", NULL, NULL);
		if (window->GetWindow()) {
			UITestView* view01 = new UITestView(window);

			m_engineViews.push_back(view01);

			isComplete = true;
		}
		else {
			isComplete = false;
		}
	}
	

	AWindowBase* window02 = new AWindowBase(1920, 1080, "Noon's Engine", NULL, NULL);
	if (window02->GetWindow()) {
		SampleGame* view01 = new SampleGame(window02);

		m_gameViews.push_back(view01);

		isComplete = true;
	}
	else {
		isComplete = false;
	}
	

	//BackCulling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//Depth
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);

	return isComplete;
	
}

void Noon::NoonEngineCore::NoonEngineStateManager::Update()
{

	for(AViewBase* view : m_engineViews)
	{
		view->Update();	
	}

	for (AViewBase* view : m_gameViews)
	{
		view->Update();
	}

}

void Noon::NoonEngineCore::NoonEngineStateManager::Draw()
{
	for (AViewBase* view : m_engineViews)
	{
		view->Draw();
	}

	for (AViewBase* view : m_gameViews)
	{
		view->Draw();
	}
	
}

void Noon::NoonEngineCore::NoonEngineStateManager::CheckWindowState()
{
	for (int i = 0; i < m_engineViews.size();)
	{
		std::cout << m_engineViews.size() << std::endl;
		
		if (m_engineViews[i]->IsCloseWindow()) {
			delete m_engineViews[i];
			m_engineViews.erase(m_engineViews.begin() + i);
		}
		else
		{
			++i;
		}
	}

	for (int i = 0; i < m_gameViews.size();)
	{
		std::cout << m_gameViews.size() << std::endl;
		if (m_gameViews[i]->IsCloseWindow()) {
			delete m_gameViews[i];
			m_gameViews.erase(m_gameViews.begin() + i);
		}
		else
		{
			++i;
		}
	}
}


bool Noon::NoonEngineCore::NoonEngineStateManager::IsExistWindow() const
{
	return !m_engineViews.empty() || !m_gameViews.empty();

	return true;
}

bool Noon::NoonEngineCore::NoonEngineStateManager::IsLoop() const
{
	return m_isLoop && IsExistWindow();
}
