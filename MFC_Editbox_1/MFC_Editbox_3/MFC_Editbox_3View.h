
// MFC_Editbox_3View.h : CMFC_Editbox_3View 类的接口
//

#pragma once


class CMFC_Editbox_3View : public CView
{
protected: // 仅从序列化创建
	CMFC_Editbox_3View();
	DECLARE_DYNCREATE(CMFC_Editbox_3View)

// 特性
public:
	CMFC_Editbox_3Doc* GetDocument() const;

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
	virtual ~CMFC_Editbox_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_Editbox_3View.cpp 中的调试版本
inline CMFC_Editbox_3Doc* CMFC_Editbox_3View::GetDocument() const
   { return reinterpret_cast<CMFC_Editbox_3Doc*>(m_pDocument); }
#endif

