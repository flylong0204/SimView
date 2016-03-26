/**************************************************
outher: LJ
time: 2016-03-23
use: ����ӿ�
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
		// ��������
		virtual ~IEarth(void) { }
		// ��������ϵ
		virtual void SetCoord(const SVString& strCoord) = 0;
		// ��������ϵ
		virtual osgEarth::SpatialReference* GetCoord(void) = 0;
		// ���ģ�͵�������
		virtual void AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight) = 0;
		// ��ø�ģ��
		virtual osg::Node* GetRootNode(void) = 0;
		// ���ͨ��λ�þ�γ�߶�
		virtual void GetLongLatHightByPoint(float x, float y, double& lat, double& lon, double& height, \
			const SVString& strViewName = "mainView") = 0;
	};
}

#endif // !_PUBLIC_IEARTH_H_
