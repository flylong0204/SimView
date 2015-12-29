/*autor�� LJ				                  */
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

		// ȫ����
		SIMVIEW_AUTO_MUTEX

	public:
		// ���캯��
		explicit CLog(const SVString& logFileName, const bool bDebugOut = true,\
			const bool bSupperFile = false);
		// ��������
		virtual ~CLog(void);

	public:
		// �������
		virtual const SVString& GetName(void) const { return (m_strLogName); }
		// ��¼��־
		virtual void Log(const SVString& log, const ILog::LogLevel logLevel = ILog::DEBUG_LEVE, const bool bDebug = true);
		// �����Ƿ�����ʱ���ǩ
		virtual void SetTimeTipEnable(bool bTimeTip);
		// �����ʱ���ǩ
		virtual inline bool GetTimeTipEnable(void) const { return (m_bTimeStamp); }
		// �����Ƿ��ڿ���̨���
		virtual void SetDebugOutputEnable(const bool bEnable);
		// ����Ƿ��ڿ���̨���
		virtual inline bool GetDebugOutputEnable(void) const { return (m_bDebug); }
		// ���õȼ�
		virtual void SetLogLevel(const ILog::LogLevel logLevel);
		// ��õȼ�
		virtual inline ILog::LogLevel GetLogLevel(void) const { return (m_logLevel); }

	protected:
		
	private:
		std::ofstream m_log; // д�뵽�ļ�
		ILog::LogLevel m_logLevel; // ��־����
		bool m_bDebug; // �Ƿ�debug���
		bool m_bFile; // �Ƿ�֧���ļ����
		bool m_bTimeStamp; // �Ƿ����ʱ���ǩ
		SVString m_strLogName; // �ļ�����
	};
}
#endif // !_LOG_H_
