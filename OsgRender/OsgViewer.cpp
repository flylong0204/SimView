#define OSGRENDER_DLL

#include <windows.h>
#include <osgViewer/CompositeViewer>
#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "../Public/OsgRender/IOsgViewConfig.h"
#include "OsgView.h"
#include "OsgViewer.h"

namespace SimView
{
	COsgViewer::COsgViewer()
		:m_pCompositeViewer(new osgViewer::CompositeViewer)
	{
	}


	COsgViewer::~COsgViewer()
	{
		// �Ƴ�������ͼ
		ListOsgView::iterator itor = m_lstOsgView.begin();
		for (; m_lstOsgView.end() != itor; ++itor)
		{
			RemoveView(*itor);
		}

		SIMVIEW_DELETE(m_pCompositeViewer);
	}

	// �����ͼ
	void COsgViewer::AddOsgView(COsgView* pOsgView)
	{
		osgViewer::View* pView = static_cast<osgViewer::View*>(pOsgView->GetView());
		if (NULL == pView)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_CONVERT_FAILD, "����ת��ʧ��", "AddOsgView");
		}
		m_pCompositeViewer->addView(pView);
		m_lstOsgView.push_back(pOsgView);
	}

	// �����ͼ����
	IOsgView* COsgViewer::GetView(const SVString& strName) const
	{
		// ��ѯ��ǰ���
		ListOsgView::const_iterator cstItor = m_lstOsgView.begin();
		for (; m_lstOsgView.end() != cstItor; ++cstItor)
		{
			if (0 == strName.compare((*cstItor)->GetName()))
			{
				return (*cstItor);
			}
		}
		
		// ������ 
		ILogManage::GetSingleton().RecordLog("��ͼ" + strName + "������");
		return (NULL);
	}

	// ��������ͼ
	osgViewer::CompositeViewer* COsgViewer::GetViewer(void) const
	{
		return (m_pCompositeViewer);
	}

	// ÿһ֡ǰ��Ҫ����ĺ���
	void COsgViewer::PreFrameUpdate(void)
	{

	}

	// ÿһ֡��Ҫ����ĺ���
	void COsgViewer::PostFrameUpdate(void)
	{

	}

	// �Ƴ���ͼ
	void COsgViewer::RemoveView(COsgView* pOsgView)
	{
		SIMVIEW_DELETE(pOsgView);
	}

	// ����һ����ͼ
	void SimView::COsgViewer::Create(IOsgViewConfig* pIOsgViewConfig)
	{
		// �ж������Ƿ�Ϊ��
		if (NULL == pIOsgViewConfig)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_CANNOT_WRITE_TO_FILE, "���ö���Ϊ��", \
				"IOsgViewer::Create");
		}

		// д����־
		const SVString& strName = pIOsgViewConfig->GetName();
		ILogManage::GetSingleton().RecordLog("������ͼ" + strName);

		COsgView* pOsgView = new COsgView(pIOsgViewConfig);
		// ������ͼ��ز���
		pOsgView->InitManipulator();
		pOsgView->InitCamera();

		// ��ӵ�������
		AddOsgView(pOsgView);
		// д����־
		ILogManage::GetSingleton().RecordLog("�ɹ�������ͼ" + strName);
	}

}