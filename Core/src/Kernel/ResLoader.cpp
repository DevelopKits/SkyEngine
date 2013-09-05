#include "Core/SkyEngine.h"
#include <Windows.h>
#include <fstream>
#include "Core/ResLoader.h"
#include "Core/FileSystem.h"
#include "Core/CoreUtil.h"

ResLoader& ResLoader::Instance(){
	static ResLoader resLoader;
	return resLoader;
}

ResLoader::ResLoader(){
	char buf[MAX_PATH];
	GetModuleFileNameA( 0, buf, sizeof(buf) );

	this->AddPath(".");
}

void ResLoader::AddPath( std::string const & path ){
	if( ! SkyFileSystem::exists( path ) ){
		return;
	}
	
	std::string path_str = path;
	if( path_str[ path_str.length() - 1 ] != '/' ){
		path_str.push_back('/');
	}
	paths_.push_back( path_str );
}

std::string ResLoader::Locate( std::string const & name ){
	if( name[0] == '/' ){
		if( SkyFileSystem::exists( name ) ){
			return name;
		}
	}
	else{
		std::vector<std::string>::iterator iter;
		for( iter = paths_.begin(); iter != paths_.end(); ++iter ){
			std::string const res_name( *iter+name );
			if( SkyFileSystem::exists( res_name ) ){
				return res_name;
			}
		}
	}

	return "";
}

ResIdentifierPtr ResLoader::Open( std::string const & name ){
	if( name[0] == '/' ){
		if( SkyFileSystem::exists( name ) ){
			uint64_t time_stamp = SkyFileSystem::last_write_time( name );

			ResIdentifierPtr rs = CORE_NEW( ResIdentifier( name, time_stamp, CORE_NEW( std::ifstream( name.c_str(), std::ios_base::binary ) ) ));

			return rs;
		}
	}
	else{
		std::vector<std::string>::iterator iter;
		for( iter = paths_.begin(); iter != paths_.end(); ++iter ){
			std::string const res_name( *iter+name );
			if( SkyFileSystem::exists( res_name ) ){
				uint64_t time_stamp = SkyFileSystem::last_write_time( name );
					
				ResIdentifierPtr rs = CORE_NEW( ResIdentifier( name, time_stamp, CORE_NEW( std::ifstream( name.c_str(), std::ios_base::binary ) ) ));

				return rs;
			}
		}
	}	
	return NULL;
}

void ResLoader::Close( ResIdentifierPtr rs ){
	CORE_DELETE( rs->input_stream() );
	CORE_DELETE( rs );
}



