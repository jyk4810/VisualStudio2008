
// ListCtrl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CListCtrlApp:
// �� Ŭ������ ������ ���ؼ��� ListCtrl.cpp�� �����Ͻʽÿ�.
//

class CListCtrlApp : public CWinAppEx
{
public:
	CListCtrlApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CListCtrlApp theApp;