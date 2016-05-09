
// MFC_Control_1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFC_Control_1Dlg 对话框
class CMFC_Control_1Dlg : public CDialogEx
{
// 构造
public:
	CMFC_Control_1Dlg(CWnd* pParent = NULL);	// 标准构造函数
	CString configstr;
	CString memory[3] = { _T("512M"), _T("1G"), _T("2G") };
	CString seconfig[4] = { _T("摄像头"), _T("无线网卡"), _T("蓝牙耳机"), _T("游戏手柄") };
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CONTROL_1_DIALOG };
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
	int m_memory;
	BOOL m_config1;
	BOOL m_config2;
	BOOL m_config3;
	BOOL m_config4;
	CButton m_commit;
	CButton m_reselect;
	afx_msg void OnClickedCommit();
	afx_msg void OnClickedReselect();
	CStatic m_config;
};
