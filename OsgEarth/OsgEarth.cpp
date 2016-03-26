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
	// ��������
	SVString COsgEarthFactory::FACTORY_TYPE_NAME = COMTYPE_OSGEARTH;
	//////////////////////////////////////////////////////////////////////////

	// ���캯��
	COsgEarth::COsgEarth(void) :m_pOsgEarthManage(NULL)
	{
	}

	// ��������
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
		// ���������ļ�
		m_pEarthConfig = new COsgEarhConfig;

		// ����ռ�
		m_pEarthRoot = new osg::Group;
		// ��ӵ���ڵ�
		osgEarth::MapNode* pEarthMapNode = static_cast<osgEarth::MapNode*>(m_pOsgEarthManage->GetEarthMapNode());
		// ����ڵ������Ƿ�Ϊ��
		if (NULL == pEarthMapNode)
		{
			return;
		}
		m_pEarthRoot->addChild(pEarthMapNode);
		m_pEarthRoot->addChild(m_pOsgEarthManage->GetRoot());

		// ���ò�����
		
		
	}

	// ��ӵ���Ⱦ��
	void COsgEarth::DrawEarth(void)
	{
		// �����Ⱦ���
		IOsgRender* pIOsgRender = CApplicationImp<IOsgRender>::GetComposition(COMNAME_OSGRENDER);
		if (NULL == pIOsgRender)
		{
			ILogManage::GetSingleton().RecordLog("��Ⱦ���ʧ��");
			return;
		}

		// �����ͼ
		IOsgView* pIOsgView = pIOsgRender->GetView(m_pOsgEarthManage->GetView());
		if (NULL == pIOsgView)
		{
			ILogManage::GetSingleton().RecordLog("��Ⱦ��ͼ������");
			return;
		}

		pIOsgView->AddRenderObj(m_pEarthRoot);

		// ���ò�����
		SetEarthManipulator();
	}

	// ������ֵ������ڵ�
	IOsgEarthManage* COsgEarth::GetOsgEarhManage(void) const
	{
		return (m_pOsgEarthManage);
	}

	// ���ò�����
	void COsgEarth::SetEarthManipulator(void)
	{
		if (!COsgEarthManage::GetSingleton().IsChangeView())
		{
			return;
		}

		// �����Ⱦ����
		IOsgRender* pIOsgRender = CApplicationImp<IOsgRender>::GetComposition(COMNAME_OSGRENDER);
		if (NULL == pIOsgRender)
		{
			ILogManage::GetSingleton().RecordLog("��ȡ��Ⱦ���ʧ�ܣ��޷���ʼ��������");
			return;
		}

		const SVString strViewName = COsgEarthManage::GetSingleton().GetView();
		IOsgView* pIOsgView = pIOsgRender->GetView(strViewName);
		if (NULL == pIOsgRender)
		{
			ILogManage::GetSingleton().RecordLog("��ȡ��Ⱦ��ͼ" + strViewName + "��ʧ�ܣ��޷���ʼ��������");
			return;
		}

		osgEarth::Util::EarthManipulator* pEarthManip = new osgEarth::Util::EarthManipulator;
		pIOsgView->AddCameraManipulator("EarthManipulator", pEarthManip);
		
		// ѡ��ǰ������
		pIOsgView->SelectCameraManipulator("EarthManipulator");
	}

}

