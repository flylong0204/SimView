/**************************************************
outher: LJ
time: 2016-03-23
use: 地球接口
from:
chanage:
change outher :
**************************************************/
#ifndef _PUBLIC_IEARTH_H_
#define _PUBLIC_IEARTH_H_

#include <osg/Node>
#include <osgEarth/SpatialReference>

namespace SimView
{
	class OSG_EARTH_EXPORT IEarth
	{
	public:
		// 析构函数
		virtual ~IEarth(void) { }
		// 设置坐标系
		virtual void SetCoord(const SVString& strCoord) = 0;
		// 设置坐标系
		virtual osgEarth::SpatialReference* GetCoord(void) = 0;
		// 添加模型到地球上
		virtual void AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight) = 0;
		// 获得根模型
		virtual osg::Node* GetRootNode(void) = 0;
		// 获得通过位置经纬高度
		virtual void GetLongLatHightByPoint(float x, float y, double& lat, double& lon, double& height, \
			const SVString& strViewName = "mainView") = 0;
	};
}

#endif // !_PUBLIC_IEARTH_H_
