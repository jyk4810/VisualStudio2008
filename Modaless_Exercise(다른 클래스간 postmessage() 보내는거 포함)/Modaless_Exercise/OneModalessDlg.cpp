// OneModalessDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "OneModalessDlg.h"
#include "Modaless_ExerciseDlg.h"

// COneModalessDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COneModalessDlg, CDialog)

COneModalessDlg::COneModalessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COneModalessDlg::IDD, pParent)
{
	
	m_pParentDlg =(CModaless_ExerciseDlg*)pParent;

}

COneModalessDlg::~COneModalessDlg()
{
}

void COneModalessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COneModalessDlg, CDialog)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// COneModalessDlg 메시지 처리기입니다.

void COneModalessDlg::OnDestroy()
{

	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	delete this;
	
}

void COneModalessDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	PostMessage(WM_DESTROY, 0, 0);	
	m_pParentDlg->m_bIsCreatedOneModalessDlg = FALSE;
	
	CDialog::OnClose();
}

BOOL COneModalessDlg::PreTranslateMessage(MSG* pMsg)
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
