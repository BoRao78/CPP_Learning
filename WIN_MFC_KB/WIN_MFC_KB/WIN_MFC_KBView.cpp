
// WIN_MFC_KBView.cpp : CWIN_MFC_KBView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "WIN_MFC_KB.h"
#endif

#include "WIN_MFC_KBDoc.h"
#include "WIN_MFC_KBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWIN_MFC_KBView

IMPLEMENT_DYNCREATE(CWIN_MFC_KBView, CView)

BEGIN_MESSAGE_MAP(CWIN_MFC_KBView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CWIN_MFC_KBView ����/����

CWIN_MFC_KBView::CWIN_MFC_KBView()
{
	// TODO: �ڴ˴���ӹ������
	//�����ʼ��������־������
	nUpKeyDown = FALSE,
	nShiftKeyDown = FALSE,
	nCtrlKeyDown = FALSE,
	nCtrlAKeyDown = FALSE,
	nShiftBKeyDown = FALSE,
	nOtherKeyDown = FALSE;
}

CWIN_MFC_KBView::~CWIN_MFC_KBView()
{
}

BOOL CWIN_MFC_KBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CWIN_MFC_KBView ����

void CWIN_MFC_KBView::OnDraw(CDC* /*pDC*/)
{
	CWIN_MFC_KBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CWIN_MFC_KBView ��ӡ

BOOL CWIN_MFC_KBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CWIN_MFC_KBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CWIN_MFC_KBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CWIN_MFC_KBView ���

#ifdef _DEBUG
void CWIN_MFC_KBView::AssertValid() const
{
	CView::AssertValid();
}

void CWIN_MFC_KBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWIN_MFC_KBDoc* CWIN_MFC_KBView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWIN_MFC_KBDoc)));
	return (CWIN_MFC_KBDoc*)m_pDocument;
}
#endif //_DEBUG


// CWIN_MFC_KBView ��Ϣ�������


void CWIN_MFC_KBView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar) {
		case VK_UP:		//�����ϼ�ͷ��ʱ��������Ϊ�档
			nUpKeyDown = TRUE;	 break;
		case VK_SHIFT:			//����shift��ʱ��������Ϊ�档
			nShiftKeyDown = TRUE; break;
		case VK_CONTROL:			//����control��ʱ��������Ϊ��
			nCtrlKeyDown = TRUE;	 break;
		default:
			nOtherKeyDown = TRUE;  break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CWIN_MFC_KBView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nChar == (65 & VK_CONTROL)) {	               //������Ctrl+a��ʱ(A���)
		if (nCtrlKeyDown == TRUE) {
			nOtherKeyDown = FALSE;
			nCtrlAKeyDown = TRUE;
			nCtrlKeyDown = FALSE;
		}
	}
	else if (nChar == 98 || nChar == 66) {	//������b��ʱ
		if (nShiftKeyDown == TRUE) {		//���shift���Ƿ��ڰ���״̬��
			nOtherKeyDown = FALSE;
			nShiftBKeyDown = TRUE;	//��SHIFT������ʱ��������Ϊ��
			nShiftKeyDown = FALSE;
		}
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CWIN_MFC_KBView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC hDC(this);
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);	//���� �׻�ˢ��
	HPEN hPen = (HPEN)GetStockObject(WHITE_PEN);		//�����׻��ʡ�
	SelectObject(hDC, hPen);				//ѡ��׻�ˢ
	SelectObject(hDC, hBrush);			//ѡ��׻���
	SetTextColor(hDC, RGB(255, 0, 0));		//����������ɫΪ��ɫ��

											//�����Ϣ��
	if (nUpKeyDown == TRUE) {
		Rectangle(hDC, 0, 0, 300, 200);                         //�����ַ���
		TextOut(hDC, 0, 0, cUp, _tcslen(cUp));
		nUpKeyDown = FALSE;
	}
	else if (nCtrlAKeyDown == TRUE) {
		Rectangle(hDC, 0, 0, 300, 200);
		TextOut(hDC, 0, 100, cCtrl_A, _tcslen(cCtrl_A));
		nCtrlAKeyDown = FALSE;
		nCtrlKeyDown = FALSE;
	}
	//else if(nCtrlAKeyDown == TRUE) 
	else if (nCtrlKeyDown == TRUE&&nCtrlAKeyDown == FALSE) {
		Rectangle(hDC, 0, 0, 300, 200);
		TextOut(hDC, 0, 60, cCtrl, _tcslen(cCtrl));
		nCtrlKeyDown = FALSE;
	}
	else if (nShiftBKeyDown == TRUE) {
		Rectangle(hDC, 0, 0, 300, 200);
		TextOut(hDC, 0, 0, cShift_B, _tcslen(cShift_B));
		nShiftBKeyDown = FALSE;
		nShiftKeyDown = FALSE;
	}
	else if (nShiftBKeyDown == FALSE&&nShiftKeyDown == TRUE) {
		Rectangle(hDC, 0, 0, 300, 200);
		TextOut(hDC, 0, 0, cShift, _tcslen(cShift));
		nShiftKeyDown = FALSE;
	}
	else if (nOtherKeyDown == TRUE) {
		Rectangle(hDC, 0, 0, 300, 200);
		nOtherKeyDown = FALSE;
	}
	else;


	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
