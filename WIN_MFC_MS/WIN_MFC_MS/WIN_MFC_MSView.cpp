
// WIN_MFC_MSView.cpp : CWIN_MFC_MSView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "WIN_MFC_MS.h"
#endif

#include "WIN_MFC_MSDoc.h"
#include "WIN_MFC_MSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWIN_MFC_MSView

IMPLEMENT_DYNCREATE(CWIN_MFC_MSView, CView)

BEGIN_MESSAGE_MAP(CWIN_MFC_MSView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CWIN_MFC_MSView ����/����

CWIN_MFC_MSView::CWIN_MFC_MSView()
{
	// TODO: �ڴ˴���ӹ������
	operate = FALSE;
	ready = TRUE;//operateΪ���������ʶ��readyΪ���Ƴ�ʼͼ�α�ʶ
	origin = TRUE;
	BeginP, EndP;
	rect = { 0,0,0,0 };
}

CWIN_MFC_MSView::~CWIN_MFC_MSView()
{
}

BOOL CWIN_MFC_MSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	//cs.style = WS_OVERLAPPEDWINDOW|WS_SYSMENU;
	cs.x = 0;
	cs.y = 0;
	cs.cx = GetSystemMetrics(SM_CXSCREEN) / 2;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) / 2;
	return CView::PreCreateWindow(cs);
}

// CWIN_MFC_MSView ����

void CWIN_MFC_MSView::OnDraw(CDC* /*pDC*/)
{
	CWIN_MFC_MSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CClientDC hdc(this);
	HBRUSH hBrush;
	if (ready == FALSE) {//�ǳ�ʼ״̬,�������������	
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		SelectObject(hdc, hBrush);
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		DeleteObject(hBrush);
	}
	else {
		rect = { 0, 0, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2 };
		if (origin == true);//��ʼ״̬
		else {	//����״̬
			hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
			SelectObject(hdc, hBrush);
		}
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	}
}


// CWIN_MFC_MSView ��ӡ

BOOL CWIN_MFC_MSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CWIN_MFC_MSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CWIN_MFC_MSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CWIN_MFC_MSView ���

#ifdef _DEBUG
void CWIN_MFC_MSView::AssertValid() const
{
	CView::AssertValid();
}

void CWIN_MFC_MSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWIN_MFC_MSDoc* CWIN_MFC_MSView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWIN_MFC_MSDoc)));
	return (CWIN_MFC_MSDoc*)m_pDocument;
}
#endif //_DEBUG


// CWIN_MFC_MSView ��Ϣ�������


void CWIN_MFC_MSView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if ((!operate) && ready) {
		operate = TRUE;		//����������
		ready = FALSE;
		SetCursor(LoadCursor(NULL, IDC_CROSS));	 //������
		BeginP.x = point.x;
		BeginP.y = point.y;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CWIN_MFC_MSView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (operate) {
		EndP.x = point.x;
		EndP.y = point.y;
		rect.left = BeginP.x<EndP.x ? BeginP.x : EndP.x;
		rect.right = BeginP.x>EndP.x ? BeginP.x : EndP.x;
		rect.top = BeginP.y<EndP.y ? BeginP.y : EndP.y;
		rect.bottom = BeginP.y>EndP.y ? BeginP.y : EndP.y;
		SetCursor(LoadCursor(NULL, IDC_WAIT));	//����ɳ©���
		Invalidate();
		UpdateWindow();
	}
	CView::OnMouseMove(nFlags, point);
}


void CWIN_MFC_MSView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (operate) {
		operate = FALSE;
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		ReleaseCapture();	//�����ӵ�ǰ�������ͷų���
		Invalidate();
		UpdateWindow();
	}
	CView::OnLButtonUp(nFlags, point);
}


void CWIN_MFC_MSView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (ready == FALSE) {
		ready = TRUE;
		origin = FALSE;
		Invalidate();
		UpdateWindow();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CWIN_MFC_MSView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (origin == FALSE) {
		origin = TRUE;
		Invalidate();
		UpdateWindow();
	}
	CView::OnRButtonDown(nFlags, point);
}
