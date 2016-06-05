
// Ex_SDIView.h : CEx_SDIView ��Ľӿ�
//

#pragma once


class CEx_SDIView : public CView
{
protected: // �������л�����
	CEx_SDIView();
	DECLARE_DYNCREATE(CEx_SDIView)

// ����
public:
	CEx_SDIDoc* GetDocument() const;
	BOOL m_bShow;
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
	virtual ~CEx_SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewMouse();
	afx_msg void OnUpdateViewMouse(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex_SDIView.cpp �еĵ��԰汾
inline CEx_SDIDoc* CEx_SDIView::GetDocument() const
   { return reinterpret_cast<CEx_SDIDoc*>(m_pDocument); }
#endif

