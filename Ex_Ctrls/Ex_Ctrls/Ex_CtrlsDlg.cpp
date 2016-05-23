
// Ex_CtrlsDlg.cpp : ʵ���ļ�
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


// CEx_CtrlsDlg �Ի���



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


// CEx_CtrlsDlg ��Ϣ�������

BOOL CEx_CtrlsDlg::OnInitDialog()
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
	m_Scrollbar1.SetScrollRange(0, 255);
	m_Scrollbar1.SetScrollPos(100);
	m_Slider1.SetRange(0, 255);
	m_Slider1.SetPos(150);
	m_Slider2.SetRange(0, 255);
	m_Slider2.SetPos(200);

	Edit = _T("������") + Name + _T("\r\nѧ�ţ�") + Number + _T("\r\n�Ա�") + Gender + _T("\r\n�������£�") + StrTime + _T("\r\n��ѧרҵ��") + Major;
	m_Edit1.SetWindowText(Edit);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CEx_CtrlsDlg::OnPaint()
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
HCURSOR CEx_CtrlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEx_CtrlsDlg::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


HBRUSH CEx_CtrlsDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	HBRUSH Brush = CreateSolidBrush(RGB(m_Scrollbar1.GetScrollPos(),
		m_Slider1.GetPos(),
		m_Slider2.GetPos()));
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return Brush;
}


void CEx_CtrlsDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT iNowPos = 0;
	if (pScrollBar == &m_Scrollbar1 || &m_Slider1 || &m_Slider2) {//�ж��Ƿ����Ե�ǰ����������Ϣ
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
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CEx_CtrlsDlg::OnBnClickedButtonStu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Ex_Stu StuDlg;
	if (StuDlg.DoModal() == IDOK) {
			Name = StuDlg.m_NameData;
			Number = StuDlg.m_NumberData;
			if (StuDlg.m_Gender == 0) Gender = "��";
			else Gender = "Ů";
			StrTime = StuDlg.m_TimeData.Format(_T("%Y - %m - %d"));
			Major = StuDlg.m_MajorData;
			Edit = _T("������") + Name + _T("\r\nѧ�ţ�") + Number + _T("\r\n�Ա�") + Gender + _T("\r\n�������£�") + StrTime + _T("\r\n��ѧרҵ��") + Major;
			m_Edit1.SetSel(0,-1);
			m_Edit1.ReplaceSel(Edit);
	}
}


void CEx_CtrlsDlg::OnBnClickedButtonCourse()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Ex_Course CourseDlg;
	if (CourseDlg.DoModal() == IDOK) {
		CourseName = CourseDlg.m_CosName;
		CourseNumber = CourseDlg.m_CosNum;
		CourseMajor = CourseDlg.m_MajorData;
		CourseType = CourseDlg.m_TypeData;
		CourseTerm = CourseDlg.m_EditTermData;
		CourseCount = CourseDlg.m_CosCount;
		CourseCredit = CourseDlg.m_Credit;
		Edit = _T("�γ̺ţ�") + CourseNumber + _T("\r\n�γ����ƣ�") + CourseName + _T("\r\n����רҵ��") + CourseMajor + _T("\r\n�γ����ͣ�") + CourseType + _T("\r\n����ѧ�ڣ�") + CourseTerm + _T("\r\n��ʱ����") + CourseCount + _T("\r\nѧ�֣�") + CourseCredit;
		m_Edit1.SetSel(0, -1);
		m_Edit1.ReplaceSel(Edit);
	}
}
