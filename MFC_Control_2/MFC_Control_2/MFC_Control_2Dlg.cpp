
// MFC_Control_2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Control_2.h"
#include "MFC_Control_2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_Control_2Dlg 对话框



CMFC_Control_2Dlg::CMFC_Control_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CONTROL_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Control_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_ScrollBar1);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_ScrollBar2);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_ScrollBar3);
}

BEGIN_MESSAGE_MAP(CMFC_Control_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CMFC_Control_2Dlg::OnNMThemeChangedScrollbar1)
	ON_WM_CTLCOLOR()
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMFC_Control_2Dlg 消息处理程序

BOOL CMFC_Control_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//ScrollBar Initial
	m_ScrollBar1.SetScrollRange(0, 255);
	m_ScrollBar1.SetScrollPos(100);
	m_ScrollBar2.SetScrollRange(0, 255);
	m_ScrollBar2.SetScrollPos(150);
	m_ScrollBar3.SetScrollRange(0, 255);
	m_ScrollBar3.SetScrollPos(200);
	//UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_Control_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_Control_2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_Control_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Control_2Dlg::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;

}


void CMFC_Control_2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT iNowPos = 0;
	if (pScrollBar == &m_ScrollBar1 || &m_ScrollBar2 || &m_ScrollBar3) {//判断是否来自当前滚动条的消息
			switch (nSBCode) {
			case SB_THUMBTRACK:	//拖动滑块
				pScrollBar->SetScrollPos(nPos);
				//UpdateData(FALSE);
				Invalidate();
				UpdateWindow();
				break;
			case SB_LINEDOWN:	
				iNowPos = pScrollBar->GetScrollPos();
				iNowPos = iNowPos + 1;
				if (iNowPos>255)
					iNowPos = 255;
				pScrollBar->SetScrollPos(iNowPos);
				Invalidate();
				UpdateWindow();
				break;
			case SB_LINEUP:	
				iNowPos = pScrollBar->GetScrollPos();
				iNowPos = iNowPos - 1;
				if (iNowPos<0)
					iNowPos = 0;
				pScrollBar->SetScrollPos(iNowPos);
				Invalidate();
				UpdateWindow();
				break;
			case SB_PAGEDOWN:	
				iNowPos = pScrollBar->GetScrollPos();
				iNowPos = iNowPos + 10;
				if (iNowPos>255)
					iNowPos = 255;
				pScrollBar->SetScrollPos(iNowPos);
				Invalidate();
				UpdateWindow();
				break;
			case SB_PAGEUP:	
				iNowPos = pScrollBar->GetScrollPos();
				iNowPos = iNowPos - 10;
				if (iNowPos<0)
					iNowPos = 0;
				pScrollBar->SetScrollPos(iNowPos);
				Invalidate();
				UpdateWindow();
				break;
			default:break;
			}
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

HBRUSH CMFC_Control_2Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO:  在此更改 DC 的任何特性

	HBRUSH Brush = CreateSolidBrush(RGB(m_ScrollBar1.GetScrollPos(),
		m_ScrollBar2.GetScrollPos(),
		m_ScrollBar3.GetScrollPos()));
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return Brush;
}
