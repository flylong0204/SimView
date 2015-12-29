/**************************************************
outher: LJ
time: 2015-10-24
use: ��־�����ฺ����Ĭ����־�ʹ�����־
from: orge
chanage:
change outher :
**************************************************/

#ifndef _LOGMANAGE_H_
#define _LOGMANAGE_H_

#pragma once

namespace SimView
{
	class CLogManage : public ILogManage
	{
	public:
		explicit CLogManage(void);
		virtual ~CLogManage(void);

	public:
		// ����һ����־
		virtual ILog* CreateLog(const SVString& logFileName, const bool bDefaultLog = false, \
			const bool bDebugOut = true, const bool bSupperFile = false);
		// ���Ĭ�ϵ���־����
		virtual ILog* GetDefaultLog(void) const;
		// ����Ĭ�ϵ���־����
		virtual ILog* SetDefaultLog(const ILog* pINewLog);
		// ������־�������־����
		virtual ILog* GetLog(const SVString& strLogName);
		// ��������ɾ��
		virtual void DestoryLog(const SVString& strLogName);
		// ֱ��ɾ����־����
		virtual void DestoryLog(ILog* pILog);
		// д����־
		virtual void RecordLog(const SVString& strLog, const ILog::LogLevel logLevel = ILog::DEBUG_LEVE, \
			const bool maskDebug = false);
		// ����Ĭ����־�ȼ�
		virtual void SetLogLevel(const ILog::LogLevel logLevel);
	private:
		// �������� �����ڲ�
		typedef std::map<SVString, ILog*> LogList;

	private:
		SIMVIEW_AUTO_MUTEX // ����Ĭ����

		ILog* m_pDefaultLog; // Ĭ����־ ϵͳ�����»��Զ�����
		LogList m_logs; //���е���־����

	};
}


#endif // _LOGMANAGE_H_