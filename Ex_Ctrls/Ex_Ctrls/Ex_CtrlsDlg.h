
// Ex_CtrlsDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CEx_CtrlsDlg �Ի���
class CEx_CtrlsDlg : public CDialogEx
{
// ����
public:
	CEx_CtrlsDlg(CWnd* pParent = NULL);	// ��׼���캯��

//�����������
	CString Name;
	CString Number;
	CString Gender;
	CString StrTime;
	CString Major;
	CString Edit;
	CString CourseName;
	CString CourseNumber;
	CString CourseMajor;
	CString CourseType;
	CString CourseTerm;
	CString CourseCount;
	CString CourseCredit;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX_CTRLS_DIALOG };
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
	CScrollBar m_Scrollbar1;
	CSliderCtrl m_Slider1;
	CSliderCtrl m_Slider2;
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CEdit m_Edit1;
	afx_msg void OnBnClickedButtonStu();
	afx_msg void OnBnClickedButtonCourse();
};
