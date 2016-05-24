// Score.cpp : 实现文件
//

#include "stdafx.h"
#include "Ex_List.h"
#include "Score.h"
#include "Ex_ListDlg.h"
#include "afxdialogex.h"


// CScore 对话框

IMPLEMENT_DYNAMIC(CScore, CDialogEx)

CScore::CScore(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CScoreDlg, pParent)
	, m_CosNum(_T(""))
	, m_Credit(_T(""))
	, m_Num(_T(""))
	, m_Score(_T(""))
{

}

CScore::~CScore()
{
}

BOOL CScore::OnInitDialog()
{		
	CDialogEx::OnInitDialog();
	CEx_ListDlg *pDlg = (CEx_ListDlg *)GetParent();

	if (pDlg && pDlg->OnEdit) {
		int nItem = pDlg->m_List.GetSelectionMark();
		m_Num = pDlg->m_List.GetItemText(nItem, 0);
		m_CosNum = pDlg->m_List.GetItemText(nItem, 1);
		m_Score = pDlg->m_List.GetItemText(nItem, 2);
		m_Credit = pDlg->m_List.GetItemText(nItem, 3);
		UpdateData(FALSE);
		m_Button_AddChange.SetWindowTextW(_T("修改"));
	}
	else {
		m_Num = _T("");
		m_CosNum = _T("");
		m_Score = _T("");
		m_Credit = _T("");
		UpdateData(FALSE);
	}
	return 0;
}

void CScore::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CosNum, m_CosNum);
	DDX_Text(pDX, IDC_EDIT_Credit, m_Credit);
	DDX_Text(pDX, IDC_EDIT_Num, m_Num);
	DDX_Text(pDX, IDC_EDIT_Score, m_Score);
	DDX_Control(pDX, IDOK, m_Button_AddChange);
}


BEGIN_MESSAGE_MAP(CScore, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CScore::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CScore::OnBnClickedOk)
END_MESSAGE_MAP()


// CScore 消息处理程序


void CScore::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CScore::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CEx_ListDlg *pDlg = (CEx_ListDlg *)GetParent();

	if (pDlg && pDlg->OnEdit) {
		UpdateData(TRUE);
		pDlg->Number = m_Num;
		pDlg->CourseNumber = m_CosNum;
		pDlg->Score.Format(_T("%3.1f"), _wtof(m_Score.GetBuffer()));
		pDlg->Credit.Format(_T("%2.1f"), _wtof(m_Credit.GetBuffer()));

		int nItem = pDlg->m_List.GetSelectionMark();
		pDlg->m_List.SetItemText(nItem, 0, pDlg->Number);
		pDlg->m_List.SetItemText(nItem, 1, pDlg->CourseNumber);
		pDlg->m_List.SetItemText(nItem, 2, pDlg->Score);
		pDlg->m_List.SetItemText(nItem, 3, pDlg->Credit);
	}
	CDialogEx::OnOK();
}
