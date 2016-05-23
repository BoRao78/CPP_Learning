#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Ex_Course 对话框

class Ex_Course : public CDialogEx
{
	DECLARE_DYNAMIC(Ex_Course)

public:
	Ex_Course(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Ex_Course();
	BOOL OnInitDialog();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Course };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Major;
	CString m_MajorData;
	CComboBox m_Type;
	CString m_TypeData;
	CString m_CosCount;
	CString m_CosName;
	CEdit m_EditTerm;
	CString m_Credit;
	CSpinButtonCtrl m_SpinTerm;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CString m_CosNum;
	CString m_EditTermData;
};
