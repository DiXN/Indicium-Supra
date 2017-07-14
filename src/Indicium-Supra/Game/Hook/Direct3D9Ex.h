#pragma once
#include <d3dx9.h>
#include "Window.h"
#include <intarch.h>

namespace Direct3D9Hooking
{
	enum Direct3DDevice9ExFunctionOrdinals : short
	{
		SetConvolutionMonoKernel = 119,
		ComposeRects = 120,
		PresentEx = 121,
		GetGPUThreadPriority = 122,
		SetGPUThreadPriority = 123,
		WaitForVBlank = 124,
		CheckResourceResidency = 125,
		SetMaximumFrameLatency = 126,
		GetMaximumFrameLatency = 127,
		CheckDeviceState_ = 128,
		CreateRenderTargetEx = 129,
		CreateOffscreenPlainSurfaceEx = 130,
		CreateDepthStencilSurfaceEx = 131,
		ResetEx = 132,
		GetDisplayModeEx = 133,
	};

	class Direct3D9Ex
	{
		UINTX *vtable;
		Window *temp_window;
		IDirect3D9Ex *d3d9_ex;
		IDirect3DDevice9Ex *d3d9_device_ex;
	public:
		Direct3D9Ex();
		~Direct3D9Ex();
		static const int VTableElements = 134;

		bool GetVTableEx(UINTX *pVTable) const;
	};
}
