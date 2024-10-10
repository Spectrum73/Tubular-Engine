#include "Engine.h"
#include <fstream>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{

}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
#ifdef _DEBUG
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt, args);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	OutputDebugString(buf);
#endif
}

VOID Logger::PrintLog(const std::wstring& fmt)
{
#ifdef _DEBUG
	const WCHAR* fmtChar = fmt.c_str();
	Logger::PrintLog(fmtChar);
#endif
}

VOID Logger::PrintDebugSeparator()
{
#ifdef _DEBUG
	OutputDebugStringW(L"\n------------------------------------------------------------------------------------\n\n");
#endif
}
