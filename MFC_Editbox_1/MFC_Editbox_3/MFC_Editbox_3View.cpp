
// MFC_Editbox_3View.cpp : CMFC_Editbox_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC_Editbox_3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC_Editbox_3View 构造/析构

CMFC_Editbox_3View::CMFC_Editbox_3View()
{
	// TODO: 在此处添加构造代码

}

CMFC_Editbox_3View::~CMFC_Editbox_3View()
{
}

BOOL CMFC_Editbox_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_Editbox_3View 绘制

void CMFC_Editbox_3View::OnDraw(CDC* /*pDC*/)
{
	CMFC_Editbox_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_Editbox_3View 打印


void CMFC_Editbox_3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC_Editbox_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_Editbox_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC_Editbox_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CMFC_Editbox_3View 诊断

#ifdef _DEBUG
void CMFC_Editbox_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_Editbox_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_Editbox_3Doc* CMFC_Editbox_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_Editbox_3Doc)));
	return (CMFC_Editbox_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_Editbox_3View 消息处理程序
