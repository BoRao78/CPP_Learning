
// Ex_Ctrls.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEx_CtrlsApp: 
// �йش����ʵ�֣������ Ex_Ctrls.cpp
//

class CEx_CtrlsApp : public CWinApp
{
public:
	CEx_CtrlsApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEx_CtrlsApp theApp;