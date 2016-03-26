/**************************************************
outher: LJ
time: 2015-10-23
use: ��־�ӿ�
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
			DEBUG_LEVE = 0, // ���Լ���
			INFO_LEVE = 1, // �ڵ��Թ�������Ҫ�õ�����Ϣ����
			WARA_LEVE = 2, // ������Ϣ����
			ERROR_LEVE = 3, // ���󼶱�
			OFF_LEVE = 4 // ���󼶱� �ر����еļ���
		};

	public:
		// ��������
		virtual ~ILog(void) { }
		// �������
		virtual const SVString& GetName(void) const = 0;
		// ��¼��־
		virtual void Log(const SVString& log, const LogLevel logLevel = DEBUG_LEVE, const bool bDebug = true) = 0;
		// �����Ƿ�����ʱ���ǩ
		virtual void SetTimeTipEnable(bool bTimeTip) = 0;
		// �����ʱ���ǩ
		virtual bool GetTimeTipEnable(void) const = 0;
		// �����Ƿ��ڿ���̨���
		virtual void SetDebugOutputEnable(const bool bEnable) = 0;
		// ����Ƿ��ڿ���̨���
		virtual bool GetDebugOutputEnable(void) const = 0;
		// ���õȼ�
		virtual void SetLogLevel(const LogLevel logLevel) = 0;
		// ��õȼ�
		virtual ILog::LogLevel GetLogLevel(void) const = 0;

	};
}

#endif //  _PUBLICE_ILOG_H_