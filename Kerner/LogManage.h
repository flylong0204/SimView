/**************************************************
outher: LJ
time: 2015-10-24
use: 日志管理类负责获得默认日志和创建日志
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
		// 创建一个日志
		virtual ILog* CreateLog(const SVString& logFileName, const bool bDefaultLog = false, \
			const bool bDebugOut = true, const bool bSupperFile = false);
		// 获得默认的日志对象
		virtual ILog* GetDefaultLog(void) const;
		// 设置默认的日志对象
		virtual ILog* SetDefaultLog(const ILog* pINewLog);
		// 根据日志名获得日志对象
		virtual ILog* GetLog(const SVString& strLogName);
		// 根据名称删除
		virtual void DestoryLog(const SVString& strLogName);
		// 直接删除日志对象
		virtual void DestoryLog(ILog* pILog);
		// 写入日志
		virtual void RecordLog(const SVString& strLog, const ILog::LogLevel logLevel = ILog::DEBUG_LEVE, \
			const bool maskDebug = false);
		// 设置默认日志等级
		virtual void SetLogLevel(const ILog::LogLevel logLevel);
	private:
		// 链表类型 用于内部
		typedef std::map<SVString, ILog*> LogList;

	private:
		SIMVIEW_AUTO_MUTEX // 用于默认锁

		ILog* m_pDefaultLog; // 默认日志 系统创建事会自动创建
		LogList m_logs; //所有的日志链表

	};
}


#endif // _LOGMANAGE_H_