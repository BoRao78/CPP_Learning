
// MFC_DemoView.h : CMFC_DemoView ��Ľӿ�
//

#pragma once


class CMFC_DemoView : public CView
{
protected: // �������л�����
	CMFC_DemoView();
	DECLARE_DYNCREATE(CMFC_DemoView)

// ����
public:
	CMFC_DemoDoc* GetDocument() const;

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
	virtual ~CMFC_DemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_DemoView.cpp �еĵ��԰汾
inline CMFC_DemoDoc* CMFC_DemoView::GetDocument() const
   { return reinterpret_cast<CMFC_DemoDoc*>(m_pDocument); }
#endif

