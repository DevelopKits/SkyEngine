#pragma once
#pragma warning(disable: 4251)		//关闭dllexort类中含有vector,string等非导出类的警告

#define	_CRT_SECURE_NO_DEPRECATE   //关闭VS安全版本的警告

#ifdef SKYENGINE_CORE_SOURCE
	#define SKYENGINE_CORE_API __declspec(dllexport)
#else
	#define SKYENGINE_CORE_API __declspec(dllimport)
#endif

#define SKYENGINE_STRINGIZE(X)	SKYENGINE_DO_STRINGIZE(X)
#define SKYENGINE_DO_STRINGIZE(X)	#X