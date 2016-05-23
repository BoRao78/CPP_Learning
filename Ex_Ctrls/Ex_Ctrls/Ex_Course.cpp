// Ex_Course.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex_Ctrls.h"
#include "Ex_Course.h"
#include "afxdialogex.h"


// Ex_Course �Ի���

IMPLEMENT_DYNAMIC(Ex_Course, CDialogEx)

Ex_Course::Ex_Course(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Course, pParent)
	, m_MajorData(_T(""))
	, m_TypeData(_T(""))
	, m_CosCount(_T(""))
	, m_CosName(_T(""))
	, m_Credit(_T(""))
	, m_CosNum(_T(""))
	, m_EditTermData(_T(""))
{

}

Ex_Course::~Ex_Course()
{
}

BOOL Ex_Course::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_Major.AddString(_T("��е���̼��Զ���"));
	m_Major.AddString(_T("�����Ϣ����"));
	m_Major.AddString(_T("���ڹ���"));
	m_Major.AddString(_T("��ҵ����"));
	m_MajorData = _T("��е���̼��Զ���");
	m_Type.AddString(_T("ͨʶ"));
	m_Type.AddString(_T("ƽ̨"));
	m_Type.AddString(_T("ר��"));
	m_Type.AddString(_T("ѡ��"));
	m_TypeData = _T("ר��");
	m_SpinTerm.SetRange(1, 8);
	m_SpinTerm.SetPos(1);
	m_SpinTerm.GetBuddy()->SetWindowText(_T("1"));
	m_EditTermData = _T("1");
	UpdateData(FALSE);
	return 0;
}

void Ex_Course::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Major, m_Major);
	DDX_CBString(pDX, IDC_COMBO_Major, m_MajorData);
	DDX_Control(pDX, IDC_COMBO_Type, m_Type);
	DDX_CBString(pDX, IDC_COMBO_Type, m_TypeData);
	DDX_Text(pDX, IDC_EDIT_CosCount, m_CosCount);
	DDX_Text(pDX, IDC_Edit_CosName, m_CosName);
	DDX_Control(pDX, IDC_EDIT_Term, m_EditTerm);
	DDX_Text(pDX, IDC_EDIT_Credit, m_Credit);
	DDX_Control(pDX, IDC_SPIN_Term, m_SpinTerm);
	DDX_Text(pDX, IDC_Edit_CosNum, m_CosNum);
	DDX_Text(pDX, IDC_EDIT_Term, m_EditTermData);
}


BEGIN_MESSAGE_MAP(Ex_Course, CDialogEx)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// Ex_Course ��Ϣ�������


void Ex_Course::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT iNowPos = 0;
	CString term;
	if (pScrollBar->GetDlgCtrlID() == IDC_SPIN_Term) {//�ж��Ƿ����Ե�ǰSpin
			if (nPos >8)  nPos = 8;
			if (nPos <1)  nPos = 1;
			term.Format(_T("%d"), nPos);
			((CSpinButtonCtrl*)pScrollBar)->GetBuddy()->SetWindowText(term);
		}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
