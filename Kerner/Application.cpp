#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "ComEnumerator.h"
#include "DynLibManage.h"
#include "PluginManage.h"
#include "GUID.h"
#include "Application.h"

namespace SimView
{
	// 构造函数
	CApplication::CApplication(void):
		m_pILogManage(NULL),
		m_pIPluginManage(NULL),
		m_pIDynLibManage(NULL),
		m_pComEnumerator(NULL)
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

	// 创建实例
	IApplication* CreateApplication(void)
	{
		return (new CApplication);
	}

}