#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// Ex_Course �Ի���

class Ex_Course : public CDialogEx
{
	DECLARE_DYNAMIC(Ex_Course)

public:
	Ex_Course(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Ex_Course();
	BOOL OnInitDialog();
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Course };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
