
// Ex_ListDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex_List.h"
#include "Ex_ListDlg.h"
#include "Score.h"
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


// CEx_ListDlg 对话框



CEx_ListDlg::CEx_ListDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EX_LIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx_ListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_BUTTON_Change, m_ButtonChange);
	DDX_Control(pDX, IDC_BUTTON_Delete, m_ButtonDelete);
	DDX_Control(pDX, IDC_BUTTON_Add, m_ButtonAdd);
}

BEGIN_MESSAGE_MAP(CEx_ListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL2, &CEx_ListDlg::OnBnClickedCancel2)
	ON_NOTIFY(NM_CLICK, IDC_LIST, &CEx_ListDlg::OnNMClickList)
	ON_BN_CLICKED(IDC_BUTTON_Delete, &CEx_ListDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_Change, &CEx_ListDlg::OnBnClickedButtonChange)
	ON_BN_CLICKED(IDC_BUTTON_Add, &CEx_ListDlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CEx_ListDlg 消息处理程序

BOOL CEx_ListDlg::OnInitDialog()
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
	//获得原有风格
	DWORD dwStyle = ::GetWindowLong(m_List.m_hWnd, GWL_STYLE);
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
	//设置新风格
	SetWindowLong(m_List.m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT | LVS_NOLABELWRAP | LVS_SHOWSELALWAYS);
	//设置扩展风格
	DWORD styles = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;//| LVS_EX_CHECKBOXES;
	ListView_SetExtendedListViewStyleEx(m_List.m_hWnd, styles, styles);
	//LVS_EX_FULLROWSELECT　整行选中
	//LVS_EX_GRIDLINES　网格线（只适用于report风格的listctrl）
	//LVS_EX_CHECKBOXES　前面加个checkbox
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_SUBITEMIMAGES);

	int i = 0, j = 0;
	CString Score[] = {_T("学号"),_T("课程号") ,_T("成绩") ,_T("学分") };
	CString ScoreData[][4] = {
		_T("21010501"), _T("2112105"), _T("80.0"), _T("3.0"),
		_T("21010501"), _T("2112348"), _T("85.0"), _T("2.5"),
		_T("21010502"), _T("2112556"), _T("88.0"), _T("2.0") };
	for (i = 0; i < 4; i++){ 
		m_List.InsertColumn(i, Score[i], LVCFMT_LEFT, 190);
	}
	for (i = 0; i < 3; i++) {
			m_List.InsertItem(i, ScoreData[i][0]);
			for (j = 1; j< 4; j++) {
			m_List.SetItemText(i,j, ScoreData[i][j]);
		}
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEx_ListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx_ListDlg::OnPaint()
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
HCURSOR CEx_ListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEx_ListDlg::OnBnClickedCancel2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CEx_ListDlg::OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	if (m_List.GetFirstSelectedItemPosition() > 0) {
		OnEdit = 1;
		m_ButtonChange.EnableWindow(TRUE);
		m_ButtonDelete.EnableWindow(TRUE);
		m_ButtonAdd.EnableWindow(FALSE);
	}
	else {
		OnEdit = 0;
		m_ButtonChange.EnableWindow(FALSE);
		m_ButtonDelete.EnableWindow(FALSE);
		m_ButtonAdd.EnableWindow(TRUE);
	}
	*pResult = 0;
}


void CEx_ListDlg::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int nItem = m_List.GetSelectionMark();
	m_List.DeleteItem(nItem);
}


void CEx_ListDlg::OnBnClickedButtonChange()
{
	// TODO: 在此添加控件通知处理程序代码
	CScore *ScoreDlg;
	ScoreDlg = new CScore;
	ScoreDlg->Create(IDD_CScoreDlg, this);
	ScoreDlg->ShowWindow(SW_SHOW);
}


void CEx_ListDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CScore ScoreDlg;
	if (ScoreDlg.DoModal() == IDOK) {
		Number = ScoreDlg.m_Num;
		CourseNumber = ScoreDlg.m_CosNum;
		Score.Format(_T("%3.1f"), _wtof(ScoreDlg.m_Score.GetBuffer()));
		Credit.Format(_T("%2.1f"), _wtof(ScoreDlg.m_Credit.GetBuffer()));

		int nIndex = m_List.GetItemCount();
		m_List.InsertItem(nIndex, Number);
		m_List.SetItemText(nIndex, 1, CourseNumber);
		m_List.SetItemText(nIndex, 2, Score);
		m_List.SetItemText(nIndex, 3, Credit);
	}
}
