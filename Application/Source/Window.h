#pragma once

#include "pch.h"

class Window
{

private:
	WCHAR		WindowClass[MAX_NAME_STRING];
	WCHAR		WindowTitle[MAX_NAME_STRING];

	INT			WindowWidth;
	INT			WindowHeight;

	HICON		hIcon;

	HWND		hWnd;

	VOID InitialiseVariables();
	VOID CreateWindowClass();
	INT InitialiseWindow();
public:
	INT Initialise();
	HWND GetHWND();
public:
	Window();
	~Window();
};

LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);