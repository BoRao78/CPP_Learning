// WIN_MFC_KBView.h : CWIN_MFC_KBView 类的接口
//

#pragma once


class CWIN_MFC_KBView : public CView
{
protected: // 仅从序列化创建
	CWIN_MFC_KBView();
	DECLARE_DYNCREATE(CWIN_MFC_KBView)

// 特性
public:
	CWIN_MFC_KBDoc* GetDocument() const;

	//以下定义输出的字符串。
	const TCHAR *cUp = _T("You had hitted the UP key");
	const TCHAR *cCtrl = _T("You had hitted the Ctrl key");
	const TCHAR *cShift = _T("You had hitted the SHIFT key");
	const TCHAR *cCtrl_A = _T("You had hitted the CTRL A key");
	const TCHAR *cShift_B = _T("You had hitted the SHIFT B key");

	//下面定义并初始化按键标志变量。
	BOOL	nUpKeyDown, nShiftKeyDown, nCtrlKeyDown, nCtrlAKeyDown, nShiftBKeyDown, nOtherKeyDown;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CWIN_MFC_KBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // WIN_MFC_KBView.cpp 中的调试版本
inline CWIN_MFC_KBDoc* CWIN_MFC_KBView::GetDocument() const
   { return reinterpret_cast<CWIN_MFC_KBDoc*>(m_pDocument); }
#endif

