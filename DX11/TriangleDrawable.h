#pragma once
// TriangleDrawable.h
#pragma once
#include "Drawable.h"
#include <d3d11.h>
#include <vector>
#include "Window.h"
#include "VertexBuffer.h"
#include "InputLayout.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include <d3dcompiler.h>
#include <wrl/client.h>
#include <DirectXMath.h>
#include "ConstantBuffer.h"

class TriangleDrawable : public Drawable {

public:
    TriangleDrawable(ID3D11Device* device, Window* windowContextHolder);

    virtual void Draw(ID3D11DeviceContext* context, ID3D11Device* device , Window* windowApp, float updateRotation, float UpdateXp, float UpdateYp, float UpdateZp) override;

};
