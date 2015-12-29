#pragma once

#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgDB/DatabasePager>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/IOsgViewConfig.h"

class COsgConfig : public SimView::IOsgViewConfig
{
public:
	COsgConfig(HWND hWnd);
	~COsgConfig();

	// 获得视图名称
	virtual SVString GetName(void) const;
	// 初始化操作器
	virtual void InitManipulator(osgGA::KeySwitchMatrixManipulator* pMainpulator);
	// 初始化视图
	virtual void InitContextTraits(osg::GraphicsContext::Traits* pTraits);

private:
	HWND m_hWnd;
};
