#include "pch.h"
#include "Window.h"

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_DESTROY:
			Logger::PrintLog(L"Closed\n");
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}

VOID Window::InitialiseVariables()
{
	/* Initialise Global Variables */

	LoadString(HInstance(), IDS_PERSCENENAME, WindowTitle, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);
	WindowWidth = 1280;
	WindowHeight = 720;
	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON_BLACK));
}

VOID Window::CreateWindowClass()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	/* Customisations */

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
	wcex.hIcon = hIcon;
	wcex.hIconSm = hIcon;
	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();
	wcex.lpfnWndProc = WindowProcess;
	RegisterClassEx(&wcex);
}

/* Returns a value depending on success state:
	0 - Success
	1 - Window creation failure
*/
INT Window::InitialiseWindow()
{
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		// Shutdown window if an error occurs.
		MessageBox(0, L"Failed to Create Window.", 0, 0);
		return 1;
	}

	ShowWindow(hWnd, SW_SHOW);
	return 0;
}

INT Window::Initialise() 
{
	InitialiseVariables();

	CreateWindowClass();

	auto windowError = InitialiseWindow();
	if (windowError != 0)
		return windowError;

	return 0;
}

Window::Window()
{
	Initialise();
}

Window::~Window()
{

}