
// Ex_List.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CEx_ListApp: 
// �йش����ʵ�֣������ Ex_List.cpp
//

class CEx_ListApp : public CWinApp
{
public:
	CEx_ListApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CEx_ListApp theApp;