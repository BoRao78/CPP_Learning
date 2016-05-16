#pragma once
#include "afxwin.h"


// Logscreen 对话框

class Logscreen : public CDialogEx
{
	DECLARE_DYNAMIC(Logscreen)

public:
	Logscreen(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Logscreen();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CButton m_ok;
//	CButton m_Cancel;
//	CButton m_OK;
	afx_msg void OnEnChangeEdit1();
	CString m_Password;
};
