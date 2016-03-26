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

	// ����һ����ʾ��ͼ���� Ĭ��������ͼ��
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

	// �����ͼ����
	SVString COsgEarthManage::GetView(void) const
	{
		return (m_strViewName);
	}

	// ����һ����ʾ��ͼ���� Ĭ��������ͼ��
	void COsgEarthManage::SetCoordSystem(const SVString& strName)
	{
		m_strCoord = strName;

		m_pSpatialRef = osgEarth::SpatialReference::get(m_strCoord);
	}

	// �������ϵͳ
	SVString COsgEarthManage::GetCoordSystem(void) const
	{
		return (m_strCoord);
	}

	// ��õ�ͼ�ڵ�
	EarthMapNode* COsgEarthManage::GetEarthMapNode(void) const
	{
		return (m_pMapNode);
	}

	// ��������µĵ�����Ϣ
	CDoublePoint3D COsgEarthManage::GetGeo(const CFloatPoint2D& vPt, const SVString& strViewName)
	{
		CDoublePoint3D vGeo(-1.0, -1.0, -1.0);
		// �жϵ�ǰ���Ƶ�ͼ�Ƿ��
		if (NULL == m_pMapNode)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("�����ͼ�ڵ�Ϊ��");
			return (vGeo);
		}

		// �����Ⱦ���
		IOsgRender* pIOsgRender = CApplicationImp<IOsgRender>::GetComposition(COMNAME_OSGRENDER);
		if (NULL == pIOsgRender)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("��Ⱦ���Ϊ��");
			return (vGeo);
		}

		// �����ͼ
		IOsgView* pIOsgView = pIOsgRender->GetView(strViewName);
		if (NULL == pIOsgView)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("��ͼΪ��");
			return (vGeo);
		}

		osg::View* pView = static_cast<osg::View*>(pIOsgView->GetView());
		if (NULL == pView)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("��ͼΪ��");
			return (vGeo);
		}

		osg::Vec3d ptWorld;
		bool bSucces = m_pMapNode->getTerrain()->getWorldCoordsUnderMouse(pView, vPt.x(), vPt.y(), ptWorld);
		// ��þ�γ�߶�
		if (!bSucces)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("��þ�γ��ʧ��");
			return (vGeo);
		}

		// �����þ�γ�߶�
		osgEarth::GeoPoint geoPoint;
		geoPoint.fromWorld(m_pSpatialRef, ptWorld);
		vGeo.set(geoPoint.x(), geoPoint.y(), geoPoint.z());
		return (vGeo);
	}

	// ��������µĵ�����Ϣ
	void COsgEarthManage::GetGeo(const CFloatPoint2D& vPt, double& dLat, double& dLon, double& dHeight, const SVString& strViewName /*= "MainView"*/)
	{
		CDoublePoint3D vGeo = GetGeo(vPt, strViewName);
		dLat = vGeo.x();
		dLon = vGeo.y();
		dHeight = vGeo.z();
	}

	// ���ʵ��ģ�͵�������
	void COsgEarthManage::AddModel(IEntity* pIEntity, double dLat, double dLon, double dHeight)
	{
		// �ж�ʵ���Ƿ�Ϊ��
		if (NULL == pIEntity)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("ʵ��Ϊ��");
			return;
		}

		// �������
		IBaseAttribute* pIBaseAttribute = pIEntity->GetBaseAttribute();
		if (NULL == pIBaseAttribute)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("ʵ��" + pIEntity->GetName() + "��������Ϊ��");
			return;
		}

		CDoublePoint3D vPt(dLat, dLon, dHeight);
		pIBaseAttribute->SetPosition(vPt);

		// �����Ⱦ����
		IDrawManager* pIDrawManager = pIEntity->GetDrawManager();
		if (NULL == pIDrawManager)
		{
			// д����־
			ILogManage::GetSingleton().RecordLog(pIEntity->GetName() + "��Ⱦ��Ϊ��");
			return;
		}

		// ���õ�������
		pIDrawManager->SetMapNode(m_pMapNode);
		DrawObj* pDrawNode = pIDrawManager->GetDrawObj();
		// ת���ڵ�����
		osg::Node* pNode = static_cast<osg::Node*>(pDrawNode);
		m_pEarthRoot->addChild(pNode);
	}

	// ���ʵ��ģ�͵�������
	void COsgEarthManage::AddModel(IEntity* pIEntity, const CDoublePoint3D& vPt)
	{
		AddModel(pIEntity, vPt.x(), vPt.y(), vPt.z());
	}

	// ���õ���ڵ�
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

	// ��ʼ��
	void COsgEarthManage::Init(void)
	{
		// ����ռ�
		m_pEarthRoot = new osg::Group;
		// ��ʼ����������ϵ
		m_pSpatialRef = osgEarth::SpatialReference::get("wgs84");
		
	}

}
