// OneModaless2Dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "OneModaless2Dlg.h"
#include "Modaless_ExerciseDlg.h"

// COneModaless2Dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COneModaless2Dlg, CDialog)

COneModaless2Dlg::COneModaless2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(COneModaless2Dlg::IDD, pParent)
{
	m_pParentDlg =(CModaless_ExerciseDlg*)AfxGetMainWnd();
	
}

COneModaless2Dlg::~COneModaless2Dlg()
{
}

void COneModaless2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COneModaless2Dlg, CDialog)
	ON_WM_DESTROY()
	
	ON_WM_CLOSE()
	END_MESSAGE_MAP()


// COneModaless2Dlg 메시지 처리기입니다.

void COneModaless2Dlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_pParentDlg->PostMessage(USER_MESSAGE_DELETE_DIALOG, NULL, NULL );
	

}


void COneModaless2Dlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PostMessage(WM_DESTROY, 0, 0);
	
	CDialog::OnClose();
}

BOOL COneModaless2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(pMsg->message == WM_KEYDOWN) 			
	{			
		switch(pMsg->wParam)			
		{			
		case VK_RETURN:			
		case VK_ESCAPE:			
			return TRUE;			
		default:			
			break;			
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
