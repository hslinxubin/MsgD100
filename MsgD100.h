
// MsgD100.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMsgD100App:
// �йش����ʵ�֣������ MsgD100.cpp
//

class CMsgD100App : public CWinApp
{
public:
	CMsgD100App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMsgD100App theApp;