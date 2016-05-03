
// WIN_MFC_TEXTView.cpp : CWIN_MFC_TEXTView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "WIN_MFC_TEXT.h"
#endif

#include "WIN_MFC_TEXTDoc.h"
#include "WIN_MFC_TEXTView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWIN_MFC_TEXTView

IMPLEMENT_DYNCREATE(CWIN_MFC_TEXTView, CView)

BEGIN_MESSAGE_MAP(CWIN_MFC_TEXTView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWIN_MFC_TEXTView ����/����

CWIN_MFC_TEXTView::CWIN_MFC_TEXTView()
{
	// TODO: �ڴ˴���ӹ������

}

CWIN_MFC_TEXTView::~CWIN_MFC_TEXTView()
{
}

BOOL CWIN_MFC_TEXTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.x = 0;
	cs.y = 0;
	cs.cx = GetSystemMetrics(SM_CXSCREEN) / 2;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) / 2;
	return CView::PreCreateWindow(cs);
}

// CWIN_MFC_TEXTView ����

void CWIN_MFC_TEXTView::OnDraw(CDC* pDC)
{
	CWIN_MFC_TEXTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pstring[0] = _T("ӭ���Ӹ�");
	pstring[1] = _T("ʱ������ϲ����");
	pstring[2] = _T("�����ٻ�������");

	hnewFont = CreateFont         			//����һ���µ��߼�����
		(48, 0, 0, 0, 500, 0, 0, 0,
			GB2312_CHARSET, //���ַ���֧�֡����塱��
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH & FF_DONTCARE,
			L"����");
	CClientDC hdc(this);

	holdFont = (HFONT)SelectObject(hdc, hnewFont);  //ѡ���µ�����
	SetTextColor(hdc, RGB(255, 255, 0));	 	//�����ı���ɫ
	SetBkColor(hdc, RGB(255, 0, 0));	 	//���ñ�����ɫ 
	GetTextExtentPoint32(hdc, pstring[0], 4, &size);

	rect = { 0, 0, GetSystemMetrics(SM_CXSCREEN)/4, GetSystemMetrics(SM_CYSCREEN)/4 };

	Xchar = (rect.right - rect.left) / 2 - size.cx / 2;
	Ychar = (rect.bottom - rect.top) / 2 - size.cy / 2 - 170;
	TextOut(hdc, Xchar, Ychar, pstring[0], 4);

	for (int i = 0; i<2; i++) {
		int m = pow(-1, i);
		Xchar = (rect.right - rect.left) / 2 - size.cx / 2 * m - 80 * m - i*size.cx / 4;
		for (int j = 0; j<7; j++) {
			Ychar = (rect.bottom - rect.top) / 2 - size.cy / 2 - 120 + j*size.cy;
			TextOut(hdc, Xchar, Ychar, pstring[i + 1] + j, 1);
		}
	}
	SelectObject(hdc, holdFont);		 //����ԭ���������ʽ
	DeleteObject(hnewFont);			 //ɾ���µ������ʽ
}


// CWIN_MFC_TEXTView ��ӡ

BOOL CWIN_MFC_TEXTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CWIN_MFC_TEXTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CWIN_MFC_TEXTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CWIN_MFC_TEXTView ���

#ifdef _DEBUG
void CWIN_MFC_TEXTView::AssertValid() const
{
	CView::AssertValid();
}

void CWIN_MFC_TEXTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWIN_MFC_TEXTDoc* CWIN_MFC_TEXTView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWIN_MFC_TEXTDoc)));
	return (CWIN_MFC_TEXTDoc*)m_pDocument;
}
#endif //_DEBUG


// CWIN_MFC_TEXTView ��Ϣ�������
