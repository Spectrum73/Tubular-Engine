#pragma once
#include "Platform/WIN32/IApplication.h"

class Application : public IApplication
{
private:
	Window applicationWindow;
	RenderAPI renderer;
public:
	Application();
	~Application();

public:
	VOID Initialise();
	VOID Update();
};