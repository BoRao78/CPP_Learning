
// MFC_Control.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_ControlApp: 
// �йش����ʵ�֣������ MFC_Control.cpp
//

class CMFC_ControlApp : public CWinApp
{
public:
	CMFC_ControlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_ControlApp theApp;