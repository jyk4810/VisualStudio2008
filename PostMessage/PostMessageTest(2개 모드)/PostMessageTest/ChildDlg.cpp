// ChildDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "PostMessageTest.h"
#include "ChildDlg.h"
#include "PostMessageTestDlg.h"

// CChildDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CChildDlg, CDialog)

CChildDlg::CChildDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChildDlg::IDD, pParent)
	, m_ComboIntegerNameIndex(0)
	, m_EditIntegerValue(_T(""))
	, m_ComboFloatNameIndex(0)
	, m_EditFloatValue(_T(""))
{
	m_pParentDlg = NULL;
	m_pParentDlg =(CPostMessageTestDlg*)AfxGetMainWnd();
	m_sInteger.IntegerName	= _T("Height");
	m_sInteger.IntegerValue	= _T("800");
}

CChildDlg::~CChildDlg()
{
}

void CChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_INTEGERNAME, m_ComboIntegerName);
	DDX_CBIndex(pDX, IDC_COMBO_INTEGERNAME, m_ComboIntegerNameIndex);
	DDX_Text(pDX, IDC_EDIT_INTEGERVALUE, m_EditIntegerValue);
	DDX_Control(pDX, IDC_COMBO_FLOATNAME, m_ComboFloatName);
	DDX_CBIndex(pDX, IDC_COMBO_FLOATNAME, m_ComboFloatNameIndex);
	DDX_Text(pDX, IDC_EDIT_FLOATVALUE, m_EditFloatValue);
}

BEGIN_MESSAGE_MAP(CChildDlg, CDialog)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_CBN_SELCHANGE(IDC_COMBO_INTEGERNAME, &CChildDlg::OnCbnSelchangeComboIntegername)
	ON_EN_UPDATE(IDC_EDIT_INTEGERVALUE, &CChildDlg::OnEnUpdateEditIntegervalue)
END_MESSAGE_MAP()
// CChildDlg 메시지 처리기입니다.

BOOL CChildDlg::PreTranslateMessage(MSG* pMsg)
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

void CChildDlg::OnDestroy()
{
	CDialog::OnDestroy();
	m_pParentDlg->PostMessage(USER_MESSAGE_DELETE_DIALOG, NULL, NULL );		
}

void CChildDlg::OnClose()
{
	PostMessage(WM_DESTROY, 0, 0);
	CDialog::OnClose();
}

BOOL CChildDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_ComboIntegerName.AddString(_T("Height"));
	m_ComboIntegerName.AddString(_T("Width"));
	m_ComboIntegerName.AddString(_T("AAAAA"));
	m_ComboIntegerName.SetCurSel(m_ComboIntegerNameIndex);
	m_EditIntegerValue = m_pParentDlg->GetParam(m_ComboIntegerNameIndex);

	m_ComboFloatName.AddString(_T("Height"));
	m_ComboFloatName.AddString(_T("Width"));
	m_ComboFloatName.AddString(_T("AAAAA"));
	m_ComboFloatName.SetCurSel(m_ComboFloatNameIndex);
	//m_EditFloatValue = GetHeightValue();
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CChildDlg::OnCbnSelchangeComboIntegername()
{
	m_ComboIntegerNameIndex = m_ComboIntegerName.GetCurSel();	
	m_ComboIntegerName.GetLBText(m_ComboIntegerNameIndex, m_sInteger.IntegerName);
	
	int mode = MESSAGE_TYPE_MODE;
	switch(mode)
	{
	case MESSAGE_TYPE_MODE_1:
	{		
		SettingValue(m_ComboIntegerNameIndex , &m_EditIntegerValue , &m_sInteger.IntegerValue , m_pParentDlg);
		UpdateData(false);
		m_pParentDlg->PostMessage(USER_MESSAGE_INTEGER_NAMEVALUE, INTEGER_NAME, (LPARAM)&m_sInteger );
		m_pParentDlg->PostMessage(USER_MESSAGE_INTEGER_NAMEVALUE, INTEGER_VALUE, (LPARAM)&m_sInteger);
		break;
	}
	case MESSAGE_TYPE_MODE_2:
		{
			CString name;
			m_ComboIntegerName.GetLBText(m_ComboIntegerNameIndex,name);
			m_pParentDlg->PostMessage(USER_MESSAGE_INTEGER_NAME,	NULL,		(LPARAM)&name );
		}
		break;
	}
}

void CChildDlg::OnEnUpdateEditIntegervalue()
{	
	UpdateData(true);
	SetValue(m_ComboIntegerNameIndex, m_EditIntegerValue);
	m_sInteger.IntegerValue = m_EditIntegerValue.GetBuffer(m_EditIntegerValue.GetLength());
	m_EditIntegerValue.ReleaseBuffer();

	int mode = MESSAGE_TYPE_MODE;
	switch(mode)
	{
	case MESSAGE_TYPE_MODE_1:
		{
			m_sInteger.IntegerValue= m_EditIntegerValue;
			m_pParentDlg->PostMessage(USER_MESSAGE_INTEGER_NAMEVALUE, INTEGER_VALUE, (LPARAM)&m_sInteger);
			break;
		}
	case MESSAGE_TYPE_MODE_2:
		{		
			CString value;
			value = m_EditIntegerValue.GetBuffer(m_EditIntegerValue.GetLength());
			m_EditIntegerValue.ReleaseBuffer();
			m_pParentDlg->PostMessage(USER_MESSAGE_INTEGER_VALUE,	  NULL,		 (LPARAM)&value);		
			break;
		}
	}
}



void CChildDlg::SetValue(int index, CString value)
{
	m_pParentDlg->SetParam(index, value);	
}

void CChildDlg::SettingValue(int m_ComboIntegerNameIndex , CString* pIntVal_edit , CString* pIntVal_struct , CPostMessageTestDlg* m_pParentDlg)
{
	switch(m_ComboIntegerNameIndex)
	{
	case 0:
		{
			*pIntVal_edit = m_pParentDlg->SetV(m_ComboIntegerNameIndex);				
			*pIntVal_struct = m_pParentDlg->SetV(m_ComboIntegerNameIndex);
			break;
		}
	case 1:
		{
			*pIntVal_edit = m_pParentDlg->SetV(m_ComboIntegerNameIndex);				
			*pIntVal_struct = m_pParentDlg->SetV(m_ComboIntegerNameIndex);
			break;
		}
	case 2:
		{
			*pIntVal_edit = m_pParentDlg->SetV(m_ComboIntegerNameIndex);				
			*pIntVal_struct = m_pParentDlg->SetV(m_ComboIntegerNameIndex);
			break;
		}
	}
}