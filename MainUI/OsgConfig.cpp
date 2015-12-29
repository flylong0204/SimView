#include "stdafx.h"
#include "OsgConfig.h"

#ifdef _DEBUG
#pragma comment(lib, "osgd.lib")
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgGAd.lib")
#else
#pragma comment(lib, "osg.lib")
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgGA.lib")
#endif // _DEBUG

COsgConfig::COsgConfig(HWND hWnd)
:m_hWnd(hWnd)
{
}


COsgConfig::~COsgConfig()
{
}

SVString COsgConfig::GetName(void) const
{
	return ("MainView");
}

void COsgConfig::InitManipulator(osgGA::KeySwitchMatrixManipulator* pMainpulator)
{
	osgGA::TrackballManipulator* pTrackball = new osgGA::TrackballManipulator;
	pMainpulator->addMatrixManipulator('1', "Trackball", pTrackball);
	pMainpulator->selectMatrixManipulator(0);

}

// ≥ı ºªØ ”Õº
void COsgConfig::InitContextTraits(osg::GraphicsContext::Traits* pTraits)
{
	RECT rect;
	GetWindowRect(m_hWnd, &rect);

	osg::ref_ptr<osg::Referenced> windata = new osgViewer::GraphicsWindowWin32::WindowData(m_hWnd);

	// Setup the traits parameters
	pTraits->x = 0;
	pTraits->y = 0;
	pTraits->width = rect.right - rect.left;
	pTraits->height = rect.bottom - rect.top;
	pTraits->windowDecoration = false;
	pTraits->doubleBuffer = true;
	pTraits->sharedContext = 0;
	pTraits->setInheritedWindowPixelFormat = true;
	pTraits->inheritedWindowData = windata;
}
