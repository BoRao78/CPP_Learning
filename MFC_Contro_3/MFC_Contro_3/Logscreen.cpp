// Logscreen.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Contro_3.h"
#include "Logscreen.h"
#include "afxdialogex.h"


// Logscreen 对话框

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


// Logscreen 消息处理程序


void Logscreen::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Logscreen::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
