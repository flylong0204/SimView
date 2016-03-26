#include "../Public/Kerner/Kerner.h"
#include "EntityManager.h"

#include <algorithm>


namespace SimView
{
	CEntityManager::CEntityManager()
	{
	}


	CEntityManager::~CEntityManager()
	{
	}

	// ����ʵ��
	void CEntityManager::Add(IEntity* pIEntity)
	{
		SIMVIEW_LOCK_AUTO_METEX

		// �����Ƿ����
		int index = GetIndex(pIEntity);
		if (-1 == index)
		{
			m_lstEntitys.push_back(pIEntity);
		}
	}

	// �Ƴ�ʵ��
	void CEntityManager::Remove(IEntity* pIEntity)
	{
		SIMVIEW_LOCK_AUTO_METEX

		ListEntitys::iterator itor = std::find(m_lstEntitys.begin(), m_lstEntitys.end(), pIEntity);
		if (m_lstEntitys.end() == itor)
		{
			return;
		}

		m_lstEntitys.erase(itor);
	}

	int CEntityManager::GetIndex(IEntity* pIEntity) const
	{
		int index = -1;
		// ��ѯ�Ƿ���� �����ڷ���-1
		ListEntitys::const_iterator cstItor = m_lstEntitys.begin();
		while (m_lstEntitys.end() != cstItor)
		{
			++index;
			++cstItor;
		}

		// �ж��Ƿ���ҵ�
		if (m_lstEntitys.end() == cstItor)
		{
			return (-1);
		}

		// ���ҳɹ�
		return (index);

	}

	// ͨ��λ�û��ʵ��
	IEntity* CEntityManager::GetEntity(const int index)
	{
		// �ж�λ���Ƿ�Ϸ�
		if ((int)m_lstEntitys.size() < index)
		{
			return (NULL);
		}

		// �������е�ʵ��
		int nTemIndex = 0;
		ListEntitys::iterator itor = m_lstEntitys.begin();
		while (m_lstEntitys.end() != itor && nTemIndex < index)
		{
			++nTemIndex;
			++itor;
		}

		return (*itor);

	}

}
