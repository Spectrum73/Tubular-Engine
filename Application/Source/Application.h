#pragma once
#include "Platform/WIN32/IApplication.h"
#include "Window.h"

class Application : public IApplication
{
private:
	Window applicationWindow;
public:
	Application();
	~Application();

public:
	VOID Initialise();
	VOID Update();
};