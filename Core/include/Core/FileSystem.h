#pragma once
#include "Core/SkyEngine.h"

namespace SkyFileSystem{
	bool SKYENGINE_CORE_API exists( std::string const & name );
	uint64_t SKYENGINE_CORE_API last_write_time( std::string const & name );
};