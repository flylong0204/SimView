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
		// 移除所有视图
		ListOsgView::iterator itor = m_lstOsgView.begin();
		for (; m_lstOsgView.end() != itor; ++itor)
		{
			RemoveView(itor->second);
		}

		SIMVIEW_DELETE(m_pCompositeViewer);
	}

	// 添加视图
	void COsgViewer::AddOsgView(COsgView* pOsgView)
	{
		m_pCompositeViewer->addView(pOsgView->GetView());
		m_lstOsgView[pOsgView->GetName()] = pOsgView;
	}

	// 获得视图对象
	IOsgView* COsgViewer::GetView(const SVString& strName) const
	{
		// 查询当前结果
		ListOsgView::const_iterator cstItor = m_lstOsgView.find(strName);
		if (NULL == cstItor->second)
		{
			ILogManage::GetSingleton().RecordLog("视图" + strName + "不存在");
			return (NULL);
		}

		return (cstItor->second);
	}

	// 获得组合视图
	osgViewer::CompositeViewer* COsgViewer::GetViewer(void) const
	{
		return (m_pCompositeViewer);
	}

	// 每一帧前需要处理的函数
	void COsgViewer::PreFrameUpdate(void)
	{

	}

	// 每一帧后要处理的函数
	void COsgViewer::PostFrameUpdate(void)
	{

	}

	// 移除视图
	void COsgViewer::RemoveView(COsgView* pOsgView)
	{
		SIMVIEW_DELETE(pOsgView);
	}

	// 创建一个视图
	void SimView::COsgViewer::Create(IOsgViewConfig* pIOsgViewConfig)
	{
		// 判断配置是否为空
		if (NULL == pIOsgViewConfig)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_CANNOT_WRITE_TO_FILE, "配置对象为空", \
				"IOsgViewer::Create");
		}

		// 写入日志
		const SVString& strName = pIOsgViewConfig->GetName();
		ILogManage::GetSingleton().RecordLog("创建视图" + strName);

		COsgView* pOsgView = new COsgView(pIOsgViewConfig);
		// 配置视图相关操作
		pOsgView->InitManipulator();
		pOsgView->InitCamera();

		// 添加到管理中
		AddOsgView(pOsgView);
		// 写入日志
		ILogManage::GetSingleton().RecordLog("成功创建视图" + strName);
	}

}