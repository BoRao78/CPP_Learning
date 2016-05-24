
// Ex_ListDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CEx_ListDlg �Ի���
class CEx_ListDlg : public CDialogEx
{
// ����
public:
	CEx_ListDlg(CWnd* pParent = NULL);	// ��׼���캯��

//���ݱ���
	BOOL OnEdit = 0;
	CString Number;
	CString CourseNumber;
	CString Score;
	CString Credit;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX_LIST_DIALOG };
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
