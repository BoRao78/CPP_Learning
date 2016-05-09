
// MFC_Control_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_Control_1Dlg �Ի���
class CMFC_Control_1Dlg : public CDialogEx
{
// ����
public:
	CMFC_Control_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CString configstr;
	CString memory[3] = { _T("512M"), _T("1G"), _T("2G") };
	CString seconfig[4] = { _T("����ͷ"), _T("��������"), _T("��������"), _T("��Ϸ�ֱ�") };
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CONTROL_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
