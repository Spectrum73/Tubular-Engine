#pragma once

#include <string>

class ENGINE_API Logger
{
private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

public:
	Logger();
	~Logger();

	static VOID PrintLog(const WCHAR* fmt, ...);
	static VOID PrintLog(const std::wstring& fmt);
	static VOID PrintLog(const std::string fmt);
	static VOID PrintDebugSeparator();
};