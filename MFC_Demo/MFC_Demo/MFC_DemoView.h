
// MFC_DemoView.h : CMFC_DemoView 类的接口
//

#pragma once


class CMFC_DemoView : public CView
{
protected: // 仅从序列化创建
	CMFC_DemoView();
	DECLARE_DYNCREATE(CMFC_DemoView)

// 特性
public:
	CMFC_DemoDoc* GetDocument() const;
//
	COLORREF	m_nColors[3]; //用户可选颜色数组
	DWORD		m_nColorIndex;	  // 当前所选颜色索引
	CString		m_strShow;	  // 显示的内容
	BOOL			m_bShow;           // 是否显示

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
	virtual ~CMFC_DemoView();
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
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // MFC_DemoView.cpp 中的调试版本
inline CMFC_DemoDoc* CMFC_DemoView::GetDocument() const
   { return reinterpret_cast<CMFC_DemoDoc*>(m_pDocument); }
#endif

