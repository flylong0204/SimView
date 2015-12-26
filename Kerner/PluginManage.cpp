#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "DynLibManage.h"
#include "ComEnumerator.h"
#include "PluginManage.h"

namespace SimView
{

	typedef void (*StartPluginFunc)(void);
	typedef void (*StopPluginFunc)(void);

	// 构造函数
	CPluginManage::CPluginManage(void)
		:IPluginManage(),
		m_bLoad(true)
	{
	}

	// 析构函数
	CPluginManage::~CPluginManage(void)
	{
		 // 卸载所有插件
		ShutDownAllPlugin();
	}

	// 添加工厂对象
	void CPluginManage::AddFactory(IComBaseFactory* pIFactory)
	{
		CComEnumerator::GetSingleton().AddFactory(pIFactory);
	}

	// 移除工厂对象
	void CPluginManage::RemoveFactory(IComBaseFactory* pIFactory)
	{
		CComEnumerator::GetSingleton().RemoveFactory(pIFactory);
	}

	// 获得插件对象
	IComFaceBase* CPluginManage::GetComInstance(const SVString& strName)
	{
		return (CComEnumerator::GetSingleton().GetComInstance(strName));
	}

	// 导入插件
	bool CPluginManage::LoadCom(const SVString& strComPath)
	{
		// 加载插件
		CDynamicLib* pLib = IDynLibManage::GetSingleton().Load(strComPath);
		if (NULL == pLib)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INTERNAL_ERROR,"初始化CDynamicLib失败",\
				"IPuginManager::LoadCom");
		}

		// 插件库是是否存在当前插件
		ListPluginLib::const_iterator cstItor = std::find(m_lstPluginLib.begin(), m_lstPluginLib.end(), pLib);
		if (m_lstPluginLib.end() != cstItor)
		{
			CLogManage::GetSingleton().RecordLog("插件" + strComPath + "已经被加载");
			return (true);
		}

		// 获得函数指针
		StartPluginFunc pDllStartFun = (StartPluginFunc)(pLib->GetSymbool("DllPluginStart"));
		if (NULL == pDllStartFun)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "插件"+ strComPath + "未找到入口函数DllPluginStart", \
				"IPuginManager::LoadCom");
		}

		// 执行函数
		pDllStartFun();
		return (true);
	}

	// 导出插件
	void CPluginManage::UnloadCom(const SVString& strComPath)
	{
		// 插件当前系统加载的插件的
		ListPluginLib::iterator itor = m_lstPluginLib.begin();
		for (; m_lstPluginLib.end() != itor; ++itor)
		{
			if (0 != (*itor)->GetName().compare(strComPath))
			{
				continue;
			}

			// 调用卸载函数
			StopPluginFunc pStopPluginFunc = (StopPluginFunc)(*itor)->GetSymbool("DllPluginStop");
			if (NULL == pStopPluginFunc)
			{
				// 没有找到 抛出异常
				SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "插件" + strComPath + "未找到入口函数DllPluginStop", \
					"IPuginManager::UnloadCom");
			}

			// 执行函数
			pStopPluginFunc();

			// 移除动态库
			CDynLibManage::GetSingleton().UnLoad(*itor);
			m_lstPluginLib.erase(itor);
			return;
		}
	}

	// 安装插件
	void CPluginManage::Install(IPlugin* pIPlugin)
	{
		CLogManage::GetSingleton().RecordLog("加载插件" + pIPlugin->GetName());
		m_lstPluginInstance.push_back(pIPlugin);
		// 安装插件
		if (NULL != pIPlugin)
		{
			pIPlugin->Install();

			if (m_bLoad)
			{
				pIPlugin->Initialise();
			}
		}

		CLogManage::GetSingleton().RecordLog("成功加载插件" + pIPlugin->GetName());
	}

	// 卸载插件
	void CPluginManage::Uninstall(IPlugin* pIPlugin)
	{
		// 记录日志
		CLogManage::GetSingleton().RecordLog("卸载插件" + pIPlugin->GetName());
		// 查询当前插件
		ListPluginInstance::iterator itor = std::find(m_lstPluginInstance.begin(), \
			m_lstPluginInstance.end(), pIPlugin);
		if (m_lstPluginInstance.end() != itor)
		{
			pIPlugin->ShutDown();
			pIPlugin->UnInstall();
			SIMVIEW_DELETE(pIPlugin);
			m_lstPluginInstance.erase(itor);
		}
		
		CLogManage::GetSingleton().RecordLog("成功卸载插件");
	}

	// 卸载所有插件
	void CPluginManage::ShutDownAllPlugin()
	{
		// 遍历插件
		ListPluginInstance::iterator itor = m_lstPluginInstance.begin();
		for (; m_lstPluginInstance.end() != itor; ++itor)
		{
			(*itor)->ShutDown();
			SIMVIEW_DELETE(*itor);
		}

		m_lstPluginInstance.clear();

	}

	// 卸载所有插件
	

}
