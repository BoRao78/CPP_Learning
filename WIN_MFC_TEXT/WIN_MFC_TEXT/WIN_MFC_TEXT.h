
// WIN_MFC_TEXT.h : WIN_MFC_TEXT Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWIN_MFC_TEXTApp:
// �йش����ʵ�֣������ WIN_MFC_TEXT.cpp
//

class CWIN_MFC_TEXTApp : public CWinApp
{
public:
	CWIN_MFC_TEXTApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWIN_MFC_TEXTApp theApp;
