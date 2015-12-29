
// MainUIView.cpp : CMainUIView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMainUIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainUIView 构造/析构

CMainUIView::CMainUIView()
{
	// TODO:  在此处添加构造代码

}

CMainUIView::~CMainUIView()
{
	SIMVIEW_DELETE(m_pOsgConfig);
}

BOOL CMainUIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMainUIView 绘制

void CMainUIView::OnDraw(CDC* /*pDC*/)
{
	CMainUIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMainUIView 打印


void CMainUIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMainUIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMainUIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMainUIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
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


// CMainUIView 诊断

#ifdef _DEBUG
void CMainUIView::AssertValid() const
{
	CView::AssertValid();
}

void CMainUIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMainUIDoc* CMainUIView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMainUIDoc)));
	return (CMainUIDoc*)m_pDocument;
}
#endif //_DEBUG


// CMainUIView 消息处理程序


int CMainUIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_pOsgConfig = new COsgConfig(m_hWnd);

	return 0;
}


void CMainUIView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO:  在此添加专用代码和/或调用基类
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

	// 启动渲染线程
	pIOsgRender->RunByThread();
	
}
