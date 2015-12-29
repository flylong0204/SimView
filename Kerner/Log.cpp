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

	// 析构函数
	CLog::~CLog()
	{
		SIMVIEW_LOCK_AUTO_METEX
		if (!m_bFile)
		{
			m_log.close();
		}
	}

	// 记录日志
	void CLog::Log(const SVString& log, const ILog::LogLevel logLevel /*= DEBUG_LEVE*/, const bool bDebug /*= true*/)
	{
		// 防止多线程 上锁
		SIMVIEW_LOCK_AUTO_METEX

		// 是否需要输出到调试
		if (m_bDebug)
		{
			std::cerr << log << std::endl;
#if defined (WIN32)
			OutputDebugString(log.c_str());
#endif
		}

		// 写入到文件中
		if (!m_bFile)
		{
			// 判断是否需要添加时间标签
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
			// 刷新文件
			m_log.flush();
		}
	}

	// 设置是否贴上时间标签
	void CLog::SetTimeTipEnable(bool bEnable)
	{
		SIMVIEW_LOCK_AUTO_METEX

		m_bTimeStamp = bEnable;
	}

	// 设置是否在控制台输出
	void CLog::SetDebugOutputEnable(const bool bEnable)
	{
		SIMVIEW_LOCK_AUTO_METEX

		m_bDebug = bEnable;
	}

	// 设置等级
	void CLog::SetLogLevel(const ILog::LogLevel logLevel)
	{
		SIMVIEW_LOCK_AUTO_METEX

		m_logLevel = logLevel;
	}

}
