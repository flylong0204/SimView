#define OSGRENDER_DLL

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "OsgRender.h"
#include "OsgRenderPlugin.h"

namespace SimView
{
	// 构造函数
	COsgRenderPlugin::COsgRenderPlugin(const SVString& strName)
		:CPluginImp<COsgRenderPlugin>(strName)
	{
	}

	// 析构函数
	COsgRenderPlugin::~COsgRenderPlugin()
	{
	}

	void COsgRenderPlugin::Install(void)
	{
		m_pIComBaseFactory = new COsgRenderFactory;
	}

	CPluginVersion COsgRenderPlugin::GetVersion(void)
	{
		CPluginVersion version(0, 0, 1, 20151028);
		return (version);
	}
}
