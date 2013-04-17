
// MsgD100.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMsgD100App:
// 有关此类的实现，请参阅 MsgD100.cpp
//

class CMsgD100App : public CWinApp
{
public:
	CMsgD100App();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMsgD100App theApp;