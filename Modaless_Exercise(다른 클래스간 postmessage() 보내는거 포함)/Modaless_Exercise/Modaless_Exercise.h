
// Modaless_Exercise.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CModaless_ExerciseApp:
// �� Ŭ������ ������ ���ؼ��� Modaless_Exercise.cpp�� �����Ͻʽÿ�.
//

class CModaless_ExerciseApp : public CWinAppEx
{
public:
	CModaless_ExerciseApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CModaless_ExerciseApp theApp;