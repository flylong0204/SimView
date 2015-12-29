#define OSGRENDER_DLL

#include <windows.h>
#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "OsgViewer.h"
#include "OsgViewerThread.h"
#include "OsgRender.h"

#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "osgGAd.lib")

namespace SimView
{
	// ��������
	SVString COsgRenderFactory::FACTORY_TYPE_NAME = COMTYPE_OSGRENDER;
	//////////////////////////////////////////////////////////////////////////

	// ���캯��
	COsgRender::COsgRender()
		:m_pOsgViewer(NULL),m_pOsgViewerThread(NULL)
	{
	}

	// ��������
	COsgRender::~COsgRender()
	{
		SIMVIEW_DELETE(m_pOsgViewerThread);
		SIMVIEW_DELETE(m_pOsgViewer);
	}


	void COsgRender::SetName(const SVString& strName)
	{
		m_strName = strName;
	}

	const SVString& COsgRender::GetName(void) const
	{
		return m_strName;
	}

	const SVString& COsgRender::GetTypeName(void) const
	{
		return COsgRenderFactory::FACTORY_TYPE_NAME;
	}

	void COsgRender::Init(void)
	{
		m_pOsgViewer = new COsgViewer();
	}

	// �����߳�����
	void COsgRender::RunByThread(void)
	{
		if (NULL == m_pOsgViewerThread)
		{
			m_pOsgViewerThread = new COsgViewerThread(m_pOsgViewer);
		}
		m_pOsgViewerThread->Start();
	}

	// ������ͼ
	void COsgRender::CreateView(IOsgViewConfig* pIOsgViewConfig)
	{
		m_pOsgViewer->Create(pIOsgViewConfig);
	}

	void COsgRender::AddRenderObj(void* pRenderObj, const SVString& strViewName /*= "MainView"*/)
	{
		IOsgView* pIOsgView = m_pOsgViewer->GetView(strViewName);
		if (NULL == pIOsgView)
		{
			SIMVIEW_EXCEPT(CConvertException::ERR_ITEM_NOT_FOUND, strViewName + "��ͼ������", "AddRenderObj");
		}

		pIOsgView->AddRenderObj(pRenderObj);
	}

}
