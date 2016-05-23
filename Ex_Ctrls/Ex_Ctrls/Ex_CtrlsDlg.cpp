
// Ex_CtrlsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex_Ctrls.h"
#include "Ex_CtrlsDlg.h"
#include "Ex_Stu.h"
#include "Ex_Course.h"
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


// CEx_CtrlsDlg 对话框



CEx_CtrlsDlg::CEx_CtrlsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EX_CTRLS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_CtrlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_Scrollbar1);
	DDX_Control(pDX, IDC_SLIDER1, m_Slider1);
	DDX_Control(pDX, IDC_SLIDER2, m_Slider2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
}

BEGIN_MESSAGE_MAP(CEx_CtrlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &CEx_CtrlsDlg::OnNMThemeChangedScrollbar1)
	ON_WM_CTLCOLOR()
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_Stu, &CEx_CtrlsDlg::OnBnClickedButtonStu)
	ON_BN_CLICKED(IDC_BUTTON_Course, &CEx_CtrlsDlg::OnBnClickedButtonCourse)
END_MESSAGE_MAP()


// CEx_CtrlsDlg 消息处理程序

BOOL CEx_CtrlsDlg::OnInitDialog()
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
	m_Scrollbar1.SetScrollRange(0, 255);
	m_Scrollbar1.SetScrollPos(100);
	m_Slider1.SetRange(0, 255);
	m_Slider1.SetPos(150);
	m_Slider2.SetRange(0, 255);
	m_Slider2.SetPos(200);

	Edit = _T("姓名：") + Name + _T("\r\n学号：") + Number + _T("\r\n性别：") + Gender + _T("\r\n出生年月：") + StrTime + _T("\r\n所学专业：") + Major;
	m_Edit1.SetWindowText(Edit);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEx_CtrlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx_CtrlsDlg::OnPaint()
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
HCURSOR CEx_CtrlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEx_CtrlsDlg::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


HBRUSH CEx_CtrlsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	HBRUSH Brush = CreateSolidBrush(RGB(m_Scrollbar1.GetScrollPos(),
		m_Slider1.GetPos(),
		m_Slider2.GetPos()));
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return Brush;
}


void CEx_CtrlsDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT iNowPos = 0;
	if (pScrollBar == &m_Scrollbar1 || &m_Slider1 || &m_Slider2) {//判断是否来自当前滚动条的消息
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
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CEx_CtrlsDlg::OnBnClickedButtonStu()
{
	// TODO: 在此添加控件通知处理程序代码
	Ex_Stu StuDlg;
	if (StuDlg.DoModal() == IDOK) {
			Name = StuDlg.m_NameData;
			Number = StuDlg.m_NumberData;
			if (StuDlg.m_Gender == 0) Gender = "男";
			else Gender = "女";
			StrTime = StuDlg.m_TimeData.Format(_T("%Y - %m - %d"));
			Major = StuDlg.m_MajorData;
			Edit = _T("姓名：") + Name + _T("\r\n学号：") + Number + _T("\r\n性别：") + Gender + _T("\r\n出生年月：") + StrTime + _T("\r\n所学专业：") + Major;
			m_Edit1.SetSel(0,-1);
			m_Edit1.ReplaceSel(Edit);
	}
}


void CEx_CtrlsDlg::OnBnClickedButtonCourse()
{
	// TODO: 在此添加控件通知处理程序代码
	Ex_Course CourseDlg;
	if (CourseDlg.DoModal() == IDOK) {
		CourseName = CourseDlg.m_CosName;
		CourseNumber = CourseDlg.m_CosNum;
		CourseMajor = CourseDlg.m_MajorData;
		CourseType = CourseDlg.m_TypeData;
		CourseTerm = CourseDlg.m_EditTermData;
		CourseCount = CourseDlg.m_CosCount;
		CourseCredit = CourseDlg.m_Credit;
		Edit = _T("课程号：") + CourseNumber + _T("\r\n课程名称：") + CourseName + _T("\r\n所属专业：") + CourseMajor + _T("\r\n课程类型：") + CourseType + _T("\r\n开课学期：") + CourseTerm + _T("\r\n课时数：") + CourseCount + _T("\r\n学分：") + CourseCredit;
		m_Edit1.SetSel(0, -1);
		m_Edit1.ReplaceSel(Edit);
	}
}
