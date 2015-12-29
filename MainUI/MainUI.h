
// MainUI.h : MainUI Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMainUIApp:
// �йش����ʵ�֣������ MainUI.cpp
//

namespace SimView
{
	class IApplication;
}

class CMainUIApp : public CWinAppEx
{
public:
	CMainUIApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	SimView::IApplication* m_pIApp;
};

extern CMainUIApp theApp;
