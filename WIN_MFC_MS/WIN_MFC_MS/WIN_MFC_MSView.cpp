
// WIN_MFC_MSView.cpp : CWIN_MFC_MSView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CWIN_MFC_MSView 构造/析构

CWIN_MFC_MSView::CWIN_MFC_MSView()
{
	// TODO: 在此处添加构造代码
	operate = FALSE;
	ready = TRUE;//operate为按下左键标识，ready为绘制初始图形标识
	origin = TRUE;
	BeginP, EndP;
	rect = { 0,0,0,0 };
}

CWIN_MFC_MSView::~CWIN_MFC_MSView()
{
}

BOOL CWIN_MFC_MSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	//cs.style = WS_OVERLAPPEDWINDOW|WS_SYSMENU;
	cs.x = 0;
	cs.y = 0;
	cs.cx = GetSystemMetrics(SM_CXSCREEN) / 2;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) / 2;
	return CView::PreCreateWindow(cs);
}

// CWIN_MFC_MSView 绘制

void CWIN_MFC_MSView::OnDraw(CDC* /*pDC*/)
{
	CWIN_MFC_MSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC hdc(this);
	HBRUSH hBrush;
	if (ready == FALSE) {//非初始状态,曾经按下了左键	
		hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		SelectObject(hdc, hBrush);
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		DeleteObject(hBrush);
	}
	else {
		rect = { 0, 0, GetSystemMetrics(SM_CXSCREEN) / 2, GetSystemMetrics(SM_CYSCREEN) / 2 };
		if (origin == true);//初始状态
		else {	//拉伸状态
			hBrush = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
			SelectObject(hdc, hBrush);
		}
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	}
}


// CWIN_MFC_MSView 打印

BOOL CWIN_MFC_MSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWIN_MFC_MSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWIN_MFC_MSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWIN_MFC_MSView 诊断

#ifdef _DEBUG
void CWIN_MFC_MSView::AssertValid() const
{
	CView::AssertValid();
}

void CWIN_MFC_MSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWIN_MFC_MSDoc* CWIN_MFC_MSView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWIN_MFC_MSDoc)));
	return (CWIN_MFC_MSDoc*)m_pDocument;
}
#endif //_DEBUG


// CWIN_MFC_MSView 消息处理程序


void CWIN_MFC_MSView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if ((!operate) && ready) {
		operate = TRUE;		//左键击活俘获
		ready = FALSE;
		SetCursor(LoadCursor(NULL, IDC_CROSS));	 //载入光标
		BeginP.x = point.x;
		BeginP.y = point.y;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CWIN_MFC_MSView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (operate) {
		EndP.x = point.x;
		EndP.y = point.y;
		rect.left = BeginP.x<EndP.x ? BeginP.x : EndP.x;
		rect.right = BeginP.x>EndP.x ? BeginP.x : EndP.x;
		rect.top = BeginP.y<EndP.y ? BeginP.y : EndP.y;
		rect.bottom = BeginP.y>EndP.y ? BeginP.y : EndP.y;
		SetCursor(LoadCursor(NULL, IDC_WAIT));	//载入沙漏光标
		Invalidate();
		UpdateWindow();
	}
	CView::OnMouseMove(nFlags, point);
}


void CWIN_MFC_MSView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (operate) {
		operate = FALSE;
		SetCursor(LoadCursor(NULL, IDC_ARROW));
		ReleaseCapture();	//把鼠标从当前窗口中释放出来
		Invalidate();
		UpdateWindow();
	}
	CView::OnLButtonUp(nFlags, point);
}


void CWIN_MFC_MSView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (origin == FALSE) {
		origin = TRUE;
		Invalidate();
		UpdateWindow();
	}
	CView::OnRButtonDown(nFlags, point);
}
