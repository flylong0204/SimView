/**************************************************
outher: LJ
time: 2015-10-24
use: 日志接口
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
		// 创建一个日志
		virtual ILog* CreateLog(const SVString& logFileName, const bool bDefaultLog = false, \
			const bool bDebugOut = true, const bool bSupperFile = false) = 0;
		// 获得默认的日志对象
		virtual ILog* GetDefaultLog(void) const = 0;
		// 设置默认的日志对象
		virtual ILog* SetDefaultLog(const ILog* pINewLog) = 0;
		// 根据日志名获得日志对象
		virtual ILog* GetLog(const SVString& strLogName) = 0;
		// 根据名称删除
		virtual void DestoryLog(const SVString& strLogName) = 0;
		// 直接删除日志对象
		virtual void DestoryLog(ILog* pILog) = 0;
		// 写入日志
		virtual void RecordLog(const SVString& strLog, const ILog::LogLevel logLevel = ILog::DEBUG_LEVE, \
			const bool maskDebug = false) = 0;
		// 设置默认日志等级
		virtual void SetLogLevel(const ILog::LogLevel logLevel) = 0;
	};
}

#endif // _PUBLICE_ILOGMANAGE_H_