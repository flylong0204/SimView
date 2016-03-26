#define OSGEARTH_DLL

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "../Public/OsgEarth/OsgEarth.h"
#include "OsgEarthManage.h"
#include "OsgEarth.h"

#include "OsgEarhConfig.h"

#include <osgEarthUtil/EarthManipulator>

#ifdef _DEBUG
#pragma comment(lib, "../Debug/Kerner.lib")

#endif // _DEBUG

#ifdef _DEBUG
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgUtild.lib")
#pragma comment(lib, "osgGAd.lib")
#pragma comment(lib, "osgTextd.lib")
#pragma comment(lib, "osgEarthd.lib")
#pragma comment(lib, "osgEarthUtild.lib")
#pragma comment(lib, "osgEarthAnnotationd.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgUtil.lib")
#pragma comment(lib, "osgGA.lib")
#pragma comment(lib, "osgText.lib")
#pragma comment(lib, "osgEarth.lib")
#pragma comment(lib, "osgEarthUtil.lib")
#pragma comment(lib, "osgEarthAnnotation.lib")
#endif 



namespace SimView
{
	// 工厂类型
	SVString COsgEarthFactory::FACTORY_TYPE_NAME = COMTYPE_OSGEARTH;
	//////////////////////////////////////////////////////////////////////////

	// 构造函数
	COsgEarth::COsgEarth(void) :m_pOsgEarthManage(NULL)
	{
	}

	// 析构函数
	COsgEarth::~COsgEarth(void)
	{
		SIMVIEW_DELETE(m_pEarthConfig);
		SIMVIEW_DELETE(m_pOsgEarthManage);
	}

	void COsgEarth::SetName(const SVString& strName)
	{
		m_strName = strName;
	}

	const SVString& COsgEarth::GetName(void) const
	{
		return m_strName;
	}

	const SVString& COsgEarth::GetTypeName(void) const
	{
		return COsgEarthFactory::FACTORY_TYPE_NAME;
	}

	void COsgEarth::Init(void)
	{
		m_pOsgEarthManage = new COsgEarthManage(this);
		// 创建配置文件
		m_pEarthConfig = new COsgEarhConfig;

		// 分配空间
		m_pEarthRoot = new osg::Group;
		// 添加地球节点
		osgEarth::MapNode* pEarthMapNode = static_cast<osgEarth::MapNode*>(m_pOsgEarthManage->GetEarthMapNode());
		// 地球节点数据是否为空
		if (NULL == pEarthMapNode)
		{
			return;
		}
		m_pEarthRoot->addChild(pEarthMapNode);
		m_pEarthRoot->addChild(m_pOsgEarthManage->GetRoot());

		// 设置操作器
		
		
	}

	// 添加到渲染体
	void COsgEarth::DrawEarth(void)
	{
		// 获得渲染插件
		IOsgRender* pIOsgRender = CApplicationImp<IOsgRender>::GetComposition(COMNAME_OSGRENDER);
		if (NULL == pIOsgRender)
		{
			ILogManage::GetSingleton().RecordLog("渲染插件失败");
			return;
		}

		// 获得视图
		IOsgView* pIOsgView = pIOsgRender->GetView(m_pOsgEarthManage->GetView());
		if (NULL == pIOsgView)
		{
			ILogManage::GetSingleton().RecordLog("渲染视图不存在");
			return;
		}

		pIOsgView->AddRenderObj(m_pEarthRoot);

		// 设置操作器
		SetEarthManipulator();
	}

	// 获得数字地球管理节点
	IOsgEarthManage* COsgEarth::GetOsgEarhManage(void) const
	{
		return (m_pOsgEarthManage);
	}

	// 设置操作器
	void COsgEarth::SetEarthManipulator(void)
	{
		if (!COsgEarthManage::GetSingleton().IsChangeView())
		{
			return;
		}

		// 获得渲染对象
		IOsgRender* pIOsgRender = CApplicationImp<IOsgRender>::GetComposition(COMNAME_OSGRENDER);
		if (NULL == pIOsgRender)
		{
			ILogManage::GetSingleton().RecordLog("获取渲染插件失败，无法初始化操作器");
			return;
		}

		const SVString strViewName = COsgEarthManage::GetSingleton().GetView();
		IOsgView* pIOsgView = pIOsgRender->GetView(strViewName);
		if (NULL == pIOsgRender)
		{
			ILogManage::GetSingleton().RecordLog("获取渲染视图" + strViewName + "件失败，无法初始化操作器");
			return;
		}

		osgEarth::Util::EarthManipulator* pEarthManip = new osgEarth::Util::EarthManipulator;
		pIOsgView->AddCameraManipulator("EarthManipulator", pEarthManip);
		
		// 选择当前操作器
		pIOsgView->SelectCameraManipulator("EarthManipulator");
	}

}

