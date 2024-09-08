#pragma once
#include <vector>
#include <d3d11.h>
#include <memory>
#include "Bindable.h"
#include "IndexBuffer.h"
#include "Window.h"

class Drawable{
public:


	void Bind(ID3D11DeviceContext* context)
	{

		for (const auto& bindable : Bindables) {

			bindable->Bind(context);

		}
	}


	virtual void Draw(ID3D11DeviceContext* context, ID3D11Device* device, Window* windowApp) = 0;


	void AddBindable(std::shared_ptr<Bindable> bindable) {


		Bindables.push_back(std::move(bindable));

	}
private:

    std::vector<std::shared_ptr<Bindable>>  Bindables; 

};
