
// TryCatch.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTryCatchApp:
// �� Ŭ������ ������ ���ؼ��� TryCatch.cpp�� �����Ͻʽÿ�.
//

class CTryCatchApp : public CWinAppEx
{
public:
	CTryCatchApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

extern CTryCatchApp theApp;