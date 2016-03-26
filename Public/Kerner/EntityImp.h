/**************************************************
outher: LJ
time: 2016-03-23
use: ʵ��ģ����
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
		// ���캯��
		explicit CEntityImp(void) : m_pIStateMachine(NULL), m_pIEntitiyDrawManager(NULL)
		{
			m_lstAttribtes.clear();
		}

		// ��������
		virtual ~CEntityImp(void)
		{
			// ɾ������
			RemoveAll();
			// ɾ����Ⱦ����
			SIMVIEW_DELETE(m_pIEntitiyDrawManager);
			// ɾ��״̬��
			SIMVIEW_DELETE(m_pIStateMachine);
		}

	public:
		// ��������
		virtual void SetName(const SVString& strName);
		// �������
		virtual SVString GetName(void) const;
		// ����ʵ���������
		virtual void SetBaseAttribute(IBaseAttribute* pIBaseAttribute);
		// ��û������Զ���
		virtual IBaseAttribute* GetBaseAttribute(void) const;
		// �������
		virtual void AddAttributes(IAttribute* pIAttribute);
		// �������
		virtual IAttribute* GetAttribute(const SVString& strAttrName) const;
		// �����������
		virtual IEntity::ListAttributes GetAllAttribute(void) const;
		// �����Ⱦ����
		virtual void AddDrawAttribute(IDrawAttribute* pIDrawAttribute);
		// �����Ⱦ����
		virtual IDrawAttribute* GetDrawAttribute(const SVString& strName);
		// �Ƴ�����
		virtual void RemoveDrawAttribute(IAttribute* pIAttribute);
		// ������Ⱦ����
		virtual void SetDrawManager(IDrawManager* pIDrawManager);
		// �����Ⱦ����
		virtual IDrawManager* GetDrawManager(void) const;

	public:
		// ����ģ��
		virtual void Update(void);

		// ��������
	public:
		// ���ñ�־
		virtual void SetID(ulong_l uid);
		// ��ñ�־
		virtual const ulong_l GetID(void) const;

		//��Ϣ���
	public: 
		// ������Ϣ
		virtual bool HandleMessage(const IMessage* pIMessage);
		// ���״̬��
		virtual IStateMachine* GetStateMachine(void) const;
		// ����״̬��
		virtual void SetStateMachine(IStateMachine* pIStateMachine);

	protected:
		// ��ʼ��
		void InitAttribute(IAttribute* pIAttribute);
		// �Ƴ����е�����
		void RemoveAll(void);
		// �����Ƿ���ڵ�ǰ����
		bool IsHand(const SVString& strName) const;

	private:
		typedef std::map<SVString, IAttribute*> MapAttributes;

	private:
		IStateMachine* m_pIStateMachine; // ״̬��
		MapAttributes m_lstAttribtes; // ���Լ���
		IDrawManager* m_pIDrawManager;
	};

	// �����Ƿ���ڵ�ǰ����
	template <class T>
	bool CEntityImp<T>::IsHand(const SVString& strName) const
	{
		MapAttributes::const_iterator cstItor = m_lstAttribtes.find(strName);
		return (m_lstAttribtes.end() != cstItor);
	}

	// �Ƴ����е�����
	template <class T>
	void CEntityImp<T>::RemoveAll(void)
	{
		MapAttributes::iterator itor = m_lstAttribtes.begin();
		for (; m_lstAttribtes.end() != itor; ++itor)
		{
			// �Ƴ���Ⱦ����
			m_pIDrawManager->Remove(itor->second);
			SIMVIEW_DELETE(itor->second);
		}

		m_lstAttribtes.clear();
	}

	// ��ʼ��
	template <class T>
	void CEntityImp<T>::InitAttribute(IAttribute* pIAttribute)
	{
		pIAttribute->Init();
	}

	// ����״̬��
	template <class T>
	void CEntityImp<T>::SetStateMachine(IStateMachine* pIStateMachine)
	{
		m_pIStateMachine = pIStateMachine;
	}

	// ���״̬��
	template <class T>
	IStateMachine* CEntityImp<T>::GetStateMachine(void) const
	{
		return (m_pIStateMachine);
	}

	// ������Ϣ
	template <class T>
	bool CEntityImp<T>::HandleMessage(const IMessage* pIMessage)
	{
		// �ж�״̬���Ƿ����
		if (NULL == m_pIStateMachine)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, "״̬��������", "HandleMessage");
		}


		return m_pIStateMachine->HandleMessage(pIMessage);
	}

	// ��ñ�־
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

	// ���ñ�־
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

	// ����ģ��
	template <class T>
	void CEntityImp<T>::Update(void)
	{
		// ״̬������
		m_pIStateMachine->Update();
	}

	// �Ƴ�����
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

	// �����Ⱦ����
	template <class T>
	IDrawAttribute* CEntityImp<T>::GetDrawAttribute(const SVString& strName)
	{
		if (NULL == m_pIDrawManager)
		{
			return (NULL);
		}

		return (m_pIDrawManager->GetAttribute(strName));
	}

	// �����Ⱦ����
	template <class T>
	void CEntityImp<T>::AddDrawAttribute(IDrawAttribute* pIDrawAttribute)
	{
		// �����Ƿ���ڵ�ǰ������
		if (IsHand(pIDrawAttribute->GetName()) || (NULL == m_pIDrawManager))
		{
			return;
		}

		m_pIDrawManager->Add(pIDrawAttribute);
		m_lstAttribtes[pIDrawAttribute->GetName()] = pIDrawAttribute;
	}

	// �����Ⱦ����
	template <class T>
	IDrawManager* CEntityImp<T>::GetDrawManager(void) const
	{
		return (m_pIDrawManager);
	}

	// ������Ⱦ����
	template <class T>
	void CEntityImp<T>::SetDrawManager(IDrawManager* pIDrawManager)
	{
		m_pIDrawManager = pIDrawManager;
	}

	// �����������
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

	// �������
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

	// �������
	template <class T>
	void CEntityImp<T>::AddAttributes(IAttribute* pIAttribute)
	{
		// ��õ�ǰ�������Ƿ����
		MapAttributes::iterator itor = m_lstAttribtes.find(pIAttribute->GetName());
		if (m_lstAttribtes.end() == itor)
		{
			m_lstAttribtes[pIAttribute->GetName()] = pIAttribute;

			return;
		}

		// ����ɾ��ԭ���� ���и���ֵ
		SIMVIEW_DELETE(itor->second);
		itor->second = pIAttribute;

		InitAttribute(pIAttribute);
	}

	// ��û������Զ���
	template <class T>
	IBaseAttribute* CEntityImp<T>::GetBaseAttribute(void) const
	{
		IBaseAttribute* pIBaseAttribute = dynamic_cast<IBaseAttribute*>(GetAttribute("��������"));
		return (pIBaseAttribute);
	}

	// ����ʵ���������
	template <class T>
	void CEntityImp<T>::SetBaseAttribute(IBaseAttribute* pIBaseAttribute)
	{
		AddAttributes(pIBaseAttribute);
	}

	// �������
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
