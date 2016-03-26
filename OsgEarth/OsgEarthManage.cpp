#define OSGEARTH_DLL

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "../Public/OsgEarth/OsgEarth.h"
#include "OsgEarthManage.h"

#include <osgEarth/Terrain>

#include "OsgEarth.h"

namespace SimView
{
	COsgEarthManage::COsgEarthManage(COsgEarth* pOsgEarth)
		:m_strViewName("MainView"), m_pMapNode(NULL), \
		m_pSpatialRef(NULL), m_pOsgEarth(pOsgEarth), m_bChange(true)
	{
		Init();
	}


	COsgEarthManage::~COsgEarthManage()
	{
	}

	// 设置一个显示视图名称 默认在主视图中
	void COsgEarthManage::SetView(const SVString& strViewName)
	{
		if (0 == m_strViewName.compare(strViewName))
		{
			return;
		}

		m_strViewName = strViewName;
		m_bChange = true;
		m_pOsgEarth->DrawEarth();
	}

	// 获得视图名称
	SVString COsgEarthManage::GetView(void) const
	{
		return (m_strViewName);
	}

	// 设置一个显示视图名称 默认在主视图中
	void COsgEarthManage::SetCoordSystem(const SVString& strName)
	{
		m_strCoord = strName;

		m_pSpatialRef = osgEarth::SpatialReference::get(m_strCoord);
	}

	// 获得坐标系统
	SVString COsgEarthManage::GetCoordSystem(void) const
	{
		return (m_strCoord);
	}

	// 获得地图节点
	EarthMapNode* COsgEarthManage::GetEarthMapNode(void) const
	{
		return (m_pMapNode);
	}

	// 获得鼠标点下的地理信息
	CDoublePoint3D COsgEarthManage::GetGeo(const CFloatPoint2D& vPt, const SVString& strViewName)
	{
		CDoublePoint3D vGeo(-1.0, -1.0, -1.0);
		// 判断当前名称地图是否空
		if (NULL == m_pMapNode)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("地球地图节点为空");
			return (vGeo);
		}

		// 获得渲染插件
		IOsgRender* pIOsgRender = CApplicationImp<IOsgRender>::GetComposition(COMNAME_OSGRENDER);
		if (NULL == pIOsgRender)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("渲染插件为空");
			return (vGeo);
		}

		// 获得视图
		IOsgView* pIOsgView = pIOsgRender->GetView(strViewName);
		if (NULL == pIOsgView)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("视图为空");
			return (vGeo);
		}

		osg::View* pView = static_cast<osg::View*>(pIOsgView->GetView());
		if (NULL == pView)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("视图为空");
			return (vGeo);
		}

		osg::Vec3d ptWorld;
		bool bSucces = m_pMapNode->getTerrain()->getWorldCoordsUnderMouse(pView, vPt.x(), vPt.y(), ptWorld);
		// 获得经纬高度
		if (!bSucces)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("获得经纬度失败");
			return (vGeo);
		}

		// 计算获得经纬高度
		osgEarth::GeoPoint geoPoint;
		geoPoint.fromWorld(m_pSpatialRef, ptWorld);
		vGeo.set(geoPoint.x(), geoPoint.y(), geoPoint.z());
		return (vGeo);
	}

	// 获得鼠标点下的地理信息
	void COsgEarthManage::GetGeo(const CFloatPoint2D& vPt, double& dLat, double& dLon, double& dHeight, const SVString& strViewName /*= "MainView"*/)
	{
		CDoublePoint3D vGeo = GetGeo(vPt, strViewName);
		dLat = vGeo.x();
		dLon = vGeo.y();
		dHeight = vGeo.z();
	}

	// 添加实体模型到地球上
	void COsgEarthManage::AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight)
	{
		// 判断实体是否为空
		if (NULL == pIEntity)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("实体为空");
			return;
		}

		// 获得属性
		IBaseAttribute* pIBaseAttribute = pIEntity->GetBaseAttribute();
		if (NULL == pIBaseAttribute)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("实体" + pIEntity->GetName() + "基础属性为空");
			return;
		}

		CDoublePoint3D vPt(dLat, dLon, dHeight);
		pIBaseAttribute->SetPosition(vPt);

		// 获得渲染对象
		IDrawManager* pIDrawManager = pIEntity->GetDrawManager();
		if (NULL == pIDrawManager)
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog(pIEntity->GetName() + "渲染体为空");
			return;
		}

		// 设置地球属性
		pIDrawManager->SetMapNode(m_pMapNode);
		DrawObj* pDrawNode = pIDrawManager->GetDrawObj();
		// 转换节点类型
		osg::Node* pNode = static_cast<osg::Node*>(pDrawNode);
		m_pEarthRoot->addChild(pNode);
	}

	// 添加实体模型到地球上
	void COsgEarthManage::AddModel(IEntity* pIEntity, const CDoublePoint3D& vPt)
	{
		AddModel(pIEntity, vPt.x(), vPt.y(), vPt.z());
	}

	// 设置地球节点
	void COsgEarthManage::SetMapNode(osgEarth::MapNode* pEarthMapNode)
	{
		if (m_pMapNode != pEarthMapNode)
		{
			m_pMapNode = pEarthMapNode;
		}
		
	}

	bool COsgEarthManage::IsChangeView(void)
	{
		bool btemp = m_bChange;
		m_bChange = false;
		return (btemp);
	}

	// 初始化
	void COsgEarthManage::Init(void)
	{
		// 分配空间
		m_pEarthRoot = new osg::Group;
		// 初始化基础坐标系
		m_pSpatialRef = osgEarth::SpatialReference::get("wgs84");
		
	}

}
