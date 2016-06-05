
// Ex_SDI.h : Ex_SDI 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CEx_SDIApp:
// 有关此类的实现，请参阅 Ex_SDI.cpp
//

class CEx_SDIApp : public CWinApp
{
public:
	CEx_SDIApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEx_SDIApp theApp;
