
// MFC_Demo.h : MFC_Demo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_DemoApp:
// �йش����ʵ�֣������ MFC_Demo.cpp
//

class CMFC_DemoApp : public CWinApp
{
public:
	CMFC_DemoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_DemoApp theApp;
