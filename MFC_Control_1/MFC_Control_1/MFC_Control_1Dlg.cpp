
// MFC_Control_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Control_1.h"
#include "MFC_Control_1Dlg.h"
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


// CMFC_Control_1Dlg �Ի���



CMFC_Control_1Dlg::CMFC_Control_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CONTROL_1_DIALOG, pParent)
	, m_memory(1)
	, m_config1(TRUE)
	, m_config2(FALSE)
	, m_config3(FALSE)
	, m_config4(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Control_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_memory);
	DDX_Check(pDX, IDC_CHECK1, m_config1);
	DDX_Check(pDX, IDC_CHECK2, m_config2);
	DDX_Check(pDX, IDC_CHECK3, m_config3);
	DDX_Check(pDX, IDC_CHECK4, m_config4);
	DDX_Control(pDX, IDC_COMMIT, m_commit);
	DDX_Control(pDX, IDC_RESELECT, m_reselect);
	DDX_Control(pDX, IDC_CONFIG, m_config);
}

BEGIN_MESSAGE_MAP(CMFC_Control_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COMMIT, &CMFC_Control_1Dlg::OnClickedCommit)
	ON_BN_CLICKED(IDC_RESELECT, &CMFC_Control_1Dlg::OnClickedReselect)
END_MESSAGE_MAP()


// CMFC_Control_1Dlg ��Ϣ�������

BOOL CMFC_Control_1Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_Control_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_Control_1Dlg::OnPaint()
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
HCURSOR CMFC_Control_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Control_1Dlg::OnClickedCommit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	configstr = _T("�û���ѡ�����£�\n�ڴ�: ");
	configstr += memory[m_memory];
	configstr += ",  ���ã�";
	if (m_config1 == TRUE)
		configstr += seconfig[0]+' ';
	if (m_config2 == TRUE)
		configstr += seconfig[1]+' ';
	if (m_config3 == TRUE)
		configstr += seconfig[2]+' ';
	if (m_config4 == TRUE)
		configstr += seconfig[3]+' ';
	m_config.SetWindowTextW(configstr);
	m_reselect.EnableWindow(TRUE);
}


void CMFC_Control_1Dlg::OnClickedReselect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_memory = 1;
	m_config1 = TRUE;
	m_config2 = FALSE;
	m_config3 = FALSE;
	m_config4 = FALSE;
	UpdateData(FALSE);
	m_config.SetWindowTextW(_T("�û���ѡ������:"));
	m_reselect.EnableWindow(FALSE);
}
