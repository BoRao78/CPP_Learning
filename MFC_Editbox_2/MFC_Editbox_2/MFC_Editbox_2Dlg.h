
// MFC_Editbox_2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_Editbox_2Dlg �Ի���
class CMFC_Editbox_2Dlg : public CDialogEx
{
// ����
public:
	CMFC_Editbox_2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_EDITBOX_2_DIALOG };
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
	afx_msg void OnEnChangeEdit1();
	CEdit m_Edit1;
	CEdit m_Edit2;
	afx_msg void OnBnClickedShow1Button();
	afx_msg void OnBnClickedClear1Button();
	afx_msg void OnBnClickedShow2Button();
	afx_msg void OnBnClickedClear2Button8();
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnBnClickedTranferButton();
	afx_msg void OnBnClickedUndoButton();
};
