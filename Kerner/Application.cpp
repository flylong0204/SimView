#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "ComEnumerator.h"
#include "DynLibManage.h"
#include "PluginManage.h"
#include "GUID.h"
#include "AttributeItem.h"
#include "ConfigFileUtil.h"
#include "Application.h"

namespace SimView
{
	// 构造函数
	CApplication::CApplication(void):
		m_pILogManage(NULL),
		m_pIPluginManage(NULL),
		m_pIDynLibManage(NULL),
		m_pComEnumerator(NULL),
		m_strModuleDir("")
	{
		Init();
	}

	// 析构函数
	CApplication::~CApplication(void)
	{
		SIMVIEW_DELETE(m_pIPluginManage);
		SIMVIEW_DELETE(m_pIDynLibManage);
		SIMVIEW_DELETE(m_pComEnumerator);
		SIMVIEW_DELETE(m_pILogManage);
	}

	// 初始化
	void CApplication::Init(void)
	{
		// 创建日志管理
		m_pILogManage = new CLogManage;
		// 创建日志对象
		m_pILogManage->CreateLog("simview.log", true);
		// 创建插件管理
		m_pIPluginManage = new CPluginManage;
		// 创建动态库管理
		m_pIDynLibManage = new CDynLibManage;
		// 创建实体管理
		m_pComEnumerator = new CComEnumerator;
	}

	// 产生guid 每次获得都是新的值
	long_l CApplication::GenerateGuid(void)
	{
		// 调用GUID生成类生成GUID
		long_l llGuid = CGUID::Generate();
		return (llGuid);
	}

	IAttributeItem* CApplication::CreateAttributeItem(IAttribute* pIAttribute, const SVString& strItemName, \
		const SVString& strText, const SVString& strUntil, \
		const Variant& var, const Contrl ct /*= CTRL_SPINBOX*/)
	{
		IAttributeItem* pItem = new CAttributeItem(pIAttribute, strItemName, strText, strUntil, var);
		if (NULL != pItem)
		{
			pItem->SetCtrlType(ct);
		}

		// 返回有效值
		return (pItem);
	}

	// 创建配置文件操作类
	IConfigFileUtil* CApplication::CreateConfigFileUtil(void)
	{
		return (new CConfigFileUtil);
	}

	// 获得可执行程序路径
	SVString CApplication::GetModulePath(void) const
	{
		return (m_strModuleDir);
	}

	// 设置可执行程序路径
	void CApplication::SetModuleDir(const SVString& strModuleDir)
	{
		if (strModuleDir.empty())
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, "可执行程序路径为空", "SetModuleDir");
		}

		// 查找最后一个 ‘/’
		const int nPos = strModuleDir.find_last_of('\\');
		if (-1 == nPos)
		{
			return ;
		}

		// 获得路径
		SVString str = strModuleDir.substr(0, nPos);

		// 当前路径
		ILogManage::GetSingleton().RecordLog("可执行程序当前路径为:" + str);
		m_strModuleDir = str;
	}

	// 创建实例
	IApplication* CreateApplication(int argc, char *argv[])
	{
		CApplication* pApplication = new CApplication;
		pApplication->SetModuleDir(argv[0]);
		return (pApplication);
	}

}