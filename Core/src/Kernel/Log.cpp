#include "Core/SkyEngine.h"
#include <cstdio>
#include <cstdarg>
#include <iostream>
#include "Core/Log.h"

void LogInfo( char const *fmt, ... )
{
	va_list args;
	va_start( args, fmt );

	char buffer[1024];
	vsprintf(buffer, fmt, args );

	std::clog << "(INFO) SKYENGINE:" << buffer <<std::endl;
	va_end(args);
}

void LogWarn( char const *fmt, ... )
{
	va_list args;
	va_start( args, fmt );

	char buffer[1024];
	vsprintf(buffer, fmt, args );

	std::clog << "(WARN) SKYENGINE:" << buffer <<std::endl;
	va_end(args);
}

void LogError( char const *fmt, ... )
{
	va_list args;
	va_start( args, fmt );

	char buffer[1024];
	vsprintf(buffer, fmt, args );

	std::clog << "(ERROR) SKYENGINE:" << buffer <<std::endl;
	va_end(args);
}