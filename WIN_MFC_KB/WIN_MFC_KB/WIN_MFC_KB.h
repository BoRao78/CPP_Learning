
// WIN_MFC_KB.h : WIN_MFC_KB Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CWIN_MFC_KBApp:
// �йش����ʵ�֣������ WIN_MFC_KB.cpp
//

class CWIN_MFC_KBApp : public CWinAppEx
{
public:
	CWIN_MFC_KBApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWIN_MFC_KBApp theApp;
