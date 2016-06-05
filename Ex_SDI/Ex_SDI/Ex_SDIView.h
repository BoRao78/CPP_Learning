
// Ex_SDIView.h : CEx_SDIView 类的接口
//

#pragma once


class CEx_SDIView : public CView
{
protected: // 仅从序列化创建
	CEx_SDIView();
	DECLARE_DYNCREATE(CEx_SDIView)

// 特性
public:
	CEx_SDIDoc* GetDocument() const;
	BOOL m_bShow;
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
	virtual ~CEx_SDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnViewMouse();
	afx_msg void OnUpdateViewMouse(CCmdUI *pCmdUI);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Ex_SDIView.cpp 中的调试版本
inline CEx_SDIDoc* CEx_SDIView::GetDocument() const
   { return reinterpret_cast<CEx_SDIDoc*>(m_pDocument); }
#endif

