
// MFC_Editbox_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Editbox_2.h"
#include "MFC_Editbox_2Dlg.h"
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


// CMFC_Editbox_2Dlg �Ի���



CMFC_Editbox_2Dlg::CMFC_Editbox_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_EDITBOX_2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_Editbox_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
}

BEGIN_MESSAGE_MAP(CMFC_Editbox_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Show1_BUTTON, &CMFC_Editbox_2Dlg::OnBnClickedShow1Button)
	ON_BN_CLICKED(IDC_Clear1_BUTTON, &CMFC_Editbox_2Dlg::OnBnClickedClear1Button)
	ON_BN_CLICKED(IDC_Show2_BUTTON, &CMFC_Editbox_2Dlg::OnBnClickedShow2Button)
	ON_BN_CLICKED(IDC_Clear2_BUTTON8, &CMFC_Editbox_2Dlg::OnBnClickedClear2Button8)
	ON_BN_CLICKED(IDC_Exit_BUTTON, &CMFC_Editbox_2Dlg::OnBnClickedExitButton)
	ON_BN_CLICKED(IDC_Tranfer_BUTTON, &CMFC_Editbox_2Dlg::OnBnClickedTranferButton)
	ON_BN_CLICKED(IDC_Undo_BUTTON, &CMFC_Editbox_2Dlg::OnBnClickedUndoButton)
END_MESSAGE_MAP()


// CMFC_Editbox_2Dlg ��Ϣ�������

BOOL CMFC_Editbox_2Dlg::OnInitDialog()
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

void CMFC_Editbox_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_Editbox_2Dlg::OnPaint()
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
HCURSOR CMFC_Editbox_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Editbox_2Dlg::OnBnClickedShow1Button()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit1.SetSel(0, -1);
	m_Edit1.ReplaceSel(_T("This is the first Editbox."));
}


void CMFC_Editbox_2Dlg::OnBnClickedClear1Button()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit1.SetSel(0, -1);
	m_Edit1.ReplaceSel(_T(""));
}


void CMFC_Editbox_2Dlg::OnBnClickedShow2Button()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit2.SetSel(0, -1);
	m_Edit2.ReplaceSel(_T("This is the second Editbox."));
}


void CMFC_Editbox_2Dlg::OnBnClickedClear2Button8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit2.SetSel(0, -1);
	m_Edit2.ReplaceSel(_T(""));
}




void CMFC_Editbox_2Dlg::OnBnClickedExitButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}


void CMFC_Editbox_2Dlg::OnBnClickedTranferButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit1.SetSel(0, -1);
	m_Edit1.Copy();
	m_Edit2.SetSel(0, -1);
	m_Edit2.ReplaceSel(_T(""));
	m_Edit2.Paste();
}


void CMFC_Editbox_2Dlg::OnBnClickedUndoButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Edit1.Undo();
	m_Edit2.Undo();
}
