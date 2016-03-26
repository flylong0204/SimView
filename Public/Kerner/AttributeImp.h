/**************************************************
outher: LJ
time: 2016-03-23
use: 属性模板类
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
		// 构造函数
		explicit CAttributeImp(IEntity* pIEntity, const SVString& strName);
		// 析构函数
		virtual ~CAttributeImp();
		// 获得实体对象
		virtual IEntity* GetEntity(void) const;
		// 获得名称
		virtual const SVString& GetName(void) const;
		// 设置名称
		virtual void SetName(const SVString& strName);
		// 获得属性列表
		virtual const IAttribute::LstAttrItems& GetAttrItems(void) const;
		// 通过属性的名称获取属性项
		virtual IAttributeItem* GetItem(const SVString& strName) const;
		// 设置属性
		virtual void AddAttrItem(IAttributeItem* pIItem);
		// 初始化
		virtual void Init(void);
		// 保存到内存中
		virtual void WriteMemory(void);

	private:
		IEntity* m_pIEntity; // 指定实体
		IAttribute::LstAttrItems m_lstAttrItems; // 属性项集合
		SVString m_strName; // 名称属性
	};

	// 构造函数
	template <class T>
	CAttributeImp<T>::CAttributeImp(IEntity* pIEntity, const SVString& strName)
		:m_pIEntity(pIEntity), m_strName(strName)
	{		
	}

	// 析构函数
	template <class T>
	CAttributeImp<T>::~CAttributeImp()
	{

	}

	// 获得实体对象
	template <class T>
	IEntity* CAttributeImp<T>::GetEntity(void) const
	{
		return (m_pIEntity);
	}

	// 获得名称
	template <class T>
	const SVString& CAttributeImp<T>::GetName(void) const
	{
		return m_strName;
	}
	// 设置名称
	template <class T>
	void CAttributeImp<T>::SetName(const SVString& strName)
	{		
		m_strName = strName;
	}

	// 获得属性列表
	template <class T>
	const IAttribute::LstAttrItems& CAttributeImp<T>::GetAttrItems(void) const
	{
		return (m_lstAttrItems);
	}

	// 通过属性的名称获取属性项
	template <class T>
	IAttributeItem* CAttributeImp<T>::GetItem(const SVString& strName) const
	{
		IAttributeItem *pIAttriItem = NULL;
		// 查询属性值
		for (LstAttrItems::const_iterator cstItor = m_lstAttrItems.begin(); \
			cstItor != m_lstAttrItems.end(); ++cstItor)
		{
			if (0 == (*cstItor)->GetTypeName().compare(strName))
			{
				pIAttriItem = *cstItor;
				break;
			}
		}

		// 返回对象
		return (pIAttriItem);
	}

	// 设置属性
	template <class T>
	void CAttributeImp<T>::AddAttrItem(IAttributeItem* pIItem)
	{
		// 查找是否含有当前的属性值
		IAttributeItem* pItem = GetItem(pIItem->GetTypeName());
		if (NULL == pItem)
		{
			// 没有当前属性 直接添加进去
			//	((CAttributeItemImp<IAttributeItem>*)pIItem)->SetAttribute(this);
			m_lstAttrItems.push_back(pIItem);
			return;
		}

		pItem = pIItem;
	}

	// 初始化
	template <class T>
	void CAttributeImp<T>::Init(void)
	{

	}

	// 保存到内存中
	template <class T>
	void CAttributeImp<T>::WriteMemory(void)
	{
		// 遍历选项
		for (LstAttrItems::const_iterator cstItor = m_lstAttrItems.begin(); \
			cstItor != m_lstAttrItems.end(); ++cstItor)
		{
			(*cstItor)->WriteMemory();
		}

	}
}

#endif // !_PUBLIC_ATTRIBUTEIMP_H_
