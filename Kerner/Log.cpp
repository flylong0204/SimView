#define SIMVIEW_KERNERLIB

#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <iomanip>
#include "../Public/Kerner/Kerner.h"
#include "Log.h"

#if (SIMVIEW_PLATFORM == 1)
#include <windows.h>
#endif

namespace SimView
{
	CLog::CLog(const SVString& logFileName, const bool bDebugOut, const bool bSupperFile)
		:m_logLevel(ILog::DEBUG_LEVE),
		m_bDebug(bDebugOut),
		m_bFile(bSupperFile),
		m_bTimeStamp(true),
		m_strLogName(logFileName)
	{
		if (!m_bFile)
		{
			m_log.open(m_strLogName.c_str());
		}
	}

	// ��������
	CLog::~CLog()
	{
		SIMVIEW_LOCK_AUTO_METEX
		if (!m_bFile)
		{
			m_log.close();
		}
	}

	// ��¼��־
	void CLog::Log(const SVString& log, const ILog::LogLevel logLevel /*= DEBUG_LEVE*/, const bool bDebug /*= true*/)
	{
		// ��ֹ���߳� ����
		SIMVIEW_LOCK_AUTO_METEX

		// �Ƿ���Ҫ���������
		if (m_bDebug)
		{
			std::cerr << log << std::endl;
#if defined (WIN32)
			OutputDebugString(log.c_str());
#endif
		}

		// д�뵽�ļ���
		if (!m_bFile)
		{
			// �ж��Ƿ���Ҫ���ʱ���ǩ
			if (m_bTimeStamp)
			{
				struct tm *pTime;
				time_t ctTime; 
				time(&ctTime);
				pTime = localtime(&ctTime);
				m_log << std::setw(2) << std::setfill('0') << pTime->tm_hour
					<< ":" << std::setw(2) << std::setfill('0') << pTime->tm_min
					<< ":" << std::setw(2) << std::setfill('0') << pTime->tm_sec
					<< ": ";
			}

			m_log << log << std::endl;
			// ˢ���ļ�
			m_log.flush();
		}
	}

	// �����Ƿ�����ʱ���ǩ
	void CLog::SetTimeTipEnable(bool bEnable)
	{
		SIMVIEW_LOCK_AUTO_METEX

		m_bTimeStamp = bEnable;
	}

	// �����Ƿ��ڿ���̨���
	void CLog::SetDebugOutputEnable(const bool bEnable)
	{
		SIMVIEW_LOCK_AUTO_METEX

		m_bDebug = bEnable;
	}

	// ���õȼ�
	void CLog::SetLogLevel(const ILog::LogLevel logLevel)
	{
		SIMVIEW_LOCK_AUTO_METEX

		m_logLevel = logLevel;
	}

}
