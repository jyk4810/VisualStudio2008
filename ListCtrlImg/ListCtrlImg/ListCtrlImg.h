
// ListCtrlImg.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CListCtrlImgApp:
// �� Ŭ������ ������ ���ؼ��� ListCtrlImg.cpp�� �����Ͻʽÿ�.
//

class CListCtrlImgApp : public CWinAppEx
{
public:
	CListCtrlImgApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CListCtrlImgApp theApp;