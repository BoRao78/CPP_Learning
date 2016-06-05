
// MFC_Source.h : MFC_Source 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFC_SourceApp:
// 有关此类的实现，请参阅 MFC_Source.cpp
//

class CMFC_SourceApp : public CWinApp
{
public:
	CMFC_SourceApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_SourceApp theApp;
