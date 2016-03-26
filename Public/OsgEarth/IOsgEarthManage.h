/**************************************************
outher: LJ
time: 2016-03-25
use: 地球管理提供接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGEARTHMANAGE_H_
#define _PUBLIC_IOSGEARTHMANAGE_H_

namespace SimView
{
	class OSG_EARTH_EXPORT IOsgEarthManage
	{
	public:
		// 析构函数
		virtual ~IOsgEarthManage(void) { }
		// 设置一个显示视图名称 默认在主视图中
		virtual void SetView(const SVString& strViewName = "MainView") = 0;
		// 获得视图名称
		virtual SVString GetView(void) const = 0;
		// 设置坐标系统
		virtual void SetCoordSystem(const SVString& strName = "wsg84") = 0;
		// 获得坐标系统
		virtual SVString GetCoordSystem(void) const = 0;
		// 获得地图节点
		virtual EarthMapNode* GetEarthMapNode(void) const = 0;
		// 获得鼠标点下的地理信息
		virtual CDoublePoint3D GetGeo(const CFloatPoint2D& vPt, const SVString& strViewName = "MainView") = 0;
		// 获得鼠标点下的地理信息
		virtual void GetGeo(const CFloatPoint2D& vPt, double& dLat, double& dLon, double& dHeight, const SVString& strViewName = "MainView") = 0;
		// 添加实体模型到地球上
		virtual void AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight) = 0;
		// 添加实体模型到地球上
		virtual void AddModel(IEntity* pIEntity, const CDoublePoint3D& vPt) = 0;
	};
}

#endif // !_PUBLIC_IOSGEARTHMANAGE_H_
