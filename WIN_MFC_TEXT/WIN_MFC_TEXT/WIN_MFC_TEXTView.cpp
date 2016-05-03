
// WIN_MFC_TEXTView.cpp : CWIN_MFC_TEXTView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CWIN_MFC_TEXTView 构造/析构

CWIN_MFC_TEXTView::CWIN_MFC_TEXTView()
{
	// TODO: 在此处添加构造代码

}

CWIN_MFC_TEXTView::~CWIN_MFC_TEXTView()
{
}

BOOL CWIN_MFC_TEXTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.x = 0;
	cs.y = 0;
	cs.cx = GetSystemMetrics(SM_CXSCREEN) / 2;
	cs.cy = GetSystemMetrics(SM_CYSCREEN) / 2;
	return CView::PreCreateWindow(cs);
}

// CWIN_MFC_TEXTView 绘制

void CWIN_MFC_TEXTView::OnDraw(CDC* pDC)
{
	CWIN_MFC_TEXTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pstring[0] = _T("迎春接福");
	pstring[1] = _T("时来万事喜临门");
	pstring[2] = _T("春到百花香满地");

	hnewFont = CreateFont         			//创建一种新的逻辑字体
		(48, 0, 0, 0, 500, 0, 0, 0,
			GB2312_CHARSET, //该字符集支持“楷体”等
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH & FF_DONTCARE,
			L"楷体");
	CClientDC hdc(this);

	holdFont = (HFONT)SelectObject(hdc, hnewFont);  //选择新的字体
	SetTextColor(hdc, RGB(255, 255, 0));	 	//设置文本颜色
	SetBkColor(hdc, RGB(255, 0, 0));	 	//设置背景颜色 
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
	SelectObject(hdc, holdFont);		 //保存原来的字体格式
	DeleteObject(hnewFont);			 //删除新的字体格式
}


// CWIN_MFC_TEXTView 打印

BOOL CWIN_MFC_TEXTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CWIN_MFC_TEXTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CWIN_MFC_TEXTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CWIN_MFC_TEXTView 诊断

#ifdef _DEBUG
void CWIN_MFC_TEXTView::AssertValid() const
{
	CView::AssertValid();
}

void CWIN_MFC_TEXTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWIN_MFC_TEXTDoc* CWIN_MFC_TEXTView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWIN_MFC_TEXTDoc)));
	return (CWIN_MFC_TEXTDoc*)m_pDocument;
}
#endif //_DEBUG


// CWIN_MFC_TEXTView 消息处理程序
