#define SIMVIEW_KERNERLIB

#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32
#include <windows.h>
#endif

#include "../Public/Kerner/Kerner.h"

namespace SimView
{
	CDynamicLib::CDynamicLib(const SVString& strName):
		m_strName(strName),
		m_hInsLib(NULL)
	{
	}

	CDynamicLib::CDynamicLib(void) :
		m_strName(""),
		m_hInsLib(NULL)
	{

	}


	CDynamicLib::~CDynamicLib()
	{
	}

	// 获得名称
	const SVString& CDynamicLib::GetName(void) const
	{
		return (m_strName);
	}

	// 载入动态库
	bool CDynamicLib::Load(const SVString& pszLibName)
	{
		ILogManage::GetSingleton().RecordLog("加载动态库" + pszLibName);

		SVString strName = pszLibName;
		m_strName = pszLibName;
#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_LINUX || SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_NACL
		// dlopen() does not add .so to the filename, like windows does for .dll
		if (strName.find(".so") == SVString::npos)
			pszLibName += ".so";
#elif SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_APPLE
		// dlopen() does not add .dylib to the filename, like windows does for .dll
		if (strName.substr(strName.length() - 6, 6) != ".dylib")
			strName += ".dylib";
#elif SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32
		// Although LoadLibraryEx will add .dll itself when you only specify the library name,
		// if you include a relative path then it does not. So, add it to be sure.
		if (strName.substr(strName.length() - 4, 4) != ".dll")
			strName += ".dll";
#endif
		m_hInsLib = (DYNLIB_HANDLE)DYNLIB_LOAD(strName.c_str());

		if (!m_hInsLib)
		{
			SIMVIEW_EXCEPT(
				CSVExpection::ERR_INTERNAL_ERROR, \
				"不能打开动态库" + m_strName + \
				". 系统错误码 " + GetLastError(), \
				"DynLib::load");
		}
		return (true);
	}

	// 载入动态库
	bool CDynamicLib::Load(void)
	{
		// 是否有默认的库名称和路径
		if (m_strName.empty())
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, \
				"不能打开动态库" + m_strName + \
				". 系统错误码 " + GetLastError(), \
				"DynLib::load");
			return (false);
		}
		// 开始导入库
		Load(m_strName);
		return (true);
	}

	// 卸载动态库
	void CDynamicLib::UnLoad(void)
	{
		// 记录日志
		ILogManage::GetSingleton().RecordLog("卸载动态库" + m_strName);

		if (DYNLIB_UNLOAD(m_hInsLib))
		{
			SIMVIEW_EXCEPT(
				CSVExpection::ERR_INTERNAL_ERROR, \
				"不能打开动态库" + m_strName + \
				". 系统错误码 " + GetLastError(), \
				"DynLib::UnLoad");
		}
	}

	// 获得动态库入口，如果没有找到 直接返回NULL
	void* CDynamicLib::GetSymbool(const SVString& strName) const throw()
	{
		return (void*)DYNLIB_GETSYM(m_hInsLib, strName.c_str());
	}

	// 获得导入最后错误
	SVString CDynamicLib::GetLastError(void) const
	{
#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32
		LPVOID lpMsgBuf;
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			::GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpMsgBuf,
			0,
			NULL
			);
		SVString ret = (SVChar*)lpMsgBuf;
		// Free the buffer.
		LocalFree(lpMsgBuf);
		return ret;
#elif SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_LINUX || SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_APPLE
		return String(dlerror());
#else
		return String("");
#endif

	}

}
