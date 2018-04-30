// OneModalessDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "OneModalessDlg.h"
#include "Modaless_ExerciseDlg.h"

// COneModalessDlg ��ȭ �����Դϴ�.

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


// COneModalessDlg �޽��� ó�����Դϴ�.

void COneModalessDlg::OnDestroy()
{

	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	delete this;
	
}

void COneModalessDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	PostMessage(WM_DESTROY, 0, 0);	
	m_pParentDlg->m_bIsCreatedOneModalessDlg = FALSE;
	
	CDialog::OnClose();
}

BOOL COneModalessDlg::PreTranslateMessage(MSG* pMsg)
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
