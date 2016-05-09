
// MFC_ControlDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC_ControlDlg 对话框
class CMFC_ControlDlg : public CDialogEx
{
// 构造
public:
	CMFC_ControlDlg(CWnd* pParent = NULL);	// 标准构造函数

	CBrush m_brush;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CONTROL_DIALOG };
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnClickedOk();
	CButton m_ok;
	CButton m_rdc4;
	int m_rd4;
	CButton m_rdc1;
	int m_rd1;
	CStatic m_static1;
	afx_msg void OnClickedStatic1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
