// Ex_Stu.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Ex_Ctrls.h"
#include "Ex_Stu.h"
#include "afxdialogex.h"


// Ex_Stu �Ի���

IMPLEMENT_DYNAMIC(Ex_Stu, CDialogEx)

Ex_Stu::Ex_Stu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_Stu, pParent)
	, m_Gender(FALSE)
	, m_NameData(_T(""))
	, m_NumberData(_T(""))
	, m_MajorData(_T(""))
	, m_TimeData(COleDateTime::GetCurrentTime())
{

}

Ex_Stu::~Ex_Stu()
{
}

BOOL Ex_Stu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_Major.AddString(_T("��е���̼��Զ���"));
	m_Major.AddString(_T("�����Ϣ����"));
	m_Major.AddString(_T("���ڹ���"));
	m_Major.AddString(_T("��ҵ����"));
	m_MajorData = _T("��е���̼��Զ���");
	UpdateData(FALSE);
	return 0;
}

void Ex_Stu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Name);
	DDX_Control(pDX, IDC_EDIT2, m_Number);
	DDX_Radio(pDX, IDC_RADIO1, m_Gender);
	DDX_Control(pDX, IDC_COMBO1, m_Major);
	DDX_Text(pDX, IDC_EDIT1, m_NameData);
	DDX_Text(pDX, IDC_EDIT2, m_NumberData);
	DDX_CBString(pDX, IDC_COMBO1, m_MajorData);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_TimeData);
}


BEGIN_MESSAGE_MAP(Ex_Stu, CDialogEx)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &Ex_Stu::OnDtnDatetimechangeDatetimepicker1)
END_MESSAGE_MAP()



void Ex_Stu::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
