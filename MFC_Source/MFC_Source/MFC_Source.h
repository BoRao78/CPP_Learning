
// MFC_Source.h : MFC_Source Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_SourceApp:
// �йش����ʵ�֣������ MFC_Source.cpp
//

class CMFC_SourceApp : public CWinApp
{
public:
	CMFC_SourceApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_SourceApp theApp;
