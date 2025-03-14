// Bindable.h
#pragma once
#include <d3d11.h>
#include <wrl.h>
#include "MACROS.h"

class Bindable {
public:

    virtual void Bind(ID3D11DeviceContext* context) = 0;
    virtual ~Bindable() = default;
};
