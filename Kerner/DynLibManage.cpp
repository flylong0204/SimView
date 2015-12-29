#define SIMVIEW_KERNERLIB
#include "../Public/Kerner/Kerner.h"
#include "DynLibManage.h"


namespace SimView
{
	//构造函数
	CDynLibManage::CDynLibManage()
	{
	}

	// 析构函数
	CDynLibManage::~CDynLibManage()
	{
		// 删除所有动态库
		DynLibList::iterator itor = m_lstDynLib.begin();
		for (; m_lstDynLib.end() != itor; ++itor)
		{
			itor->second->UnLoad();
			SIMVIEW_DELETE(itor->second);
		}

		// 清空链表
		m_lstDynLib.clear();
	}

	// 导入动态库
	CDynamicLib* CDynLibManage::Load(const SVString& strDynLibName)
	{
		// 查找当前是库是否已经被加载
		DynLibList::const_iterator cstItor = m_lstDynLib.find(strDynLibName);
		if (m_lstDynLib.end() != cstItor)
		{
			// 已经被加载 ，直接返回当前库
			return (cstItor->second);
		}

		// 没有加载 则直接加载进入
		CDynamicLib* pDynLib = new CDynamicLib(strDynLibName);
		// 导入动态库
		pDynLib->Load();
		m_lstDynLib[strDynLibName] = pDynLib;
		return (pDynLib);
	}

	// 卸载动态库
	void CDynLibManage::UnLoad(CDynamicLib* pDynLib)
	{
		// 查找当前存在
		DynLibList::iterator itor = m_lstDynLib.find(pDynLib->GetName());
		if (m_lstDynLib.end() != itor)
		{
			m_lstDynLib.erase(itor);
		}

		// 卸载
		pDynLib->UnLoad();
		SIMVIEW_DELETE(pDynLib);
	}

}
