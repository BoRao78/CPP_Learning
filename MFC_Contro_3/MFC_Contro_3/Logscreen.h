#pragma once
#include "afxwin.h"


// Logscreen �Ի���

class Logscreen : public CDialogEx
{
	DECLARE_DYNAMIC(Logscreen)

public:
	Logscreen(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Logscreen();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CButton m_ok;
//	CButton m_Cancel;
//	CButton m_OK;
	afx_msg void OnEnChangeEdit1();
	CString m_Password;
};
