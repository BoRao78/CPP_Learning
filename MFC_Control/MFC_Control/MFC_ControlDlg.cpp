
// MFC_ControlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Control.h"
#include "MFC_ControlDlg.h"
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


// CMFC_ControlDlg 对话框



CMFC_ControlDlg::CMFC_ControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CONTROL_DIALOG, pParent)
	, m_rd4(0)
	, m_rd1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_brush.CreateSolidBrush(RGB(255, 255, 200));
}

void CMFC_ControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OK, m_ok);
	DDX_Control(pDX, IDC_RADIO4, m_rdc4);
	DDX_Radio(pDX, IDC_RADIO4, m_rd4);
	DDX_Control(pDX, IDC_RADIO1, m_rdc1);
	DDX_Radio(pDX, IDC_RADIO1, m_rd1);
	DDX_Control(pDX, IDC_STATIC_1, m_static1);
}

BEGIN_MESSAGE_MAP(CMFC_ControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON2, &CMFC_ControlDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_OK, &CMFC_ControlDlg::OnClickedOk)
	ON_STN_CLICKED(IDC_STATIC_1, &CMFC_ControlDlg::OnClickedStatic1)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMFC_ControlDlg 消息处理程序

BOOL CMFC_ControlDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_ControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_ControlDlg::OnPaint()
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
HCURSOR CMFC_ControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_ControlDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFC_ControlDlg::OnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_ok.SetWindowTextW(_T("Hello"));
	m_rd1 = 1;
	m_rd4 = 0;
	//Attention
	UpdateData(FALSE);//
	m_static1.SetWindowTextW(_T("Haha"));
}


void CMFC_ControlDlg::OnClickedStatic1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_static1.SetWindowTextW(_T("Haha"));
}


HBRUSH CMFC_ControlDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return m_brush;
}
