#pragma once

#include "DirectX12/Base/D12Device.h"

class ENGINE_API RenderAPI
{

public:
	RenderAPI() = default;
	~RenderAPI();

	VOID Initialise(HWND hwnd);

private:

	D12Device mDevice;
};