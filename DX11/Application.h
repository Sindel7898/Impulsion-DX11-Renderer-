#pragma once
#include "Window.h"

class Application  final : public Window
{
public:
    Application(const std::string& title);


protected:

    bool Load() override;
    void Render() override;
    void Update() override;

};
