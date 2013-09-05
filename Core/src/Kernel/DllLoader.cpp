#include "Core/SkyEngine.h"
#include <Windows.h>
#include "Core/DllLoader.h"
#include "Core/ResLoader.h"

DllLoader::DllLoader()
	:dll_handle_(0)
{
}

DllLoader::~DllLoader(){
	this->Free();
}


bool DllLoader::Load( std::string const & dll_name ){
	std::string name = ResLoader::Instance().Locate( dll_name );
	if( name.empty() )
		return false;

	dll_handle_ = static_cast<void*>(::LoadLibraryA(name.c_str()));

	return dll_handle_ != 0;
}

void DllLoader::Free()
{
	if( dll_handle_ ){
		::FreeLibrary(static_cast<HMODULE>(dll_handle_));
	}
}

void* DllLoader::GetProcAddress( std::string const & proc_name ){
	return reinterpret_cast<void*>(::GetProcAddress(static_cast<HMODULE>(dll_handle_), proc_name.c_str()));
}