// Logscreen.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_Contro_3.h"
#include "Logscreen.h"
#include "afxdialogex.h"


// Logscreen �Ի���

IMPLEMENT_DYNAMIC(Logscreen, CDialogEx)

Logscreen::Logscreen(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_Password(_T(""))
{

}

Logscreen::~Logscreen()
{
}

void Logscreen::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, m_ok);
	//  DDX_Control(pDX, IDCANCEL, m_Cancel);
	//  DDX_Control(pDX, IDOK, m_OK);
	DDX_Text(pDX, IDC_EDIT1, m_Password);
}


BEGIN_MESSAGE_MAP(Logscreen, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Logscreen::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &Logscreen::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Logscreen ��Ϣ�������


void Logscreen::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Logscreen::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
