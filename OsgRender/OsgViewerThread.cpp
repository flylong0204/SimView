#define OSGRENDER_DLL

#include <windows.h>
#include <osgViewer/CompositeViewer>
#include "../Public/Kerner/Kerner.h"
#include "OsgViewer.h"
#include "OsgViewerThread.h"

namespace SimView
{
	// ���캯��
	COsgViewerThread::COsgViewerThread(COsgViewer* pOsgViewer)
		:CSimViewThread(), m_pOsgViewer(pOsgViewer), m_bDone(false)
	{
	}

	// ��������
	COsgViewerThread::~COsgViewerThread()
	{
		// ֹͣ����
		m_bDone = true;
		Join();
	}

	// ���д�����
	void COsgViewerThread::Run(void)
	{
		osgViewer::CompositeViewer* pCompositeViewer = m_pOsgViewer->GetViewer();
		if (NULL != pCompositeViewer && !pCompositeViewer->done() && !m_bDone)
		{
			m_pOsgViewer->PreFrameUpdate();
			pCompositeViewer->frame();
			m_pOsgViewer->PostFrameUpdate();
		}
	}

}