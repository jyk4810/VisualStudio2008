
// ListBox.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CListBoxApp:
// �� Ŭ������ ������ ���ؼ��� ListBox.cpp�� �����Ͻʽÿ�.
//

class CListBoxApp : public CWinAppEx
{
public:
	CListBoxApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CListBoxApp theApp;