
// PostAndSendMessage.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPostAndSendMessageApp:
// �� Ŭ������ ������ ���ؼ��� PostAndSendMessage.cpp�� �����Ͻʽÿ�.
//

class CPostAndSendMessageApp : public CWinAppEx
{
public:
	CPostAndSendMessageApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPostAndSendMessageApp theApp;