/**************************************************
outher: LJ
time: 2016-03-25
use: �������ʵ����
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
		// ���캯��
		explicit COsgEarthManage(COsgEarth* pOsgEarth);
		// ��������
		virtual ~COsgEarthManage();

	public:
		// ����һ����ʾ��ͼ���� Ĭ��������ͼ��
		virtual void SetView(const SVString& strViewName = "MainView");
		// �����ͼ����
		virtual SVString GetView(void) const ;
		// ��������ϵͳ
		virtual void SetCoordSystem(const SVString& strName = "wsg84");
		// �������ϵͳ
		virtual SVString GetCoordSystem(void) const;
		// ��õ�ͼ�ڵ�
		virtual EarthMapNode* GetEarthMapNode(void) const;
		// ��������µĵ�����Ϣ
		virtual CDoublePoint3D GetGeo(const CFloatPoint2D& vPt, const SVString& strViewName = "MainView") ;
		// ��������µĵ�����Ϣ
		virtual void GetGeo(const CFloatPoint2D& vPt, double& dLat, double& dLon, double& dHeight, const SVString& strViewName = "MainView") ;
		// ���ʵ��ģ�͵�������
		virtual void AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight);
		// ���ʵ��ģ�͵�������
		virtual void AddModel(IEntity* pIEntity, const CDoublePoint3D& vPt) ;

	public:
		// ���õ���ڵ�
		void SetMapNode(osgEarth::MapNode* pEarthMapNode);
		// ���ظ��ڵ�
		inline osg::Group* GetRoot(void) { return (m_pEarthRoot);  }
		// �ж��Ƿ������ͼ��ʾ
		bool IsChangeView(void);

	protected:
		// ��ʼ��
		void Init(void);

	private:
		SVString m_strViewName; // ��ʾ��ͼ������
		SVString m_strCoord; // ����ϵͳ
		osgEarth::MapNode* m_pMapNode; // ����ָ��
		osgEarth::SpatialReference* m_pSpatialRef; // ����ϵָ��
		osg::Group* m_pEarthRoot; // �����Ŀ¼
		COsgEarth* m_pOsgEarth; // ������
		bool m_bChange; // �Ƿ������ͼ
	};

}

#endif // !_OSGEARTHMANAGE_H_