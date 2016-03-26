#define  SIMVIEW_KERNERLIB
#include "../Public/Kerner/Kerner.h"
#include "EntityFactoryManager.h"

namespace SimView
{
	CEntityFactoryManager::CEntityFactoryManager(void) : m_pIParent(NULL)
	{
	}


	CEntityFactoryManager::~CEntityFactoryManager()
	{
	}

	// ���·��
	SVString CEntityFactoryManager::GetPath(void) const
	{
		return (m_strPath);
	}

	// ����·��
	void CEntityFactoryManager::SetPath(const SVString& strPath)
	{
		m_strPath = strPath;
	}

	const SVString CEntityFactoryManager::GetType(void) const
	{
		return ("ConmpTpye"); 
	}

	// ��ù������� ��ʵ������
	const SVString& CEntityFactoryManager::GetInstanceName(void) const
	{
		return (m_strName);
	}

	// ��ӹ���
	void CEntityFactoryManager::Add(IEntityBaseFactory* pIEntityBaseFactory)
	{
		// ��ӵ��б���
		m_lstEntityFactorys.push_back(pIEntityBaseFactory);

		if (IsHand(pIEntityBaseFactory->GetInstanceName()))
		{
			m_lstEntityFactorys.pop_back(); 
		}
	}

	// �Ƴ�������
	void CEntityFactoryManager::Remove(IEntityBaseFactory* pIEntityBaseFactory)
	{
		// �ж��Ƿ�Ϊ���׸�ֵ
		IEntityFactoryType::ListEntityFactorys::iterator itor = std::find(m_lstEntityFactorys.begin(), m_lstEntityFactorys.end(), pIEntityBaseFactory);
		if (m_lstEntityFactorys.end() == itor)
		{
			return;
		}

		// �ж��Ƿ�Ϊ��������
		IEntityFactoryType* pIEntityFactoryTyp = dynamic_cast<IEntityFactoryType*>(pIEntityBaseFactory);
		if (NULL == pIEntityFactoryTyp)
		{
			SIMVIEW_DELETE(pIEntityBaseFactory);
			m_lstEntityFactorys.erase(itor);
			ILogManage::GetSingleton().RecordLog("ɾ������" + pIEntityBaseFactory->GetInstanceName() + "�ɹ�");
			return;
		}
	
		// �������е��Ӷ��� 
		IEntityFactoryType::ListEntityFactorys lstFactroys = pIEntityFactoryTyp->GetChilds();
		IEntityFactoryType::ListEntityFactorys::iterator findItor = lstFactroys.begin();
		for (; lstFactroys.end() != findItor; ++findItor)
		{
			IEntityBaseFactory* pIBaseFactory = *findItor;
			pIBaseFactory->SetParent(this);
			Add(pIBaseFactory);
		}

		// ɾ����ǰ�Ĺ���
		SIMVIEW_DELETE(pIEntityBaseFactory);
		m_lstEntityFactorys.erase(itor);
		ILogManage::GetSingleton().RecordLog("ɾ������" + pIEntityBaseFactory->GetInstanceName() + "�ɹ�");
		
	}

	// ��������еĹ���
	IEntityFactoryType::ListEntityFactorys CEntityFactoryManager::GetChilds(void) const
	{
		return (m_lstEntityFactorys);
	}

	// ���ø���
	void CEntityFactoryManager::SetParent(IEntityBaseFactory* pIEntityBaseFactory)
	{
		m_pIParent = pIEntityBaseFactory;
	}

	// ��ø���
	IEntityBaseFactory* CEntityFactoryManager::GetParent(void) const
	{
		return (m_pIParent);
	}

	// �Ƿ������ �����
	bool CEntityFactoryManager::IsHand(const SVString& strPath)
	{
		// �жϵ�ǰ·���Ƿ�Ϊ��
		if (m_strPath.empty())
		{
			SetPath(m_strName);
		}

		// �ж�·���Ƿ�����˸����
		// �ж��Ƿ�Ϊ���ڵ�
		if (0 == GetPath().find_first_of(strPath + "."))
		{
			// ˵���Ǹ�������ظ������
			ILogManage::GetSingleton().RecordLog("�ڱ�ͨ·�ϣ���� " + strPath + " �ѱ���ӹ���");
			return (true);
		}
		else
		{
			if (GetPath().find("." + strPath) < 0)
			{
				//��ʾû�г��ֹ�,��ô���Լ���
				//���������·��
				SVString componentPath = GetPath() + "." + strPath;
				//�����������·��
				SetPath(componentPath);
			}
			else
			{
				// ˵���Ǹ�������ظ������
				ILogManage::GetSingleton().RecordLog("�ڱ�ͨ·�ϣ���� " + strPath + " �ѱ���ӹ���");
				return (true);

			}
		}
		return (false);
	}

}
