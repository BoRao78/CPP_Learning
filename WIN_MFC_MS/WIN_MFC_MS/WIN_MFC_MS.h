
// WIN_MFC_MS.h : WIN_MFC_MS Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWIN_MFC_MSApp:
// �йش����ʵ�֣������ WIN_MFC_MS.cpp
//

class CWIN_MFC_MSApp : public CWinAppEx
{
public:
	CWIN_MFC_MSApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWIN_MFC_MSApp theApp;
