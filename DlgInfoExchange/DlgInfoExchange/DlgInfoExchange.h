
// DlgInfoExchange.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDlgInfoExchangeApp:
// �� Ŭ������ ������ ���ؼ��� DlgInfoExchange.cpp�� �����Ͻʽÿ�.
//

class CDlgInfoExchangeApp : public CWinAppEx
{
public:
	CDlgInfoExchangeApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDlgInfoExchangeApp theApp;