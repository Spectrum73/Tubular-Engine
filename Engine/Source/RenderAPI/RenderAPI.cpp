#include "Engine.h"

#include "DirectX12/DXGI/DXGIFactory.h"
#include "DirectX12/DXGI/DXGIAdapter.h"
#include "DirectX12/Base/D12Device.h"

#include "RenderAPI.h"
#include <sstream>



RenderAPI::~RenderAPI()
{
}

VOID RenderAPI::Initialise(HWND hwnd)
{
	/* Select Adapter and Create Device */
	DXGIFactory factory;
	DXGIAdapter adapter = factory.GetAdapter();

	DXGI_ADAPTER_DESC desc;
	adapter->GetDesc(&desc);

	// Output the chosen adapter
	Logger::PrintDebugSeparator();
	Logger::PrintLog(L"Device - ");
	Logger::PrintLog(desc.Description);
	Logger::PrintLog("\n");
	Logger::PrintDebugSeparator();

	mDevice.Init(adapter.Get());
	mDevice->SetName(L"Main Virtual Device");

	/* Create Direct Command Queue */
	 
	/* Create Swap Chain (2 backbuffers) */
	 
	/* Create a Fence */
	 
	/* Create FenceValues for synchronisation */
	 
	/* Create a Descriptor Heap */
	 
	/* Create Render Target View descriptors for each backbuffer */
}