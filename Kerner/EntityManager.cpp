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

	// 加入实体
	void CEntityManager::Add(IEntity* pIEntity)
	{
		SIMVIEW_LOCK_AUTO_METEX

		// 查找是否存在
		int index = GetIndex(pIEntity);
		if (-1 == index)
		{
			m_lstEntitys.push_back(pIEntity);
		}
	}

	// 移除实体
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
		// 查询是否存在 不存在返回-1
		ListEntitys::const_iterator cstItor = m_lstEntitys.begin();
		while (m_lstEntitys.end() != cstItor)
		{
			++index;
			++cstItor;
		}

		// 判断是否查找到
		if (m_lstEntitys.end() == cstItor)
		{
			return (-1);
		}

		// 查找成功
		return (index);

	}

	// 通过位置获得实体
	IEntity* CEntityManager::GetEntity(const int index)
	{
		// 判断位置是否合法
		if ((int)m_lstEntitys.size() < index)
		{
			return (NULL);
		}

		// 遍历所有的实体
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
