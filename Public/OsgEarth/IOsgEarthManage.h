/**************************************************
outher: LJ
time: 2016-03-25
use: ��������ṩ�ӿ�
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
		// ��������
		virtual ~IOsgEarthManage(void) { }
		// ����һ����ʾ��ͼ���� Ĭ��������ͼ��
		virtual void SetView(const SVString& strViewName = "MainView") = 0;
		// �����ͼ����
		virtual SVString GetView(void) const = 0;
		// ��������ϵͳ
		virtual void SetCoordSystem(const SVString& strName = "wsg84") = 0;
		// �������ϵͳ
		virtual SVString GetCoordSystem(void) const = 0;
		// ��õ�ͼ�ڵ�
		virtual EarthMapNode* GetEarthMapNode(void) const = 0;
		// ��������µĵ�����Ϣ
		virtual CDoublePoint3D GetGeo(const CFloatPoint2D& vPt, const SVString& strViewName = "MainView") = 0;
		// ��������µĵ�����Ϣ
		virtual void GetGeo(const CFloatPoint2D& vPt, double& dLat, double& dLon, double& dHeight, const SVString& strViewName = "MainView") = 0;
		// ���ʵ��ģ�͵�������
		virtual void AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight) = 0;
		// ���ʵ��ģ�͵�������
		virtual void AddModel(IEntity* pIEntity, const CDoublePoint3D& vPt) = 0;
	};
}

#endif // !_PUBLIC_IOSGEARTHMANAGE_H_
