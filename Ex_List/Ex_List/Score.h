#pragma once
#include "afxwin.h"


// CScore 对话框

class CScore : public CDialogEx
{
	DECLARE_DYNAMIC(CScore)

public:
	CScore(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CScore();
	//CEx_ListDlg* pDlg;
	BOOL OnInitDialog();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CScoreDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	CString m_CosNum;
	CString m_Credit;
	CString m_Num;
	CString m_Score;
	CButton m_Button_AddChange;
	afx_msg void OnBnClickedOk();
};
