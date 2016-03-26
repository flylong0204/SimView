#define OSGEARTH_DLL

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgEarth/OsgEarth.h"
#include "OsgEarth.h"
#include "OsgEarthPlugin.h"

namespace SimView
{
	// ���캯��
	COsgEarthPlugin::COsgEarthPlugin(const SVString& strName)
		:CPluginImp<COsgEarthPlugin>(strName)
	{
	}

	// ��������
	COsgEarthPlugin::~COsgEarthPlugin()
	{
	}

	// ��װ����
	void COsgEarthPlugin::Install(void)
	{
		m_pIComBaseFactory = new COsgEarthFactory;
	}

	// �汾����
	SimView::CPluginVersion COsgEarthPlugin::GetVersion(void)
	{
		CPluginVersion version(0, 0, 1, 20151028);
		return (version);
	}

}
