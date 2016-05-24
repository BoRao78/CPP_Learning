
// Ex_ListDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CEx_ListDlg 对话框
class CEx_ListDlg : public CDialogEx
{
// 构造
public:
	CEx_ListDlg(CWnd* pParent = NULL);	// 标准构造函数

//数据变量
	BOOL OnEdit = 0;
	CString Number;
	CString CourseNumber;
	CString Score;
	CString Credit;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX_LIST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnNMClickList(NMHDR *pNMHDR, LRESULT *pResult);
	CButton m_ButtonChange;
	CButton m_ButtonDelete;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonChange();
	CButton m_ButtonAdd;
	afx_msg void OnBnClickedButtonAdd();
};
