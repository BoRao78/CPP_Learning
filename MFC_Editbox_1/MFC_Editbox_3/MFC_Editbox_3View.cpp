
// MFC_Editbox_3View.cpp : CMFC_Editbox_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_Editbox_3.h"
#endif

#include "MFC_Editbox_3Doc.h"
#include "MFC_Editbox_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_Editbox_3View

IMPLEMENT_DYNCREATE(CMFC_Editbox_3View, CView)

BEGIN_MESSAGE_MAP(CMFC_Editbox_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC_Editbox_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC_Editbox_3View ����/����

CMFC_Editbox_3View::CMFC_Editbox_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CMFC_Editbox_3View::~CMFC_Editbox_3View()
{
}

BOOL CMFC_Editbox_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_Editbox_3View ����

void CMFC_Editbox_3View::OnDraw(CDC* /*pDC*/)
{
	CMFC_Editbox_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_Editbox_3View ��ӡ


void CMFC_Editbox_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC_Editbox_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_Editbox_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_Editbox_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CMFC_Editbox_3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC_Editbox_3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC_Editbox_3View ���

#ifdef _DEBUG
void CMFC_Editbox_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_Editbox_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_Editbox_3Doc* CMFC_Editbox_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_Editbox_3Doc)));
	return (CMFC_Editbox_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_Editbox_3View ��Ϣ�������
