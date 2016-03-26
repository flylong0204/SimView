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

	// 获得路径
	SVString CEntityFactoryManager::GetPath(void) const
	{
		return (m_strPath);
	}

	// 设置路径
	void CEntityFactoryManager::SetPath(const SVString& strPath)
	{
		m_strPath = strPath;
	}

	const SVString CEntityFactoryManager::GetType(void) const
	{
		return ("ConmpTpye"); 
	}

	// 获得工厂名称 即实体名称
	const SVString& CEntityFactoryManager::GetInstanceName(void) const
	{
		return (m_strName);
	}

	// 添加工厂
	void CEntityFactoryManager::Add(IEntityBaseFactory* pIEntityBaseFactory)
	{
		// 添加到列表中
		m_lstEntityFactorys.push_back(pIEntityBaseFactory);

		if (IsHand(pIEntityBaseFactory->GetInstanceName()))
		{
			m_lstEntityFactorys.pop_back(); 
		}
	}

	// 移除出工厂
	void CEntityFactoryManager::Remove(IEntityBaseFactory* pIEntityBaseFactory)
	{
		// 判断是否为第首个值
		IEntityFactoryType::ListEntityFactorys::iterator itor = std::find(m_lstEntityFactorys.begin(), m_lstEntityFactorys.end(), pIEntityBaseFactory);
		if (m_lstEntityFactorys.end() == itor)
		{
			return;
		}

		// 判断是否为工厂管理集
		IEntityFactoryType* pIEntityFactoryTyp = dynamic_cast<IEntityFactoryType*>(pIEntityBaseFactory);
		if (NULL == pIEntityFactoryTyp)
		{
			SIMVIEW_DELETE(pIEntityBaseFactory);
			m_lstEntityFactorys.erase(itor);
			ILogManage::GetSingleton().RecordLog("删除工厂" + pIEntityBaseFactory->GetInstanceName() + "成功");
			return;
		}
	
		// 遍历所有的子对象 
		IEntityFactoryType::ListEntityFactorys lstFactroys = pIEntityFactoryTyp->GetChilds();
		IEntityFactoryType::ListEntityFactorys::iterator findItor = lstFactroys.begin();
		for (; lstFactroys.end() != findItor; ++findItor)
		{
			IEntityBaseFactory* pIBaseFactory = *findItor;
			pIBaseFactory->SetParent(this);
			Add(pIBaseFactory);
		}

		// 删除当前的工厂
		SIMVIEW_DELETE(pIEntityBaseFactory);
		m_lstEntityFactorys.erase(itor);
		ILogManage::GetSingleton().RecordLog("删除工厂" + pIEntityBaseFactory->GetInstanceName() + "成功");
		
	}

	// 获得子所有的工厂
	IEntityFactoryType::ListEntityFactorys CEntityFactoryManager::GetChilds(void) const
	{
		return (m_lstEntityFactorys);
	}

	// 设置父类
	void CEntityFactoryManager::SetParent(IEntityBaseFactory* pIEntityBaseFactory)
	{
		m_pIParent = pIEntityBaseFactory;
	}

	// 获得父类
	IEntityBaseFactory* CEntityFactoryManager::GetParent(void) const
	{
		return (m_pIParent);
	}

	// 是否包含了 该组件
	bool CEntityFactoryManager::IsHand(const SVString& strPath)
	{
		// 判断当前路径是否为空
		if (m_strPath.empty())
		{
			SetPath(m_strName);
		}

		// 判断路径是否包含了该组件
		// 判断是否为根节点
		if (0 == GetPath().find_first_of(strPath + "."))
		{
			// 说明是根组件，重复添加了
			ILogManage::GetSingleton().RecordLog("在本通路上，组件 " + strPath + " 已被添加过了");
			return (true);
		}
		else
		{
			if (GetPath().find("." + strPath) < 0)
			{
				//表示没有出现过,那么可以加入
				//计算组件的路径
				SVString componentPath = GetPath() + "." + strPath;
				//设置子组件的路径
				SetPath(componentPath);
			}
			else
			{
				// 说明是根组件，重复添加了
				ILogManage::GetSingleton().RecordLog("在本通路上，组件 " + strPath + " 已被添加过了");
				return (true);

			}
		}
		return (false);
	}

}
