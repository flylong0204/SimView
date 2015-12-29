
// MainUIView.h : CMainUIView ��Ľӿ�
//

#pragma once

class COsgConfig;

class CMainUIView : public CView
{
protected: // �������л�����
	CMainUIView();
	DECLARE_DYNCREATE(CMainUIView)

// ����
public:
	CMainUIDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMainUIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	COsgConfig* m_pOsgConfig;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // MainUIView.cpp �еĵ��԰汾
inline CMainUIDoc* CMainUIView::GetDocument() const
   { return reinterpret_cast<CMainUIDoc*>(m_pDocument); }
#endif

