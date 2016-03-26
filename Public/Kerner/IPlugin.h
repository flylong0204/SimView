/**************************************************
outher: LJ
time: 2015-10-24
use: ���ϵͳͷ�ļ� 
from: ogre
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IPLUGIN_H_
#define _PUBLICE_IPLUGIN_H_

namespace SimView
{
	// ����汾��
	class CPluginVersion 
	{
	public:
		CPluginVersion(const int nMainV, const int nMinorV, const int nReviseV, \
			const int nDate) :
			m_nMainV(nMainV),
			m_nMinorV(nMinorV),
			m_nReviseV(nReviseV),
			m_nDate(nDate)
		{

		}

		// ������汾��
		virtual int MainVersion(void) const
		{
			return (m_nMainV);
		}

		// ��ôΰ汾��
		virtual int MinorVersion(void) const
		{
			return (m_nMinorV);
		}

		// ����޶��汾��
		virtual int ReviseVersion(void) const
		{
			return (m_nReviseV);
		}

		// ��ð汾����
		virtual int CreateDate(void) const
		{
			return (m_nDate);
		}

		// ��ð汾�ַ���
		virtual SVString GetVersion(void) const
		{
			SVChar szTmp[256];
			SVSprintf(szTmp, "%d.%d.%d.%d", m_nMainV, m_nMinorV, m_nReviseV, m_nDate);
			return szTmp;
		}

	private:
		int m_nMainV; // ���汾��
		int m_nMinorV; // �ΰ汾��
		int m_nReviseV; // �޶��汾��
		int m_nDate; // �޶�����
	};

	//////////////////////////////////////////////////////////////////////////

	// �������
	class KERNER_EXPORT IPlugin
	{
	public:
		// ��������
		virtual ~IPlugin(void) { }
		// ��ò������
		virtual const SVString& GetName(void) const = 0;
		// ��װ���
		virtual void Install(void) = 0;
		// ��ʼ�����
		virtual void Initialise(void) = 0;
		// ���ղ��
		virtual void ShutDown(void) = 0;
		// ж�ز��
		virtual void UnInstall(void) = 0;
		// ��ò���汾
		virtual CPluginVersion GetVersion(void) = 0;
	};
}

#endif // !_PUBLICE_IPLUGIN_H_
