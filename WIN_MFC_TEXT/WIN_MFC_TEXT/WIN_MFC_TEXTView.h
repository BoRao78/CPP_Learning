#include "tchar.h"
// WIN_MFC_TEXTView.h : CWIN_MFC_TEXTView 类的接口
//

#pragma once


class CWIN_MFC_TEXTView : public CView
{
protected: // 仅从序列化创建
	CWIN_MFC_TEXTView();
	DECLARE_DYNCREATE(CWIN_MFC_TEXTView)

	// 特性
public:
	CWIN_MFC_TEXTDoc* GetDocument() const;

	// 操作
public:
	int Xchar, Ychar;
	SIZE size;
	LPCTSTR pstring[3];
	RECT	rect;					//无效矩形区
	HFONT holdFont, hnewFont;
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
	virtual ~CWIN_MFC_TEXTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // WIN_MFC_TEXTView.cpp 中的调试版本
inline CWIN_MFC_TEXTDoc* CWIN_MFC_TEXTView::GetDocument() const
   { return reinterpret_cast<CWIN_MFC_TEXTDoc*>(m_pDocument); }
#endif

