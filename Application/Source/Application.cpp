#include "pch.h"
#include "Application.h"
#include "Platform/WIN32/WinEntry.h"

ENTRYAPP(Application)

Application::Application()
{
}

Application::~Application()
{
}

VOID Application::Initialise()
{
	Logger::PrintDebugSeparator();
	Logger::PrintLog(L"Application Started...\n");
	Logger::PrintDebugSeparator();
}

VOID Application::Update()
{
	std::wstring string = Time::GetTime();
	string.push_back('\n');
	Logger::PrintLog(string);
}

