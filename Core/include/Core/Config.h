#pragma once
#pragma warning(disable: 4251)		//�ر�dllexort���к���vector,string�ȷǵ�����ľ���

#define	_CRT_SECURE_NO_DEPRECATE   //�ر�VS��ȫ�汾�ľ���

#ifdef SKYENGINE_CORE_SOURCE
	#define SKYENGINE_CORE_API __declspec(dllexport)
#else
	#define SKYENGINE_CORE_API __declspec(dllimport)
#endif

#define SKYENGINE_STRINGIZE(X)	SKYENGINE_DO_STRINGIZE(X)
#define SKYENGINE_DO_STRINGIZE(X)	#X