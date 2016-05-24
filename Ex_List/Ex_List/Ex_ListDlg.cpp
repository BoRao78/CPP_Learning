
// Ex_ListDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex_List.h"
#include "Ex_ListDlg.h"
#include "Score.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CEx_ListDlg �Ի���



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


// CEx_ListDlg ��Ϣ�������

BOOL CEx_ListDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//���ԭ�з��
	DWORD dwStyle = ::GetWindowLong(m_List.m_hWnd, GWL_STYLE);
	dwStyle &= ~(LVS_TYPEMASK);
	dwStyle &= ~(LVS_EDITLABELS);
	//�����·��
	SetWindowLong(m_List.m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT | LVS_NOLABELWRAP | LVS_SHOWSELALWAYS);
	//������չ���
	DWORD styles = LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES;//| LVS_EX_CHECKBOXES;
	ListView_SetExtendedListViewStyleEx(m_List.m_hWnd, styles, styles);
	//LVS_EX_FULLROWSELECT������ѡ��
	//LVS_EX_GRIDLINES�������ߣ�ֻ������report����listctrl��
	//LVS_EX_CHECKBOXES��ǰ��Ӹ�checkbox
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_SUBITEMIMAGES);

	int i = 0, j = 0;
	CString Score[] = {_T("ѧ��"),_T("�γ̺�") ,_T("�ɼ�") ,_T("ѧ��") };
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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEx_ListDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CEx_ListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CEx_ListDlg::OnBnClickedCancel2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CEx_ListDlg::OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nItem = m_List.GetSelectionMark();
	m_List.DeleteItem(nItem);
}


void CEx_ListDlg::OnBnClickedButtonChange()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CScore *ScoreDlg;
	ScoreDlg = new CScore;
	ScoreDlg->Create(IDD_CScoreDlg, this);
	ScoreDlg->ShowWindow(SW_SHOW);
}


void CEx_ListDlg::OnBnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
