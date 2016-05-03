
// WIN_MFC_MSView.h : CWIN_MFC_MSView ��Ľӿ�
//

#pragma once


class CWIN_MFC_MSView : public CView
{
protected: // �������л�����
	CWIN_MFC_MSView();
	DECLARE_DYNCREATE(CWIN_MFC_MSView)

// ����
public:
	CWIN_MFC_MSDoc* GetDocument() const;

// ����
public:
	BOOL  operate, ready;//operateΪ���������ʶ��readyΪ���Ƴ�ʼͼ�α�ʶ
	BOOL  origin ;
	POINT BeginP, EndP;
	RECT rect;
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
	virtual ~CWIN_MFC_MSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WIN_MFC_MSView.cpp �еĵ��԰汾
inline CWIN_MFC_MSDoc* CWIN_MFC_MSView::GetDocument() const
   { return reinterpret_cast<CWIN_MFC_MSDoc*>(m_pDocument); }
#endif

