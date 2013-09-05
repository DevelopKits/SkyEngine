#include "Core/SkyEngine.h"
#include <Windows.h>
#include "Core/FileSystem.h"

namespace SkyFileSystem{
	bool exists( std::string const & name ){
		WIN32_FILE_ATTRIBUTE_DATA info;
		if( ::GetFileAttributesExA( name.c_str(), GetFileExInfoStandard, &info ) ){
			return true;
		}
		return false;
	}

	uint64_t last_write_time( std::string const & name ){
		WIN32_FILE_ATTRIBUTE_DATA info;
		if( ::GetFileAttributesExA( name.c_str(), GetFileExInfoStandard, &info ) ){
			return info.ftLastWriteTime.dwHighDateTime * 0x100000000ULL + info.ftLastWriteTime.dwLowDateTime;
		}
		return 0;
	}
}
