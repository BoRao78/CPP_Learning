#include "tchar.h"
#define UNICODE
// MFC_DemoView.cpp : CMFC_DemoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_Demo.h"
#endif

#include "MFC_DemoDoc.h"
#include "MFC_DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DemoView

IMPLEMENT_DYNCREATE(CMFC_DemoView, CView)

BEGIN_MESSAGE_MAP(CMFC_DemoView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC_DemoView ����/����

CMFC_DemoView::CMFC_DemoView(){
	// TODO: �ڴ˴���ӹ������
	m_nColors[0] = RGB(255, 0, 0);
	m_nColors[1] = RGB(0, 255, 0);
	m_nColors[2] = RGB(0, 0, 255);
	m_nColorIndex = 0;
	m_strShow = "Hello World!";
	m_bShow = TRUE;
}

CMFC_DemoView::~CMFC_DemoView()
{
}

BOOL CMFC_DemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_DemoView ����

void CMFC_DemoView::OnDraw(CDC* pDC)
{
	CMFC_DemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (m_bShow)
	{
		pDC->SetTextColor(m_nColors[m_nColorIndex]);
		// ��������ַ�����ɫ
		pDC->TextOut(100, 100, m_strShow);   // ����ַ���
	}

}


// CMFC_DemoView ��ӡ

BOOL CMFC_DemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_DemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_DemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFC_DemoView ���

#ifdef _DEBUG
void CMFC_DemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_DemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_DemoDoc* CMFC_DemoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DemoDoc)));
	return (CMFC_DemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DemoView ��Ϣ�������


void CMFC_DemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	dc.TextOut(100, 140, _T("You have pressed the left button of the mouse!"));

	CView::OnLButtonDown(nFlags, point);
}


void CMFC_DemoView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str1, str2;
	str1 = "You have pressed "; str2 = " !";
	str1 += wchar_t(nChar); str1 += str2;
	CClientDC dc(this);
	dc.TextOut(100, 120, str1);

	CView::OnChar(nChar, nRepCnt, nFlags);
}
