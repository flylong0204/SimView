/**********************************************/
/*autor： LJ				                  */
/*time: 2015-10-18		                      */
/*use:	Load the library	                  */
/*use:				                          */
/**********************************************/

#ifndef _DYNAMICELIB_H_
#define _DYNAMICELIB_H_

#pragma once

#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32
#    define DYNLIB_HANDLE hInstance
#    define DYNLIB_LOAD( a ) LoadLibraryEx( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#    define DYNLIB_GETSYM( a, b ) GetProcAddress( a, b )
#    define DYNLIB_UNLOAD( a ) !FreeLibrary( a )

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#elif SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_LINUX || SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_ANDROID || SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_NACL
#    define DYNLIB_HANDLE void*
#    define DYNLIB_LOAD( a ) dlopen( a, RTLD_LAZY | RTLD_GLOBAL)
#    define DYNLIB_GETSYM( a, b ) dlsym( a, b )
#    define DYNLIB_UNLOAD( a ) dlclose( a )

#elif SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_APPLE || SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_APPLE_IOS
#    define DYNLIB_HANDLE void*
#    define DYNLIB_LOAD( a ) mac_loadDylib( a )
#    define DYNLIB_GETSYM( a, b ) dlsym( a, b )
#    define DYNLIB_UNLOAD( a ) dlclose( a )

#endif

namespace SimView
{
	class KERNER_DLL CDynamicLib
	{
	public:
		explicit CDynamicLib(const SVString& strName);
		explicit CDynamicLib(void);
		~CDynamicLib();

		// 获得名称
		const SVString& GetName(void) const;
		// 载入动态库
		bool Load(const SVString& pszLibName);
		// 载入动态库
		bool Load(void);
		// 卸载动态库
		void UnLoad(void);
		// 获得动态库入口，如果没有找到 直接返回NULL
		void* GetSymbool(const SVString& strName) const throw();

	protected:
		// 获得导入最后错误
		SVString GetLastError(void) const;

	private:
		SVString m_strName; // 对应名称
		DYNLIB_HANDLE m_hInsLib; // 动态库句柄
	};
}

#endif // _DYNAMICELIB_H_