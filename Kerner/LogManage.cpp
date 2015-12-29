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
		// ����ɾ��
		LogList::iterator itor = m_logs.begin();
		for (; m_logs.end() != itor; ++itor)
		{
			SIMVIEW_DELETE(itor->second);
		}

		m_logs.clear();
	}

	// ����һ����־
	ILog* CLogManage::CreateLog(const SVString& logFileName, const bool bDefaultLog/* = false*/, \
		const bool bDebugOut /*= true*/, const bool bSupperFile /*= false*/)
	{
		SIMVIEW_LOCK_AUTO_METEX

		// ����һ����־ʵ��
		ILog* pINewLog = new CLog(logFileName, bDebugOut, bSupperFile);

		// �ж��Ƿ���Ĭ�ϵ�
		if (NULL == m_pDefaultLog || bDefaultLog)
		{
			m_pDefaultLog = pINewLog;
		}

		// �����б���
		m_logs.insert(LogList::value_type(logFileName, pINewLog));
		return (pINewLog);
	}

	// ���Ĭ�ϵ���־����
	ILog* CLogManage::GetDefaultLog(void) const
	{
		return (m_pDefaultLog);
	}

	// ����Ĭ�ϵ���־����
	ILog* CLogManage::SetDefaultLog(const ILog* pINewLog)
	{
		SIMVIEW_LOCK_AUTO_METEX

		// �����µ�ֵ
		ILog* pIOldLog = m_pDefaultLog;
		m_pDefaultLog = const_cast<ILog*>(pINewLog);
		return (pIOldLog);
	}

	// ������־�������־����
	ILog* CLogManage::GetLog(const SVString& strLogName)
	{
		// ����
		SIMVIEW_LOCK_AUTO_METEX

		//����
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

	// ��������ɾ��
	void CLogManage::DestoryLog(const SVString& strLogName)
	{
		// ��ѯ
		LogList::iterator itor = m_logs.find(strLogName);
		if (m_logs.end() == itor)
		{
			return;
		}

		// �ж�Ĭ����־�Ƿ�͵�ǰ��ͬ
		if (m_pDefaultLog == itor->second)
		{
			m_pDefaultLog = NULL;
		}

		SIMVIEW_DELETE(itor->second);
		m_logs.erase(itor);
	}

	// ֱ��ɾ����־����
	void CLogManage::DestoryLog(ILog* pILog)
	{
		DestoryLog(pILog->GetName());
	}

	// д����־
	void CLogManage::RecordLog(const SVString& strLog, const ILog::LogLevel logLevel /*= ILog::DEBUG_LEVE*/, \
		const bool maskDebug /*= false*/)
	{
		// �̰߳�ȫ
		SIMVIEW_LOCK_AUTO_METEX

		// �ж�Ĭ���Ƿ�Ϊ��
		if (NULL == m_pDefaultLog)
		{
			return;
		}

		// ��¼��־
		m_pDefaultLog->Log(strLog, logLevel, maskDebug);
	}

	// ����Ĭ����־�ȼ�
	void CLogManage::SetLogLevel(const ILog::LogLevel logLevel)
	{
		// �̰߳�ȫ
		SIMVIEW_LOCK_AUTO_METEX

			// �ж�Ĭ���Ƿ�Ϊ��
		if (NULL == m_pDefaultLog)
		{
			return;
		}

		// ��¼��־
		m_pDefaultLog->SetLogLevel(logLevel);
	}



}