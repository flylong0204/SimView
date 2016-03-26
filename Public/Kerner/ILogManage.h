/**************************************************
outher: LJ
time: 2015-10-24
use: ��־�ӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_ILOGMANAGE_H_
#define _PUBLICE_ILOGMANAGE_H_

namespace SimView
{
	class KERNER_EXPORT ILogManage : public CSingleton<ILogManage>
	{
	public:
		virtual ~ILogManage(void) { }
		// ����һ����־
		virtual ILog* CreateLog(const SVString& logFileName, const bool bDefaultLog = false, \
			const bool bDebugOut = true, const bool bSupperFile = false) = 0;
		// ���Ĭ�ϵ���־����
		virtual ILog* GetDefaultLog(void) const = 0;
		// ����Ĭ�ϵ���־����
		virtual ILog* SetDefaultLog(const ILog* pINewLog) = 0;
		// ������־�������־����
		virtual ILog* GetLog(const SVString& strLogName) = 0;
		// ��������ɾ��
		virtual void DestoryLog(const SVString& strLogName) = 0;
		// ֱ��ɾ����־����
		virtual void DestoryLog(ILog* pILog) = 0;
		// д����־
		virtual void RecordLog(const SVString& strLog, const ILog::LogLevel logLevel = ILog::DEBUG_LEVE, \
			const bool maskDebug = false) = 0;
		// ����Ĭ����־�ȼ�
		virtual void SetLogLevel(const ILog::LogLevel logLevel) = 0;
	};
}

#endif // _PUBLICE_ILOGMANAGE_H_