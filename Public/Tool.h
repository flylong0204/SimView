/**************************************************
outher: LJ
time: 2015-10-23
use: һЩ���ߺ�ͷ�ļ�
from: 
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_TOOL_H_
#define _PUBLIC_TOOL_H_

// ȡ��4251����
#pragma warning(disable: 4251) // string ���ͷ���privete���µĵ�������

#if defined(_DEBUG) || defined(DEBUG)

#define SIMVIEW_DELETE(p)  if (NULL != p) delete p; p = NULL;
#define SIMVIEW_DELETE_ARRAY(p) if(NULL != p) delete[] p; p = NULL;

#elif

#define SIMVIEW_DELETE(p)  if (NULL != p) delete p;
#define SIMVIEW_DELETE_ARRAY(p) if(NULL != p) delete[] p;

#endif // _DEBUG


	//////////////////////////////////////////////////////////////////////////
#if (SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32)

#define SIMVIEW_EXPORT _declspec(dllexport)
#define SIMVIEW_IMPORT _declspec(dllimport)

#elif SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_LINUX

#define SIMVIEW_EXPORT __attribute__((visibility("default")))
#define SIMVIEW_IMPORT __attribute__((visibility("default")))

#endif // SIMVIEW_PLATFORM

#ifdef __cplusplus
#define SIMVIEW_EXTERN_C extern "C"
#else
#define SIMVIEW_EXTERN_C
#endif // _cplusplus

	// ���ĵ��뵼���ؼ���
#ifdef SIMVIEW_KERNERLIB
#define KERNER_DLL SIMVIEW_EXPORT
#else
#define KERNER_DLL SIMVIEW_IMPORT

#endif

//////////////////////////////////////////////////////////////////////////
#endif //  _PUBLIC_TOOL_H_