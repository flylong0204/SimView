/**************************************************
outher: LJ
time: 2016-03-15
use: ʵ�幤�������࣬ ����ʵ�幤��ʵ�����Ĺ���
from: 
chanage:
change outher :
**************************************************/

#pragma once

#include <vector>

namespace SimView
{
	class CEntityFactoryManager : public IEntityFactoryType
	{
	public:
		explicit CEntityFactoryManager(void);
		~CEntityFactoryManager();

	public:
		// ���·��
		virtual SVString GetPath(void) const;
		// ����·��
		virtual void SetPath(const SVString& strPath);
		// �������
		virtual const SVString GetType(void) const;
		// ��ù������� ��ʵ������
		virtual const SVString& GetInstanceName(void) const;
		// ��ӹ���
		virtual void Add(IEntityBaseFactory* pIEntityBaseFactory);
		// �Ƴ�������
		virtual void Remove(IEntityBaseFactory* pIEntityBaseFactory);
		// ��������еĹ���
		virtual IEntityFactoryType::ListEntityFactorys GetChilds(void) const;
		// ���ø���
		virtual void SetParent(IEntityBaseFactory* pIEntityBaseFactory);
		// ��ø���
		virtual IEntityBaseFactory* GetParent(void) const;

	protected:
		// �Ƿ������ �����
		bool IsHand(const SVString& strPath);

	private:
		IEntityBaseFactory* m_pIParent; // ����ָ��
		SVString m_strPath; // ·��
		SVString m_strName; // ��������
		ListEntityFactorys m_lstEntityFactorys; // ��Ԫ���б�

	};
}


