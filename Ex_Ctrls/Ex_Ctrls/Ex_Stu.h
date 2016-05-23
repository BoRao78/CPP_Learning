#pragma once
#include "afxwin.h"
#include "afxdtctl.h"
#include "ATLComTime.h"


// Ex_Stu 对话框

class Ex_Stu : public CDialogEx
{
	DECLARE_DYNAMIC(Ex_Stu)

public:
	Ex_Stu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Ex_Stu();
	BOOL OnInitDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Stu };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CButton m_Radio;
//	BOOL m_Radio;
//	CDateTimeCtrl m_DateTime;
	CEdit m_Name;
	CEdit m_Number;
	BOOL m_Gender;
	CComboBox m_Major;
	CString m_NameData;
	CString m_NumberData;
	CString m_MajorData;
//	CString m_TimeData;
	afx_msg void OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult);
	COleDateTime m_TimeData;
};
