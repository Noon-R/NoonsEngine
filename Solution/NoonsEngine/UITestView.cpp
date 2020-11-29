#include "UITestView.h"

UITestView::UITestView(AWindowBase* const window)
	:ADefineView(window)
    , m_uiContext(ImGui::CreateContext())
{
    
   
    
    // imgui init
    ImGui::SetCurrentContext(m_uiContext);
    
    ImGui_ImplGlfw_InitForOpenGL(m_window->GetWindow(), true);
    ImGui_ImplOpenGL3_Init();
    ImGui_ImplOpenGL3_CreateDeviceObjects();
    ImGui_ImplOpenGL3_CreateFontsTexture();
    
    

}

UITestView::~UITestView()
{
    ImGui::SetCurrentContext(m_uiContext);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext(m_uiContext);

}

int UITestView::Init()
{
    return 0;
}

int UITestView::Update()
{
   
    return 0;
}

int UITestView::Draw()
{

    m_window->SetWindowContext(); {

        glClearColor(0.2f, 0.3f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui::SetCurrentContext(m_uiContext);
        ImGui_ImplGlfw_SetCurrentWindow(m_window->GetWindow());
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        // gui
        {
            ImGui::Begin("Test Window");

            ImGui::Text("Hello, world %d", 123);

            if (ImGui::Button("OK")) {
                printf("Button\n");
            }

            static char buf[256] = "aaa";
            if (ImGui::InputText("string", buf, 256)) {
                printf("InputText\n");
            }

            static float f = 0.0f;
            if (ImGui::SliderFloat("float", &f, 0.0f, 1.0f)) {
                printf("SliderFloat\n");
            }
            ImGui::End();
        }

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    }
    m_window->SwapBuffers();
    return 0;
}
