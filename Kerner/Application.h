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

	protected:
		// ��ʼ��
		void Init(void);

	private:
		ILogManage* m_pILogManage; // ��־����
		IPluginManage* m_pIPluginManage; // �������
		IDynLibManage* m_pIDynLibManage; // ��������
		CComEnumerator* m_pComEnumerator; // ʵ�����
	};

}
#endif // !_APPLICATION_H_
