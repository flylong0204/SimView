#define OSGRENDER_DLL

#include <windows.h>
#include <osgViewer/CompositeViewer>
#include "../Public/Kerner/Kerner.h"
#include "OsgViewer.h"
#include "OsgViewerThread.h"

namespace SimView
{
	// 构造函数
	COsgViewerThread::COsgViewerThread(COsgViewer* pOsgViewer)
		:CSimViewThread(), m_pOsgViewer(pOsgViewer), m_bDone(false)
	{
	}

	// 析构函数
	COsgViewerThread::~COsgViewerThread()
	{
		// 停止运行
		m_bDone = true;
		Join();
	}

	// 运行处理函数
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