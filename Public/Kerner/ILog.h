/**************************************************
outher: LJ
time: 2015-10-23
use: 日志接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_ILOG_H_
#define _PUBLICE_ILOG_H_

namespace SimView
{
	class KERNER_EXPORT ILog
	{
	public:
		enum LogLevel
		{
			DEBUG_LEVE = 0, // 调试级别
			INFO_LEVE = 1, // 在调试过程中需要用到的信息级别
			WARA_LEVE = 2, // 警告信息级别
			ERROR_LEVE = 3, // 错误级别
			OFF_LEVE = 4 // 错误级别， 关闭所有的级别
		};

	public:
		// 析构函数
		virtual ~ILog(void) { }
		// 获得名称
		virtual const SVString& GetName(void) const = 0;
		// 记录日志
		virtual void Log(const SVString& log, const LogLevel logLevel = DEBUG_LEVE, const bool bDebug = true) = 0;
		// 设置是否贴上时间标签
		virtual void SetTimeTipEnable(bool bTimeTip) = 0;
		// 获得是时间标签
		virtual bool GetTimeTipEnable(void) const = 0;
		// 设置是否在控制台输出
		virtual void SetDebugOutputEnable(const bool bEnable) = 0;
		// 获得是否在控制台输出
		virtual bool GetDebugOutputEnable(void) const = 0;
		// 设置等级
		virtual void SetLogLevel(const LogLevel logLevel) = 0;
		// 获得等级
		virtual ILog::LogLevel GetLogLevel(void) const = 0;

	};
}

#endif //  _PUBLICE_ILOG_H_