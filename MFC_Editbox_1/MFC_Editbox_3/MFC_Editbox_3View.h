
// MFC_Editbox_3View.h : CMFC_Editbox_3View ��Ľӿ�
//

#pragma once


class CMFC_Editbox_3View : public CView
{
protected: // �������л�����
	CMFC_Editbox_3View();
	DECLARE_DYNCREATE(CMFC_Editbox_3View)

// ����
public:
	CMFC_Editbox_3Doc* GetDocument() const;

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
	virtual ~CMFC_Editbox_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_Editbox_3View.cpp �еĵ��԰汾
inline CMFC_Editbox_3Doc* CMFC_Editbox_3View::GetDocument() const
   { return reinterpret_cast<CMFC_Editbox_3Doc*>(m_pDocument); }
#endif

