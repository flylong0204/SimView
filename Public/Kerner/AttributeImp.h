/**************************************************
outher: LJ
time: 2016-03-23
use: ����ģ����
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_ATTRIBUTEIMP_H_
#define _PUBLIC_ATTRIBUTEIMP_H_

namespace SimView
{
	template <class T>
	class CAttributeImp : public T
	{
	public:
		// ���캯��
		explicit CAttributeImp(IEntity* pIEntity, const SVString& strName);
		// ��������
		virtual ~CAttributeImp();
		// ���ʵ�����
		virtual IEntity* GetEntity(void) const;
		// �������
		virtual const SVString& GetName(void) const;
		// ��������
		virtual void SetName(const SVString& strName);
		// ��������б�
		virtual const IAttribute::LstAttrItems& GetAttrItems(void) const;
		// ͨ�����Ե����ƻ�ȡ������
		virtual IAttributeItem* GetItem(const SVString& strName) const;
		// ��������
		virtual void AddAttrItem(IAttributeItem* pIItem);
		// ��ʼ��
		virtual void Init(void);
		// ���浽�ڴ���
		virtual void WriteMemory(void);

	private:
		IEntity* m_pIEntity; // ָ��ʵ��
		IAttribute::LstAttrItems m_lstAttrItems; // �������
		SVString m_strName; // ��������
	};

	// ���캯��
	template <class T>
	CAttributeImp<T>::CAttributeImp(IEntity* pIEntity, const SVString& strName)
		:m_pIEntity(pIEntity), m_strName(strName)
	{		
	}

	// ��������
	template <class T>
	CAttributeImp<T>::~CAttributeImp()
	{

	}

	// ���ʵ�����
	template <class T>
	IEntity* CAttributeImp<T>::GetEntity(void) const
	{
		return (m_pIEntity);
	}

	// �������
	template <class T>
	const SVString& CAttributeImp<T>::GetName(void) const
	{
		return m_strName;
	}
	// ��������
	template <class T>
	void CAttributeImp<T>::SetName(const SVString& strName)
	{		
		m_strName = strName;
	}

	// ��������б�
	template <class T>
	const IAttribute::LstAttrItems& CAttributeImp<T>::GetAttrItems(void) const
	{
		return (m_lstAttrItems);
	}

	// ͨ�����Ե����ƻ�ȡ������
	template <class T>
	IAttributeItem* CAttributeImp<T>::GetItem(const SVString& strName) const
	{
		IAttributeItem *pIAttriItem = NULL;
		// ��ѯ����ֵ
		for (LstAttrItems::const_iterator cstItor = m_lstAttrItems.begin(); \
			cstItor != m_lstAttrItems.end(); ++cstItor)
		{
			if (0 == (*cstItor)->GetTypeName().compare(strName))
			{
				pIAttriItem = *cstItor;
				break;
			}
		}

		// ���ض���
		return (pIAttriItem);
	}

	// ��������
	template <class T>
	void CAttributeImp<T>::AddAttrItem(IAttributeItem* pIItem)
	{
		// �����Ƿ��е�ǰ������ֵ
		IAttributeItem* pItem = GetItem(pIItem->GetTypeName());
		if (NULL == pItem)
		{
			// û�е�ǰ���� ֱ����ӽ�ȥ
			//	((CAttributeItemImp<IAttributeItem>*)pIItem)->SetAttribute(this);
			m_lstAttrItems.push_back(pIItem);
			return;
		}

		pItem = pIItem;
	}

	// ��ʼ��
	template <class T>
	void CAttributeImp<T>::Init(void)
	{

	}

	// ���浽�ڴ���
	template <class T>
	void CAttributeImp<T>::WriteMemory(void)
	{
		// ����ѡ��
		for (LstAttrItems::const_iterator cstItor = m_lstAttrItems.begin(); \
			cstItor != m_lstAttrItems.end(); ++cstItor)
		{
			(*cstItor)->WriteMemory();
		}

	}
}

#endif // !_PUBLIC_ATTRIBUTEIMP_H_
