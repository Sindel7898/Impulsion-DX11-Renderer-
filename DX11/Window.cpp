#include "Window.h"
#include"D3D11.h"

Window::Window(const std::string& title) :WindowTitle(title)
{
}


bool Window::Initialize()
{
    //glfw initialisation and window creation 

    if (!glfwInit())
    {
        std::cout << "GLFW: Unable to initialize\n";
        return false;
    }

    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);

    _width = static_cast<int32_t>(videoMode->width * 0.9);
    _height = static_cast<int32_t>(videoMode->height * 0.9f);

   
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    _window = glfwCreateWindow(_width, _height, WindowTitle.data(), nullptr, nullptr);

    
    if (_window == nullptr)
    {
        std::cout << "GLFW: Unable to create window\n";
        return false;
    }

    const int32_t windowLeft = videoMode->width / 2 - _width / 2;
    const int32_t windowTop = videoMode->height / 2 - _height / 2;

    glfwSetWindowPos(_window, windowLeft, windowTop);

    //create instance of  directx11
    d3d11 = new D3D11(this);

    //IMGI initialisation
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOther(_window, true);
    ImGui_ImplDX11_Init(d3d11->GetDevice(), d3d11->GetDeviceContext());
    return true;
}

float lastTime = 0.0;
float deltaTime = 0.0;

void Window::Run()
{

    if (!Initialize())
    {
        return;
    }
    
    float lastTime = 0.0;

    while (!glfwWindowShouldClose(_window))
    {
        glfwPollEvents();

        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        //Camera Update
        if(glfwGetMouseButton(_window, GLFW_MOUSE_BUTTON_RIGHT)){

            Camera::GetInstance().Update(deltaTime, GetWindow());
          
        }
        else
        {
            glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

        }


        d3d11->Update();
        d3d11->EndFrame();

    }
}


void Window::Cleanup()
{
    if (_window != nullptr)
    {
        glfwDestroyWindow(_window);
        _window = nullptr;
    }
    glfwTerminate();
}




Window::~Window()
{
    Cleanup();
}