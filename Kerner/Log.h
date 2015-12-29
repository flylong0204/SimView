/*autor： LJ				                  */
/*time: 2015-10-20		                      */
/*use:	the log header                  */
/*use:				                          */
/**********************************************/

#ifndef _LOG_H_
#define _LOG_H_

#pragma once

namespace SimView
{
	class CLog : public ILog
	{
	public:

		// 全局锁
		SIMVIEW_AUTO_MUTEX

	public:
		// 构造函数
		explicit CLog(const SVString& logFileName, const bool bDebugOut = true,\
			const bool bSupperFile = false);
		// 析构函数
		virtual ~CLog(void);

	public:
		// 获得名称
		virtual const SVString& GetName(void) const { return (m_strLogName); }
		// 记录日志
		virtual void Log(const SVString& log, const ILog::LogLevel logLevel = ILog::DEBUG_LEVE, const bool bDebug = true);
		// 设置是否贴上时间标签
		virtual void SetTimeTipEnable(bool bTimeTip);
		// 获得是时间标签
		virtual inline bool GetTimeTipEnable(void) const { return (m_bTimeStamp); }
		// 设置是否在控制台输出
		virtual void SetDebugOutputEnable(const bool bEnable);
		// 获得是否在控制台输出
		virtual inline bool GetDebugOutputEnable(void) const { return (m_bDebug); }
		// 设置等级
		virtual void SetLogLevel(const ILog::LogLevel logLevel);
		// 获得等级
		virtual inline ILog::LogLevel GetLogLevel(void) const { return (m_logLevel); }

	protected:
		
	private:
		std::ofstream m_log; // 写入到文件
		ILog::LogLevel m_logLevel; // 日志级别
		bool m_bDebug; // 是否debug输出
		bool m_bFile; // 是否支持文件输出
		bool m_bTimeStamp; // 是否加上时间标签
		SVString m_strLogName; // 文件名称
	};
}
#endif // !_LOG_H_
