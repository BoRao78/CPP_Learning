// WIN_MFC_KBView.h : CWIN_MFC_KBView ��Ľӿ�
//

#pragma once


class CWIN_MFC_KBView : public CView
{
protected: // �������л�����
	CWIN_MFC_KBView();
	DECLARE_DYNCREATE(CWIN_MFC_KBView)

// ����
public:
	CWIN_MFC_KBDoc* GetDocument() const;

	//���¶���������ַ�����
	const TCHAR *cUp = _T("You had hitted the UP key");
	const TCHAR *cCtrl = _T("You had hitted the Ctrl key");
	const TCHAR *cShift = _T("You had hitted the SHIFT key");
	const TCHAR *cCtrl_A = _T("You had hitted the CTRL A key");
	const TCHAR *cShift_B = _T("You had hitted the SHIFT B key");

	//���涨�岢��ʼ��������־������
	BOOL	nUpKeyDown, nShiftKeyDown, nCtrlKeyDown, nCtrlAKeyDown, nShiftBKeyDown, nOtherKeyDown;

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
	virtual ~CWIN_MFC_KBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // WIN_MFC_KBView.cpp �еĵ��԰汾
inline CWIN_MFC_KBDoc* CWIN_MFC_KBView::GetDocument() const
   { return reinterpret_cast<CWIN_MFC_KBDoc*>(m_pDocument); }
#endif

