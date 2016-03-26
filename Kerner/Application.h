/**************************************************
outher: LJ
time: 2015-10-24
use: ������� 
from:
chanage:
change outher :
**************************************************/

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#pragma once

namespace SimView
{
	class CComEnumerator;

	class CApplication : public IApplication
	{
	public:
		// ���캯��
		explicit CApplication(void);
		// ��������
		virtual ~CApplication(void);

	public:
		// ����guid ÿ�λ�ö����µ�ֵ
		virtual long_l GenerateGuid(void);
		// ����������
		virtual IAttributeItem* CreateAttributeItem(IAttribute* pIAttribute, const SVString& strItemName, const SVString& strText, const SVString& strUntil, \
			const Variant& var, const Contrl ct = CTRL_SPINBOX);
		// ���������ļ�������
		virtual IConfigFileUtil* CreateConfigFileUtil(void);
		// ��ÿ�ִ�г���·��
		virtual SVString GetModulePath(void) const;

	public:
		// ���ÿ�ִ�г���·��
		void SetModuleDir(const SVString& strModuleDir);

	protected:
		// ��ʼ��
		void Init(void);

	private:
		ILogManage* m_pILogManage; // ��־����
		IPluginManage* m_pIPluginManage; // �������
		IDynLibManage* m_pIDynLibManage; // ��������
		CComEnumerator* m_pComEnumerator; // ʵ�����

		SVString m_strModuleDir; // ��ִ�г�������·��
	};

}
#endif // !_APPLICATION_H_
