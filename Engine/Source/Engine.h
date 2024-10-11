#pragma once

#ifdef WIN32

#include <Windows.h>

#endif

#include <iostream>

#ifdef BUILD_DLL
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif

// DirectX headers
#include <d3d12.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>

// Compiled lib files for d12

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxguid.lib")

#include "Common/Logger.h"
#include "Common/Time.h"
#include "Common/Helper.h"