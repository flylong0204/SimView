/**************************************************
outher: LJ
time: 2016-03-23
use: ���Խӿ�
from:
chanage:
change outher :
**************************************************/
#ifndef _PUBLIC_IATTRIBUTE_H_
#define _PUBLIC_IATTRIBUTE_H_

namespace SimView
{
	class KERNER_EXPORT IAttribute
	{
	public:
		typedef std::list<IAttributeItem* > LstAttrItems;

	public:
		// ��������
		virtual ~IAttribute(void) { }
		// ��ʼ������
		virtual void Init(void) = 0;
		// ���ģ�Ͷ���
		virtual IEntity* GetEntity(void) const = 0;
		// �������
		virtual const SVString& GetName(void) const = 0;
		// ��������
		virtual void SetName(const SVString& strName) = 0;
		// ��������б�
		virtual const LstAttrItems& GetAttrItems(void) const = 0;
		// ͨ�����Ե����ƻ�ȡ������
		virtual IAttributeItem* GetItem(const SVString& strName) const = 0;
		// ��������
		virtual void AddAttrItem(IAttributeItem* pIItem) = 0;
		// д���ڴ���
		//virtual void WriteMemory(void);
	};
}

#endif // !_PUBLIC_IATTRIBUTE_H_
