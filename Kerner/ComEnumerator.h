/**************************************************
outher: LJ
time: 2015-10-25
use: ���ö��ֵ
from:
chanage:
change outher :
**************************************************/

#ifndef _COMENUMERATOR_H_
#define _COMENUMERATOR_H_

#pragma once

namespace SimView
{
	class CComEnumerator : public CSingleton<CComEnumerator>
	{
	public:
		// ���캯��
		explicit CComEnumerator(void);
		// ��������
		virtual ~CComEnumerator(void);

	public:
		// ��ӹ�������
		void AddFactory(IComBaseFactory* pIFactory);
		// �Ƴ���������
		void RemoveFactory(IComBaseFactory* pIFactory);
		// ����ʵ��
		IComFaceBase* CreateComInstance(const SVString& strTypeName, const SVString& strName);
		// ���ʵ��
		IComFaceBase* GetComInstance(const SVString& strName) const;
		// �Ƿ���ڵ�ǰ���
		bool HasComInstance(const SVString& strName) const;
		// ж�����в��
		void ShutAll(void);

	private:
		typedef std::map<SVString, IComFaceBase*> ListInstaces; // ʵ������
		typedef std::list<IComBaseFactory*> ListFactorys; // ��������
		typedef std::vector<const ComFaceBaseData*> ListComDatas; // ��������

		ListInstaces m_listInstances; // ʵ����󼯺�
		ListFactorys m_listFactorys; // �������󼯺�
		ListComDatas m_listComData; // ���ݹ�������

	};
}

#endif // !_COMENUMERATOR_H_