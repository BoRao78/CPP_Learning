
// WIN_MFC_MS.h : WIN_MFC_MS 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CWIN_MFC_MSApp:
// 有关此类的实现，请参阅 WIN_MFC_MS.cpp
//

class CWIN_MFC_MSApp : public CWinAppEx
{
public:
	CWIN_MFC_MSApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWIN_MFC_MSApp theApp;
