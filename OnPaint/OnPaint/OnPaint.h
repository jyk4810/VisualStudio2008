
// OnPaint.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// COnPaintApp:
// �� Ŭ������ ������ ���ؼ��� OnPaint.cpp�� �����Ͻʽÿ�.
//

class COnPaintApp : public CWinAppEx
{
public:
	COnPaintApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern COnPaintApp theApp;