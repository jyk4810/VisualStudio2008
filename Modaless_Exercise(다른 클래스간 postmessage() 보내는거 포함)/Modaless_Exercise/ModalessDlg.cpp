// ModalessDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "ModalessDlg.h"

#include "Modaless_ExerciseDlg.h"

// CModalessDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CModalessDlg, CDialog)

CModalessDlg::CModalessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModalessDlg::IDD, pParent)
{
	
	CModaless_ExerciseDlg* pModaless_ExerciseDlg = (CModaless_ExerciseDlg*)::AfxGetMainWnd();
	
}

CModalessDlg::~CModalessDlg()
{
}

void CModalessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CModalessDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CModalessDlg 메시지 처리기입니다.

void CModalessDlg::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	CDialog::PostNcDestroy();
}

void CModalessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(nID==SC_CLOSE)

    {
       
    }
	CDialog::OnSysCommand(nID, lParam);
}

void CModalessDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PostMessage(WM_DESTROY, 0, 0);	
	
	CDialog::OnClose();
	
}

void CModalessDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	delete this;
}

BOOL CModalessDlg::PreTranslateMessage(MSG* pMsg)
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
