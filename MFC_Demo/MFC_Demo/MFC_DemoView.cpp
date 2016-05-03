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
	CClientDC hdc(this);
	SetMapMode(hdc, MM_ANISOTROPIC);       //����ӳ��ģʽ
	HPEN hP = (HPEN)GetStockObject(BLACK_PEN);	//��ɫ����
	HBRUSH hB = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //��ˢ
	SelectObject(hdc, hB);   //ѡ��ˢ
	SelectObject(hdc, hP);       //ѡ�񻭱�
	RoundRect(hdc, 50, 120, 100, 200, 15, 15); //����Բ�Ǿ���
	hB = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  //��������ɫ��ˢ
	SelectObject(hdc, hB);  	   //ѡ��ˢ
	Ellipse(hdc, 150, 50, 200, 150); 	   //������Բ
	hB = (HBRUSH)GetStockObject(HOLLOW_BRUSH); //�黭ˢ
	SelectObject(hdc, hB);  	  //ѡ��ˢ
	Pie(hdc, 250, 50, 300, 100, 250, 50, 300, 50);  	//���Ʊ���

	hP = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
	hB = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 255, 0));
	SelectObject(hdc, hP);
	SelectObject(hdc, hB);
	RoundRect(hdc, 35, 220, 115, 270, 15, 15);
	Ellipse(hdc, 125, 170, 225, 220);
	Pie(hdc, 250, 120, 300, 170, 300, 120, 300, 170);

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
