#include "tchar.h"
#define UNICODE
// MFC_DemoView.cpp : CMFC_DemoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_Demo.h"
#endif

#include "MFC_DemoDoc.h"
#include "MFC_DemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_DemoView

IMPLEMENT_DYNCREATE(CMFC_DemoView, CView)

BEGIN_MESSAGE_MAP(CMFC_DemoView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFC_DemoView 构造/析构

CMFC_DemoView::CMFC_DemoView(){
	// TODO: 在此处添加构造代码

}

CMFC_DemoView::~CMFC_DemoView()
{
}

BOOL CMFC_DemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_DemoView 绘制

void CMFC_DemoView::OnDraw(CDC* pDC)
{
	CMFC_DemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC hdc(this);
	SetMapMode(hdc, MM_ANISOTROPIC);       //设置映像模式
	HPEN hP = (HPEN)GetStockObject(BLACK_PEN);	//黑色画笔
	HBRUSH hB = (HBRUSH)GetStockObject(DKGRAY_BRUSH); //画刷
	SelectObject(hdc, hB);   //选择画刷
	SelectObject(hdc, hP);       //选择画笔
	RoundRect(hdc, 50, 120, 100, 200, 15, 15); //绘制圆角矩形
	hB = (HBRUSH)GetStockObject(LTGRAY_BRUSH);  //采用亮灰色画刷
	SelectObject(hdc, hB);  	   //选择画刷
	Ellipse(hdc, 150, 50, 200, 150); 	   //绘制椭圆
	hB = (HBRUSH)GetStockObject(HOLLOW_BRUSH); //虚画刷
	SelectObject(hdc, hB);  	  //选择画刷
	Pie(hdc, 250, 50, 300, 100, 250, 50, 300, 50);  	//绘制饼形

	hP = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 255));
	hB = CreateHatchBrush(HS_HORIZONTAL, RGB(0, 255, 0));
	SelectObject(hdc, hP);
	SelectObject(hdc, hB);
	RoundRect(hdc, 35, 220, 115, 270, 15, 15);
	Ellipse(hdc, 125, 170, 225, 220);
	Pie(hdc, 250, 120, 300, 170, 300, 120, 300, 170);

}


// CMFC_DemoView 打印

BOOL CMFC_DemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_DemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFC_DemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFC_DemoView 诊断

#ifdef _DEBUG
void CMFC_DemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_DemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_DemoDoc* CMFC_DemoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_DemoDoc)));
	return (CMFC_DemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_DemoView 消息处理程序
