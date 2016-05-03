
// WIN_MFC_KBView.cpp : CWIN_MFC_KBView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CWIN_MFC_KBView 构造/析构

CWIN_MFC_KBView::CWIN_MFC_KBView()
{
	// TODO: 在此处添加构造代码
	//下面初始化按键标志变量。
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
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CWIN_MFC_KBView 绘制

void CWIN_MFC_KBView::OnDraw(CDC* /*pDC*/)
{
	CWIN_MFC_KBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CWIN_MFC_KBView 打印

BOOL CWIN_MFC_KBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWIN_MFC_KBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWIN_MFC_KBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWIN_MFC_KBView 诊断

#ifdef _DEBUG
void CWIN_MFC_KBView::AssertValid() const
{
	CView::AssertValid();
}

void CWIN_MFC_KBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWIN_MFC_KBDoc* CWIN_MFC_KBView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWIN_MFC_KBDoc)));
	return (CWIN_MFC_KBDoc*)m_pDocument;
}
#endif //_DEBUG


// CWIN_MFC_KBView 消息处理程序


void CWIN_MFC_KBView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nChar) {
		case VK_UP:		//当按上箭头键时，变量置为真。
			nUpKeyDown = TRUE;	 break;
		case VK_SHIFT:			//当按shift键时，变量置为真。
			nShiftKeyDown = TRUE; break;
		case VK_CONTROL:			//当按control键时，变量置为真
			nCtrlKeyDown = TRUE;	 break;
		default:
			nOtherKeyDown = TRUE;  break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CWIN_MFC_KBView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == (65 & VK_CONTROL)) {	               //当按下Ctrl+a键时(A亦可)
		if (nCtrlKeyDown == TRUE) {
			nOtherKeyDown = FALSE;
			nCtrlAKeyDown = TRUE;
			nCtrlKeyDown = FALSE;
		}
	}
	else if (nChar == 98 || nChar == 66) {	//当按下b键时
		if (nShiftKeyDown == TRUE) {		//检查shift键是否处于按下状态。
			nOtherKeyDown = FALSE;
			nShiftBKeyDown = TRUE;	//当SHIFT键按下时，变量置为真
			nShiftKeyDown = FALSE;
		}
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CWIN_MFC_KBView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC hDC(this);
	HBRUSH hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);	//创建 白画刷。
	HPEN hPen = (HPEN)GetStockObject(WHITE_PEN);		//创建白画笔。
	SelectObject(hDC, hPen);				//选入白画刷
	SelectObject(hDC, hBrush);			//选入白画笔
	SetTextColor(hDC, RGB(255, 0, 0));		//设置字体颜色为红色。

											//输出信息。
	if (nUpKeyDown == TRUE) {
		Rectangle(hDC, 0, 0, 300, 200);                         //覆盖字符串
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
