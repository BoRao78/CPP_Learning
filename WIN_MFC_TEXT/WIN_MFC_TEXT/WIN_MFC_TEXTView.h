#include "tchar.h"
// WIN_MFC_TEXTView.h : CWIN_MFC_TEXTView ��Ľӿ�
//

#pragma once


class CWIN_MFC_TEXTView : public CView
{
protected: // �������л�����
	CWIN_MFC_TEXTView();
	DECLARE_DYNCREATE(CWIN_MFC_TEXTView)

	// ����
public:
	CWIN_MFC_TEXTDoc* GetDocument() const;

	// ����
public:
	int Xchar, Ychar;
	SIZE size;
	LPCTSTR pstring[3];
	RECT	rect;					//��Ч������
	HFONT holdFont, hnewFont;
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
	virtual ~CWIN_MFC_TEXTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WIN_MFC_TEXTView.cpp �еĵ��԰汾
inline CWIN_MFC_TEXTDoc* CWIN_MFC_TEXTView::GetDocument() const
   { return reinterpret_cast<CWIN_MFC_TEXTDoc*>(m_pDocument); }
#endif

