#define  SIMVIEW_KERNERLIB
#include <algorithm>
#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "ComEnumerator.h"

namespace SimView
{
	// 构造函数
	CComEnumerator::CComEnumerator(void)
	{
	}

	// 析构函数
	CComEnumerator::~CComEnumerator(void)
	{
		// 遍历所有的实例
		ListInstaces::iterator  itor = m_listInstances.begin();
		for (; m_listInstances.end() != itor; ++itor)
		{
			// 通过工厂进行回收实例
			for (ListFactorys::iterator fItor = m_listFactorys.begin(); \
				m_listFactorys.end() != fItor; ++fItor)
			{
				IComBaseFactory* pIComBaseFactory = (*fItor);
				if (0 == pIComBaseFactory->GetMetaData().strTypeName.compare(itor->second->GetTypeName()))
				{
					pIComBaseFactory->DestoryInstance(itor->second);
					m_listInstances.erase(itor->first);
					break;
				}
			}
		}

		m_listInstances.clear();
	}

	// 添加工厂对象
	void CComEnumerator::AddFactory(IComBaseFactory* pIFactory)
	{
		// 查询是否存在当前的工厂
		ListFactorys::const_iterator cstItor = std::find(\
			m_listFactorys.begin(), m_listFactorys.end(), pIFactory);
		if (m_listFactorys.end() != cstItor)
		{
			return;
		}

		// 添加到列表中
		m_listFactorys.push_back(pIFactory);
		// 添加数据列表中
		m_listComData.push_back(&pIFactory->GetMetaData());

		CreateComInstance(pIFactory->GetMetaData().strTypeName, pIFactory->GetMetaData().strName);
		//写入日志
		CLogManage::GetSingleton().RecordLog("插件类型" + pIFactory->GetMetaData().strName + "成功注册");
	}

	// 移除工厂对象
	void CComEnumerator::RemoveFactory(IComBaseFactory* pIFactory)
	{
		// 回收当前实例
		ListInstaces::iterator itor = m_listInstances.begin();
		for (; m_listInstances.end() != itor;)
		{
			IComFaceBase* pIComFaceInst = itor->second;
			if (0 == pIComFaceInst->GetTypeName().compare(pIFactory->GetMetaData().strTypeName))
			{
				// 工厂回收实例
				pIFactory->DestoryInstance(pIComFaceInst);
				ListInstaces::iterator deli = itor++;
				m_listInstances.erase(deli);
			}
			else
			{
				++itor;
			}
		}

		// 移除数据
		ListComDatas::iterator dataItor = m_listComData.begin();
		for (; m_listComData.end() != dataItor; ++dataItor)
		{
			if (*dataItor == &(pIFactory->GetMetaData()))
			{
				m_listComData.erase(dataItor);
				break;
			}
		}

		m_listFactorys.remove(pIFactory);
	}

	// 创建实例
	IComFaceBase* CComEnumerator::CreateComInstance(const SVString& strTypeName, const SVString& strName)
	{
		// 判断当前实例是否存在
		if (m_listInstances.end() != m_listInstances.find(strName))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_DUPLICATE_ITEM, "当前插件:" + strName + \
				"已经存在", "CreateComInstance");
		}

		// 创建实例
		IComFaceBase* hIns = NULL;
		// 遍历工厂 
		ListFactorys::iterator itor = m_listFactorys.begin();
		for (; m_listFactorys.end() != itor; ++itor)
		{
			IComBaseFactory* pIComBaseFactory = *itor;
			if (0 == strTypeName.compare(pIComBaseFactory->GetMetaData().strTypeName))
			{
				hIns = pIComBaseFactory->CreateInstance(strName);
				break;
			}
		}

		if (NULL == hIns)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "没有当前类型的组件" + strTypeName, \
				"CreateComInstance");
		}

		// 保存到系统中
		m_listInstances[hIns->GetName()] = hIns;

		// 初始化插件
		hIns->Init();
		return (hIns);
	}

	// 获得实例
	IComFaceBase* CComEnumerator::GetComInstance(const SVString& strName) const
	{
		ListInstaces::const_iterator cstItor = m_listInstances.find(strName);
		if (m_listInstances.end() != cstItor)
		{
			return (cstItor->second);
		}
		else
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "没有找到当前组件" + strName, \
				"GetComInstance");
		}
	}

	// 是否存在当前插件
	bool CComEnumerator::HasComInstance(const SVString& strName) const
	{
		return (m_listInstances.end() == m_listInstances.find(strName));
	}

	// 卸载所有插件
	void CComEnumerator::ShutAll(void)
	{

	}

}