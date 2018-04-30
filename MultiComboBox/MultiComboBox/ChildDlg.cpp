// ChildDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiComboBox.h"
#include "ChildDlg.h"
#include "MultiComboBoxDlg.h"

// CChildDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChildDlg, CDialog)

CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChildDlg::IDD, pParent)
{
	m_pParentDlg = (CMultiComboBoxDlg*)AfxGetMainWnd();
}

CChildDlg::~CChildDlg()
{
}

void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChildDlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO_NUMBER, &CChildDlg::OnCbnSelchangeComboNumber)
END_MESSAGE_MAP()


// CChildDlg 메시지 처리기입니다.

void CChildDlg::OnClose()
{
	PostMessage(WM_DESTROY, 0, 0);
	CDialog::OnClose();
}

void CChildDlg::OnDestroy()
{
	CDialog::OnDestroy();
	m_pParentDlg->PostMessage(USER_MESSAGE_DELETE_DIALOG, NULL, NULL );
}

BOOL CChildDlg::PreTranslateMessage(MSG* pMsg)
{
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

BOOL CChildDlg::OnInitDialog()
{
	CDialog::OnInitDialog();	

	((CComboBox*)GetDlgItem(IDC_COMBO_NUMBER))->AddString(_T("1"));
	((CComboBox*)GetDlgItem(IDC_COMBO_NUMBER))->AddString(_T("2"));
	((CComboBox*)GetDlgItem(IDC_COMBO_NUMBER))->AddString(_T("3"));

	((CComboBox*)GetDlgItem(IDC_COMBO_NUMBER))->SetCurSel(0);
	SetEnumEntry();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CChildDlg::SetEnumEntry()
{	
	((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->ResetContent();
	int count = 0;
	CString strEnumEntry = _T("");
	int index = ((CComboBox*)GetDlgItem(IDC_COMBO_NUMBER))->GetCurSel();
	m_pParentDlg->GetEnumCount(index, &count);
	
	for(int i=0; i<count; i++)
	{
		m_pParentDlg->GetEnumEntry(index, i, &strEnumEntry);
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(strEnumEntry);
	}

	int entryIdx = 0;
	m_pParentDlg->GetEnumEntryIntValue(index, &entryIdx);
	((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->SetCurSel(entryIdx);
}


void CChildDlg::OnCbnSelchangeComboNumber()
{
	SetEnumEntry();

	/*((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->ResetContent();

	int a;
	a=((CComboBox*)GetDlgItem(IDC_COMBO_NUMBER))->GetCurSel();
		
	if (  a== m_pParentDlg->A )
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("A1"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("B1"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("C1"));
	}
	else if (a == m_pParentDlg->B )
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("A2"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("B2"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("C2"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("D2"));
	}
	else if ( a== m_pParentDlg->C )
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("A3"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("B3"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("C3"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("D3"));
		((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->AddString(_T("E3"));
	}
	
	m_pParentDlg->GetVal( ((CComboBox*)GetDlgItem(IDC_COMBO_VALUE))->GetCount() );*/
}

