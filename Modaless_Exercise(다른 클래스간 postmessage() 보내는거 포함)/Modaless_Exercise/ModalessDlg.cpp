// ModalessDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "ModalessDlg.h"

#include "Modaless_ExerciseDlg.h"

// CModalessDlg ��ȭ �����Դϴ�.

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


// CModalessDlg �޽��� ó�����Դϴ�.

void CModalessDlg::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	CDialog::PostNcDestroy();
}

void CModalessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(nID==SC_CLOSE)

    {
       
    }
	CDialog::OnSysCommand(nID, lParam);
}

void CModalessDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	PostMessage(WM_DESTROY, 0, 0);	
	
	CDialog::OnClose();
	
}

void CModalessDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	delete this;
}

BOOL CModalessDlg::PreTranslateMessage(MSG* pMsg)
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
