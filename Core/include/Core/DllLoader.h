#pragma once
#include <string>

class SKYENGINE_CORE_API DllLoader
{
public:
	DllLoader();
	virtual ~DllLoader();

	bool Load( std::string const & dll_name );
	void Free();

	void* GetProcAddress( std::string const & proc_name );

private:
	void* dll_handle_;
};