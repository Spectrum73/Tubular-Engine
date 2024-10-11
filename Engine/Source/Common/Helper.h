#pragma once
#include <sstream>
#include <exception>

#define ENGINE_EVALUATE_HR(hr, error) if ((hr) != S_OK) { Logger::PrintLog((std::ostringstream() << "API Error:  " << error << " at file: " << __FILE__ << "\n").str()); }

#ifdef _DEBUG
#define ENGINE_ASSERT(exp) if (!(exp)) { Logger::PrintLog((std::ostringstream() << "\nCritical error in file: " << __FILE__ << "\n\n").str()); throw; }
#else
#define ENGINE_ASSERT(exp)
#endif
