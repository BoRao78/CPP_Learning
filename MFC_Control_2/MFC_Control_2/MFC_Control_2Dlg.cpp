
// MFC_Control_2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Control_2.h"
#include "MFC_Control_2Dlg.h"
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


// CMFC_Control_2Dlg �Ի���



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


// CMFC_Control_2Dlg ��Ϣ�������

BOOL CMFC_Control_2Dlg::OnInitDialog()
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
	//ScrollBar Initial
	m_ScrollBar1.SetScrollRange(0, 255);
	m_ScrollBar1.SetScrollPos(100);
	m_ScrollBar2.SetScrollRange(0, 255);
	m_ScrollBar2.SetScrollPos(150);
	m_ScrollBar3.SetScrollRange(0, 255);
	m_ScrollBar3.SetScrollPos(200);
	//UpdateData(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_Control_2Dlg::OnPaint()
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
HCURSOR CMFC_Control_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_Control_2Dlg::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;

}


void CMFC_Control_2Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT iNowPos = 0;
	if (pScrollBar == &m_ScrollBar1 || &m_ScrollBar2 || &m_ScrollBar3) {//�ж��Ƿ����Ե�ǰ����������Ϣ
			switch (nSBCode) {
			case SB_THUMBTRACK:	//�϶�����
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
	// TODO:  �ڴ˸��� DC ���κ�����

	HBRUSH Brush = CreateSolidBrush(RGB(m_ScrollBar1.GetScrollPos(),
		m_ScrollBar2.GetScrollPos(),
		m_ScrollBar3.GetScrollPos()));
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return Brush;
}
