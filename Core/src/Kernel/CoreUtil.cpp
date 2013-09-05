#include "Core/SkyEngine.h"
#include "Core/CoreUtil.h"
#include <Windows.h>

std::wstring& Convert( std::wstring & strDest, std::string const & strSrc ){
	int const wcs_len = MultiByteToWideChar( CP_ACP, 0, strSrc.c_str(), strSrc.size(), 0, 0 );
	std::vector<wchar_t> tmp(wcs_len+1);
	MultiByteToWideChar( CP_ACP, 0, strSrc.c_str(), strSrc.size(), &tmp[0], wcs_len );

	strDest.assign( tmp.begin(), tmp.end()-1 );
	return strDest;
}