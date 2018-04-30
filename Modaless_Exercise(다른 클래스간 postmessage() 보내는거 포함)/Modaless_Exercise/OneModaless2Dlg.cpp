// OneModaless2Dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "OneModaless2Dlg.h"
#include "Modaless_ExerciseDlg.h"

// COneModaless2Dlg ��ȭ �����Դϴ�.

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


// COneModaless2Dlg �޽��� ó�����Դϴ�.

void COneModaless2Dlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	m_pParentDlg->PostMessage(USER_MESSAGE_DELETE_DIALOG, NULL, NULL );
	

}


void COneModaless2Dlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	PostMessage(WM_DESTROY, 0, 0);
	
	CDialog::OnClose();
}

BOOL COneModaless2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
