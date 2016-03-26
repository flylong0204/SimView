/**************************************************
outher: LJ
time: 2016-03-15
use: the base of Entity
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IENTITYBASEFACTORY_H_
#define _PUBLIC_IENTITYBASEFACTORY_H_

namespace SimView
{
	class KERNER_EXPORT IEntityBaseFactory
	{
	public:
		// ��������
		virtual ~IEntityBaseFactory() { }
		// ���·��
		virtual SVString GetPath(void) const = 0;
		// ����·��
		virtual void SetPath(const SVString& strPath) = 0;
		// �������
		virtual const SVString GetType(void) const = 0;
		// ��ù������� ��ʵ������
		virtual const SVString& GetInstanceName(void) const = 0;
		// ��ӹ���
		virtual void Add(IEntityBaseFactory* pIEntityBaseFactory) = 0;
		// �������
		virtual void Remove(IEntityBaseFactory* pIEntityBaseFactory) = 0;
		// ���ø���
		virtual void SetParent(IEntityBaseFactory* pIEntityBaseFactory) = 0;
		// ��ø���
		virtual IEntityBaseFactory* GetParent(void) const = 0;
	};
}

#endif // !_PUBLIC_IENTITYBASEFACTORY_H_