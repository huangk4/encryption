
// ��Ӣ���������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��Ӣ���������App: 
// �йش����ʵ�֣������ ��Ӣ���������.cpp
//

class C��Ӣ���������App : public CWinApp
{
public:
	C��Ӣ���������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��Ӣ���������App theApp;