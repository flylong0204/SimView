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

	// �������
	const SVString& CDynamicLib::GetName(void) const
	{
		return (m_strName);
	}

	// ���붯̬��
	bool CDynamicLib::Load(const SVString& pszLibName)
	{
		ILogManage::GetSingleton().RecordLog("���ض�̬��" + pszLibName);

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
				"���ܴ򿪶�̬��" + m_strName + \
				". ϵͳ������ " + GetLastError(), \
				"DynLib::load");
		}
		return (true);
	}

	// ���붯̬��
	bool CDynamicLib::Load(void)
	{
		// �Ƿ���Ĭ�ϵĿ����ƺ�·��
		if (m_strName.empty())
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, \
				"���ܴ򿪶�̬��" + m_strName + \
				". ϵͳ������ " + GetLastError(), \
				"DynLib::load");
			return (false);
		}
		// ��ʼ�����
		Load(m_strName);
		return (true);
	}

	// ж�ض�̬��
	void CDynamicLib::UnLoad(void)
	{
		// ��¼��־
		ILogManage::GetSingleton().RecordLog("ж�ض�̬��" + m_strName);

		if (DYNLIB_UNLOAD(m_hInsLib))
		{
			SIMVIEW_EXCEPT(
				CSVExpection::ERR_INTERNAL_ERROR, \
				"���ܴ򿪶�̬��" + m_strName + \
				". ϵͳ������ " + GetLastError(), \
				"DynLib::UnLoad");
		}
	}

	// ��ö�̬����ڣ����û���ҵ� ֱ�ӷ���NULL
	void* CDynamicLib::GetSymbool(const SVString& strName) const throw()
	{
		return (void*)DYNLIB_GETSYM(m_hInsLib, strName.c_str());
	}

	// ��õ���������
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
