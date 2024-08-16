#pragma once

#include <string>
#include <iostream>
#include <GLFW/glfw3.h>


struct GLFWwindow;

class D3D11 ;

class Window
{
public:

    Window(const std::string& title);
    virtual ~Window();
   // void Run();
    void Run();

    D3D11* TESTD3D = nullptr; 

protected:

    virtual void Cleanup();
    virtual bool Initialize();


    virtual bool Load() = 0;
    virtual void Render() = 0;
    virtual void Update() = 0;

private:

    GLFWwindow* _window = nullptr;
    int32_t _width = 0;
    int32_t _height = 0;

    std::string WindowTitle;
   

public :

    __forceinline int32_t GetWindowWidth()  { return _width; }
    __forceinline int32_t GetWindowHeight() { return _height; }
    __forceinline GLFWwindow* GetWindow() { return _window; }
};