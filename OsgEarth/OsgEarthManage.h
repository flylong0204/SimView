/**************************************************
outher: LJ
time: 2016-03-25
use: 地球管理实体类
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGEARTHMANAGE_H_
#define _OSGEARTHMANAGE_H_

#pragma once

#include <osgEarth/MapNode>

namespace SimView
{
	class COsgEarth;

	class COsgEarthManage : public CSingleton<COsgEarthManage>, public IOsgEarthManage
	{
	public:
		// 构造函数
		explicit COsgEarthManage(COsgEarth* pOsgEarth);
		// 析构函数
		virtual ~COsgEarthManage();

	public:
		// 设置一个显示视图名称 默认在主视图中
		virtual void SetView(const SVString& strViewName = "MainView");
		// 获得视图名称
		virtual SVString GetView(void) const ;
		// 设置坐标系统
		virtual void SetCoordSystem(const SVString& strName = "wsg84");
		// 获得坐标系统
		virtual SVString GetCoordSystem(void) const;
		// 获得地图节点
		virtual EarthMapNode* GetEarthMapNode(void) const;
		// 获得鼠标点下的地理信息
		virtual CDoublePoint3D GetGeo(const CFloatPoint2D& vPt, const SVString& strViewName = "MainView") ;
		// 获得鼠标点下的地理信息
		virtual void GetGeo(const CFloatPoint2D& vPt, double& dLat, double& dLon, double& dHeight, const SVString& strViewName = "MainView") ;
		// 添加实体模型到地球上
		virtual void AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight);
		// 添加实体模型到地球上
		virtual void AddModel(IEntity* pIEntity, const CDoublePoint3D& vPt) ;

	public:
		// 设置地球节点
		void SetMapNode(osgEarth::MapNode* pEarthMapNode);
		// 返回根节点
		inline osg::Group* GetRoot(void) { return (m_pEarthRoot);  }
		// 判断是否更改视图显示
		bool IsChangeView(void);

	protected:
		// 初始化
		void Init(void);

	private:
		SVString m_strViewName; // 显示视图的名称
		SVString m_strCoord; // 坐标系统
		osgEarth::MapNode* m_pMapNode; // 地球指针
		osgEarth::SpatialReference* m_pSpatialRef; // 坐标系指针
		osg::Group* m_pEarthRoot; // 地球根目录
		COsgEarth* m_pOsgEarth; // 地球插件
		bool m_bChange; // 是否更改视图
	};

}

#endif // !_OSGEARTHMANAGE_H_