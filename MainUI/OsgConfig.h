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

	// �����ͼ����
	virtual SVString GetName(void) const;
	// ��ʼ��������
	virtual void InitManipulator(osgGA::KeySwitchMatrixManipulator* pMainpulator);
	// ��ʼ����ͼ
	virtual void InitContextTraits(osg::GraphicsContext::Traits* pTraits);

private:
	HWND m_hWnd;
};
