
// WIN_MFC_MSView.h : CWIN_MFC_MSView 类的接口
//

#pragma once


class CWIN_MFC_MSView : public CView
{
protected: // 仅从序列化创建
	CWIN_MFC_MSView();
	DECLARE_DYNCREATE(CWIN_MFC_MSView)

// 特性
public:
	CWIN_MFC_MSDoc* GetDocument() const;

// 操作
public:
	BOOL  operate, ready;//operate为按下左键标识，ready为绘制初始图形标识
	BOOL  origin ;
	POINT BeginP, EndP;
	RECT rect;
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
	virtual ~CWIN_MFC_MSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // WIN_MFC_MSView.cpp 中的调试版本
inline CWIN_MFC_MSDoc* CWIN_MFC_MSView::GetDocument() const
   { return reinterpret_cast<CWIN_MFC_MSDoc*>(m_pDocument); }
#endif

