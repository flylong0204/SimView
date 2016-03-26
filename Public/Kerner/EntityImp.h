/**************************************************
outher: LJ
time: 2016-03-23
use: 实体模板类
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_ENTITYIMP_H_
#define _PUBLIC_ENTITYIMP_H_

namespace SimView
{
	template <class T>
	class CEntityImp : public T
	{
	public:
		// 构造函数
		explicit CEntityImp(void) : m_pIStateMachine(NULL), m_pIEntitiyDrawManager(NULL)
		{
			m_lstAttribtes.clear();
		}

		// 析构函数
		virtual ~CEntityImp(void)
		{
			// 删除属性
			RemoveAll();
			// 删除渲染管理
			SIMVIEW_DELETE(m_pIEntitiyDrawManager);
			// 删除状态机
			SIMVIEW_DELETE(m_pIStateMachine);
		}

	public:
		// 设置名称
		virtual void SetName(const SVString& strName);
		// 获得名称
		virtual SVString GetName(void) const;
		// 设置实体基本属性
		virtual void SetBaseAttribute(IBaseAttribute* pIBaseAttribute);
		// 获得基本属性对象
		virtual IBaseAttribute* GetBaseAttribute(void) const;
		// 添加属性
		virtual void AddAttributes(IAttribute* pIAttribute);
		// 获得属性
		virtual IAttribute* GetAttribute(const SVString& strAttrName) const;
		// 获得所有属性
		virtual IEntity::ListAttributes GetAllAttribute(void) const;
		// 添加渲染属性
		virtual void AddDrawAttribute(IDrawAttribute* pIDrawAttribute);
		// 获得渲染属性
		virtual IDrawAttribute* GetDrawAttribute(const SVString& strName);
		// 移除属性
		virtual void RemoveDrawAttribute(IAttribute* pIAttribute);
		// 设置渲染管理
		virtual void SetDrawManager(IDrawManager* pIDrawManager);
		// 获得渲染管理
		virtual IDrawManager* GetDrawManager(void) const;

	public:
		// 更新模型
		virtual void Update(void);

		// 基础属性
	public:
		// 设置标志
		virtual void SetID(ulong_l uid);
		// 获得标志
		virtual const ulong_l GetID(void) const;

		//消息相关
	public: 
		// 处理消息
		virtual bool HandleMessage(const IMessage* pIMessage);
		// 获得状态机
		virtual IStateMachine* GetStateMachine(void) const;
		// 设置状态机
		virtual void SetStateMachine(IStateMachine* pIStateMachine);

	protected:
		// 初始化
		void InitAttribute(IAttribute* pIAttribute);
		// 移除所有的属性
		void RemoveAll(void);
		// 查找是否存在当前属性
		bool IsHand(const SVString& strName) const;

	private:
		typedef std::map<SVString, IAttribute*> MapAttributes;

	private:
		IStateMachine* m_pIStateMachine; // 状态机
		MapAttributes m_lstAttribtes; // 属性集合
		IDrawManager* m_pIDrawManager;
	};

	// 查找是否存在当前属性
	template <class T>
	bool CEntityImp<T>::IsHand(const SVString& strName) const
	{
		MapAttributes::const_iterator cstItor = m_lstAttribtes.find(strName);
		return (m_lstAttribtes.end() != cstItor);
	}

	// 移除所有的属性
	template <class T>
	void CEntityImp<T>::RemoveAll(void)
	{
		MapAttributes::iterator itor = m_lstAttribtes.begin();
		for (; m_lstAttribtes.end() != itor; ++itor)
		{
			// 移除渲染属性
			m_pIDrawManager->Remove(itor->second);
			SIMVIEW_DELETE(itor->second);
		}

		m_lstAttribtes.clear();
	}

	// 初始化
	template <class T>
	void CEntityImp<T>::InitAttribute(IAttribute* pIAttribute)
	{
		pIAttribute->Init();
	}

	// 设置状态机
	template <class T>
	void CEntityImp<T>::SetStateMachine(IStateMachine* pIStateMachine)
	{
		m_pIStateMachine = pIStateMachine;
	}

	// 获得状态机
	template <class T>
	IStateMachine* CEntityImp<T>::GetStateMachine(void) const
	{
		return (m_pIStateMachine);
	}

	// 处理消息
	template <class T>
	bool CEntityImp<T>::HandleMessage(const IMessage* pIMessage)
	{
		// 判断状态机是否存在
		if (NULL == m_pIStateMachine)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, "状态机不存在", "HandleMessage");
		}


		return m_pIStateMachine->HandleMessage(pIMessage);
	}

	// 获得标志
	template <class T>
	const ulong_l CEntityImp<T>::GetID(void) const
	{
		IBaseAttribute* pIBaseAttribte = GetBaseAttribute();
		if (NULL == pIBaseAttribte)
		{
			return (-1);
		}
		return (pIBaseAttribte->GetEntityID());
	}

	// 设置标志
	template <class T>
	void CEntityImp<T>::SetID(ulong_l uid)
	{
		IBaseAttribute* pIBaseAttribte = GetBaseAttribute();
		if (NULL == pIBaseAttribte)
		{
			return;
		}
		pIBaseAttribte->SetEntityID(uid);
	}

	// 更新模型
	template <class T>
	void CEntityImp<T>::Update(void)
	{
		// 状态机更新
		m_pIStateMachine->Update();
	}

	// 移除属性
	template <class T>
	void CEntityImp<T>::RemoveDrawAttribute(IAttribute* pIAttribute)
	{
		m_pIDrawManager->Remove(pIDrawAttribute);
		MapAttributes::iterator itor = m_lstAttribtes.find(pIDrawAttribute->GetName());
		if (m_lstAttribtes.end() == itor)
		{
			return;
		}

		m_lstAttribtes.erase(itor);
	}

	// 获得渲染属性
	template <class T>
	IDrawAttribute* CEntityImp<T>::GetDrawAttribute(const SVString& strName)
	{
		if (NULL == m_pIDrawManager)
		{
			return (NULL);
		}

		return (m_pIDrawManager->GetAttribute(strName));
	}

	// 添加渲染属性
	template <class T>
	void CEntityImp<T>::AddDrawAttribute(IDrawAttribute* pIDrawAttribute)
	{
		// 查找是否存在当前的属性
		if (IsHand(pIDrawAttribute->GetName()) || (NULL == m_pIDrawManager))
		{
			return;
		}

		m_pIDrawManager->Add(pIDrawAttribute);
		m_lstAttribtes[pIDrawAttribute->GetName()] = pIDrawAttribute;
	}

	// 获得渲染管理
	template <class T>
	IDrawManager* CEntityImp<T>::GetDrawManager(void) const
	{
		return (m_pIDrawManager);
	}

	// 设置渲染管理
	template <class T>
	void CEntityImp<T>::SetDrawManager(IDrawManager* pIDrawManager)
	{
		m_pIDrawManager = pIDrawManager;
	}

	// 获得所有属性
	template <class T>
	IEntity::ListAttributes CEntityImp<T>::GetAllAttribute(void) const
	{
		IEntity::ListAttributes lstAttribute;
		MapAttributes::const_iterator itor = m_lstAttribtes.begin();
		for (; m_lstAttribtes.end() != itor; ++itor)
		{
			lstAttribute.push_back(itor->second);
		}

		return (lstAttribute);
	}

	// 获得属性
	template <class T>
	IAttribute* CEntityImp<T>::GetAttribute(const SVString& strAttrName) const
	{
		MapAttributes::const_iterator itor = m_lstAttribtes.find(strAttrName);
		if (m_lstAttribtes.end() == itor)
		{
			return (NULL);
		}

		return (itor->second);
	}

	// 添加属性
	template <class T>
	void CEntityImp<T>::AddAttributes(IAttribute* pIAttribute)
	{
		// 获得当前的属性是否存在
		MapAttributes::iterator itor = m_lstAttribtes.find(pIAttribute->GetName());
		if (m_lstAttribtes.end() == itor)
		{
			m_lstAttribtes[pIAttribute->GetName()] = pIAttribute;

			return;
		}

		// 否则删除原来的 进行更新值
		SIMVIEW_DELETE(itor->second);
		itor->second = pIAttribute;

		InitAttribute(pIAttribute);
	}

	// 获得基本属性对象
	template <class T>
	IBaseAttribute* CEntityImp<T>::GetBaseAttribute(void) const
	{
		IBaseAttribute* pIBaseAttribute = dynamic_cast<IBaseAttribute*>(GetAttribute("基础属性"));
		return (pIBaseAttribute);
	}

	// 设置实体基本属性
	template <class T>
	void CEntityImp<T>::SetBaseAttribute(IBaseAttribute* pIBaseAttribute)
	{
		AddAttributes(pIBaseAttribute);
	}

	// 获得名称
	template <class T>
	SVString CEntityImp<T>::GetName(void) const
	{
		IBaseAttribute* pIBaseAttribute = GetBaseAttribute();
		if (NULL == pIBaseAttribute)
		{
			return ("");
		}
		return (pIBaseAttribute->GetEntityName());
	}

	template <class T>
	void CEntityImp<T>::SetName(const SVString& strName)
	{
		IBaseAttribute* pIBaseAttribute = GetBaseAttribute();
		if (NULL == pIBaseAttribute)
		{
			return;
		}
		pIBaseAttribute->SetEntityName(strName);
	}

}

#endif // !_PUBLIC_ENTITYIMP_H_
