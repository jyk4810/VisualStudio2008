
// PostMessageExercise.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPostMessageExerciseApp:
// �� Ŭ������ ������ ���ؼ��� PostMessageExercise.cpp�� �����Ͻʽÿ�.
//

class CPostMessageExerciseApp : public CWinAppEx
{
public:
	CPostMessageExerciseApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPostMessageExerciseApp theApp;