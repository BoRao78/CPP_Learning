
// Ex_SDIView.cpp : CEx_SDIView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_MOUSE, &CEx_SDIView::OnViewMouse)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MOUSE, &CEx_SDIView::OnUpdateViewMouse)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CEx_SDIView 构造/析构

CEx_SDIView::CEx_SDIView()
{
	// TODO: 在此处添加构造代码
	m_bShow = FALSE;
}

CEx_SDIView::~CEx_SDIView()
{
}

BOOL CEx_SDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CEx_SDIView 绘制

void CEx_SDIView::OnDraw(CDC* pDC)
{
	CEx_SDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (m_bShow){
		pDC->SetTextColor(RGB(0,0,0));
		CPoint pt;
		GetCursorPos(&pt);
		ScreenToClient(&pt);
		CString mShow; 
		mShow.Format(_T("%d,%d"), pt.x, pt.y);
		pDC->TextOut(100, 100, mShow);   // 输出字符串
	}
}


// CEx_SDIView 打印

BOOL CEx_SDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CEx_SDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CEx_SDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CEx_SDIView 诊断

#ifdef _DEBUG
void CEx_SDIView::AssertValid() const
{
	CView::AssertValid();
}

void CEx_SDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx_SDIDoc* CEx_SDIView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx_SDIDoc)));
	return (CEx_SDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CEx_SDIView 消息处理程序


void CEx_SDIView::OnViewMouse()
{
	// TODO: 在此添加命令处理程序代码
	m_bShow = !m_bShow;
	Invalidate();
}


void CEx_SDIView::OnUpdateViewMouse(CCmdUI *pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck(m_bShow);
}


void CEx_SDIView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu menu, *m_pPop;
	//装在菜单，资源ID为IDR_POPMENU——你编辑的菜单的ID
	menu.LoadMenuW(IDR_POPUPMENU);
	m_pPop = menu.GetSubMenu(0);
	CPoint myPoint;
	GetCursorPos(&myPoint);  //鼠标位置

	UINT nCheck = m_bShow ? MF_CHECKED : MF_UNCHECKED;	 			// 更新【Show】的check状态
	m_pPop->CheckMenuItem(ID_VIEW_MOUSE, MF_BYCOMMAND | nCheck);
	m_pPop->CheckMenuItem(ID_VIEW_TOOLBAR, MF_CHECKED);
	m_pPop->CheckMenuItem(ID_VIEW_STATUS_BAR, MF_CHECKED);

	m_pPop->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, myPoint.x, myPoint.y, this);
	CView::OnRButtonDown(nFlags, point);
}
