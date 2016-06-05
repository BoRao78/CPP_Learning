
// Ex_SDIView.cpp : CEx_SDIView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Ex_SDI.h"
#endif

#include "Ex_SDIDoc.h"
#include "Ex_SDIView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx_SDIView

IMPLEMENT_DYNCREATE(CEx_SDIView, CView)

BEGIN_MESSAGE_MAP(CEx_SDIView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_MOUSE, &CEx_SDIView::OnViewMouse)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MOUSE, &CEx_SDIView::OnUpdateViewMouse)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx_SDIView ����/����

CEx_SDIView::CEx_SDIView()
{
	// TODO: �ڴ˴���ӹ������
	m_bShow = FALSE;
}

CEx_SDIView::~CEx_SDIView()
{
}

BOOL CEx_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CEx_SDIView ����

void CEx_SDIView::OnDraw(CDC* pDC)
{
	CEx_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	if (m_bShow){
		pDC->SetTextColor(RGB(0,0,0));
		CPoint pt;
		GetCursorPos(&pt);
		ScreenToClient(&pt);
		CString mShow; 
		mShow.Format(_T("%d,%d"), pt.x, pt.y);
		pDC->TextOut(100, 100, mShow);   // ����ַ���
	}
}


// CEx_SDIView ��ӡ

BOOL CEx_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CEx_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CEx_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CEx_SDIView ���

#ifdef _DEBUG
void CEx_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SDIDoc* CEx_SDIView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SDIDoc)));
	return (CEx_SDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CEx_SDIView ��Ϣ�������


void CEx_SDIView::OnViewMouse()
{
	// TODO: �ڴ���������������
	m_bShow = !m_bShow;
	Invalidate();
}


void CEx_SDIView::OnUpdateViewMouse(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->SetCheck(m_bShow);
}


void CEx_SDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMenu menu, *m_pPop;
	//װ�ڲ˵�����ԴIDΪIDR_POPMENU������༭�Ĳ˵���ID
	menu.LoadMenuW(IDR_POPUPMENU);
	m_pPop = menu.GetSubMenu(0);
	CPoint myPoint;
	GetCursorPos(&myPoint);  //���λ��

	UINT nCheck = m_bShow ? MF_CHECKED : MF_UNCHECKED;	 			// ���¡�Show����check״̬
	m_pPop->CheckMenuItem(ID_VIEW_MOUSE, MF_BYCOMMAND | nCheck);
	m_pPop->CheckMenuItem(ID_VIEW_TOOLBAR, MF_CHECKED);
	m_pPop->CheckMenuItem(ID_VIEW_STATUS_BAR, MF_CHECKED);

	m_pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, myPoint.x, myPoint.y, this);
	CView::OnRButtonDown(nFlags, point);
}
