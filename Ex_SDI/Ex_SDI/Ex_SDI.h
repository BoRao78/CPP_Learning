
// Ex_SDI.h : Ex_SDI Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CEx_SDIApp:
// �йش����ʵ�֣������ Ex_SDI.cpp
//

class CEx_SDIApp : public CWinApp
{
public:
	CEx_SDIApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEx_SDIApp theApp;
