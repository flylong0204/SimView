#define OSGEARTH_DLL

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgEarth/OsgEarth.h"
#include "OsgEarth.h"
#include "OsgEarthPlugin.h"

namespace SimView
{
	// 构造函数
	COsgEarthPlugin::COsgEarthPlugin(const SVString& strName)
		:CPluginImp<COsgEarthPlugin>(strName)
	{
	}

	// 析构函数
	COsgEarthPlugin::~COsgEarthPlugin()
	{
	}

	// 安装函数
	void COsgEarthPlugin::Install(void)
	{
		m_pIComBaseFactory = new COsgEarthFactory;
	}

	// 版本函数
	SimView::CPluginVersion COsgEarthPlugin::GetVersion(void)
	{
		CPluginVersion version(0, 0, 1, 20151028);
		return (version);
	}

}
