
// MainUIView.cpp : CMainUIView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MainUI.h"
#endif

#include "MainUIDoc.h"
#include "MainUIView.h"

#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "OsgConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainUIView

IMPLEMENT_DYNCREATE(CMainUIView, CView)

BEGIN_MESSAGE_MAP(CMainUIView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMainUIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainUIView ����/����

CMainUIView::CMainUIView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMainUIView::~CMainUIView()
{
	SIMVIEW_DELETE(m_pOsgConfig);
}

BOOL CMainUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMainUIView ����

void CMainUIView::OnDraw(CDC* /*pDC*/)
{
	CMainUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMainUIView ��ӡ


void CMainUIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMainUIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMainUIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMainUIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

void CMainUIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMainUIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMainUIView ���

#ifdef _DEBUG
void CMainUIView::AssertValid() const
{
	CView::AssertValid();
}

void CMainUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMainUIDoc* CMainUIView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMainUIDoc)));
	return (CMainUIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMainUIView ��Ϣ�������


int CMainUIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_pOsgConfig = new COsgConfig(m_hWnd);

	return 0;
}


void CMainUIView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO:  �ڴ����ר�ô����/����û���
	// SimView::IPluginManage::GetSingleton().GetComInstance(SimView::COMNAME_OSGRENDER);
	SimView::IOsgRender* pIOsgRender = SimView::CApplicationImp<SimView::IOsgRender\
		>::GetComposition(SimView::COMNAME_OSGRENDER);
	if (NULL == pIOsgRender)
	{
		return;
	}

	//COsgConfig* pOsgConfig = new COsgConfig(m_hWnd);
	pIOsgRender->CreateView(m_pOsgConfig);

	osg::Node* pNode = osgDB::readNodeFile("D:\\Program Files\\OpenSceneGraph\\OpenSceneGraph-Data\\cow.osg");
	pIOsgRender->AddRenderObj(pNode);

	// ������Ⱦ�߳�
	pIOsgRender->RunByThread();
	
}
