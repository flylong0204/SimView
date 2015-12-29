#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "Log.h"
#include "LogManage.h"

namespace SimView
{
	CLogManage::CLogManage(void)
		:m_pDefaultLog(NULL)
	{
	}


	CLogManage::~CLogManage(void)
	{
		// 遍历删除
		LogList::iterator itor = m_logs.begin();
		for (; m_logs.end() != itor; ++itor)
		{
			SIMVIEW_DELETE(itor->second);
		}

		m_logs.clear();
	}

	// 创建一个日志
	ILog* CLogManage::CreateLog(const SVString& logFileName, const bool bDefaultLog/* = false*/, \
		const bool bDebugOut /*= true*/, const bool bSupperFile /*= false*/)
	{
		SIMVIEW_LOCK_AUTO_METEX

		// 创建一个日志实例
		ILog* pINewLog = new CLog(logFileName, bDebugOut, bSupperFile);

		// 判断是否含有默认的
		if (NULL == m_pDefaultLog || bDefaultLog)
		{
			m_pDefaultLog = pINewLog;
		}

		// 放入列表中
		m_logs.insert(LogList::value_type(logFileName, pINewLog));
		return (pINewLog);
	}

	// 获得默认的日志对象
	ILog* CLogManage::GetDefaultLog(void) const
	{
		return (m_pDefaultLog);
	}

	// 设置默认的日志对象
	ILog* CLogManage::SetDefaultLog(const ILog* pINewLog)
	{
		SIMVIEW_LOCK_AUTO_METEX

		// 设置新的值
		ILog* pIOldLog = m_pDefaultLog;
		m_pDefaultLog = const_cast<ILog*>(pINewLog);
		return (pIOldLog);
	}

	// 根据日志名获得日志对象
	ILog* CLogManage::GetLog(const SVString& strLogName)
	{
		// 上锁
		SIMVIEW_LOCK_AUTO_METEX

		//遍历
		LogList::const_iterator cstItor = m_logs.find(strLogName);

		if (m_logs.end() != cstItor)
		{
			return (cstItor->second);
		}
		else
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALIDPARAMS, "Log not found", "ILogManage::GetLog");
		}
		
		return (NULL);
	}

	// 根据名称删除
	void CLogManage::DestoryLog(const SVString& strLogName)
	{
		// 查询
		LogList::iterator itor = m_logs.find(strLogName);
		if (m_logs.end() == itor)
		{
			return;
		}

		// 判断默认日志是否和当前相同
		if (m_pDefaultLog == itor->second)
		{
			m_pDefaultLog = NULL;
		}

		SIMVIEW_DELETE(itor->second);
		m_logs.erase(itor);
	}

	// 直接删除日志对象
	void CLogManage::DestoryLog(ILog* pILog)
	{
		DestoryLog(pILog->GetName());
	}

	// 写入日志
	void CLogManage::RecordLog(const SVString& strLog, const ILog::LogLevel logLevel /*= ILog::DEBUG_LEVE*/, \
		const bool maskDebug /*= false*/)
	{
		// 线程安全
		SIMVIEW_LOCK_AUTO_METEX

		// 判断默认是否为空
		if (NULL == m_pDefaultLog)
		{
			return;
		}

		// 记录日志
		m_pDefaultLog->Log(strLog, logLevel, maskDebug);
	}

	// 设置默认日志等级
	void CLogManage::SetLogLevel(const ILog::LogLevel logLevel)
	{
		// 线程安全
		SIMVIEW_LOCK_AUTO_METEX

			// 判断默认是否为空
		if (NULL == m_pDefaultLog)
		{
			return;
		}

		// 记录日志
		m_pDefaultLog->SetLogLevel(logLevel);
	}



}