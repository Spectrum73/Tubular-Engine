#include "Engine.h"

#include "IApplication.h"

extern IApplication* EntryApplication();

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	auto EntryApp = EntryApplication();

	Logger logger;
	EntryApp->Initialise();

	MSG msg{ 0 };
	while (msg.message != WM_QUIT)
	{
		// If there are window messages then process them.
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			EntryApp->Update();
		}
	}

	return 0;
}