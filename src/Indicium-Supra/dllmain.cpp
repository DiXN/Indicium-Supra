#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3d9.lib")

#include "dllmain.h"

#include <Utils/Windows.h>
#include <Game/Game.h>

HANDLE g_hDllHandle = 0;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID)
{
	g_hDllHandle = hInstance;

	DisableThreadLibraryCalls((HMODULE) hInstance);

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		return CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(initGame), nullptr, 0, nullptr) > nullptr;
	case DLL_PROCESS_DETACH:
		{
			MH_DisableHook(MH_ALL_HOOKS);
			MH_Uninitialize();
		}
		break;
	};

	return TRUE;
}

