#pragma once

#include <string>
#include "imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_dx11.h"

#include <GLFW/glfw3.h>


struct GLFWwindow;

class D3D11 ;

class Window
{
public:

    Window(const std::string& title);
     ~Window();
    void Run();



private:

 
    int32_t _width = 0;
    int32_t _height = 0;

    std::string WindowTitle;
   
    double mouseX;
    double mouseY;

    bool SetMouse = true;

    GLFWwindow* _window = nullptr;
    D3D11* d3d11 = nullptr;

    void Cleanup();
    bool Initialize();

public :

    __forceinline int32_t GetWindowWidth()  { return _width; }
    __forceinline int32_t GetWindowHeight() { return _height; }
    __forceinline GLFWwindow* GetWindow() { return _window; }
};