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
	ON_CBN_SELCHANGE(IDC_COMBO_FLOATNAME, &CChildDlg::OnCbnSelchangeComboFloatname)
	ON_EN_UPDATE(IDC_EDIT_FLOATVALUE, &CChildDlg::OnEnUpdateEditFloatvalue)	
END_MESSAGE_MAP()
// CChildDlg 메시지 처리기입니다.

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

	CString strVal;

	m_ComboIntegerName.AddString(_T("Height"));									//((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("Exposure"));
	m_ComboIntegerName.AddString(_T("Width"));
	m_ComboIntegerName.AddString(_T("OffsetX"));
	m_ComboIntegerName.AddString(_T("OffsetY"));
	m_ComboIntegerName.SetCurSel(m_ComboIntegerNameIndex);						//((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->SetCurSel(m_ComboFloatNameIndex);
	m_ComboIntegerName.GetLBText(m_ComboIntegerNameIndex, strVal);				//GetDlgItemText(IDC_COMBO_FLOATNAME, strVal);
	m_EditIntegerValue = m_pParentDlg->GetParam(VALUE_TYPE_INTEGER, strVal);
	UpdateData(false);															//SetDlgItemText(IDC_EDIT_FLOATVALUE, m_EditFloatValue);

	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("Exposure"));
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("Time"));
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->AddString(_T("Pixel"));
	((CComboBox*)GetDlgItem(IDC_COMBO_FLOATNAME))->SetCurSel(m_ComboFloatNameIndex);
	GetDlgItemText(IDC_COMBO_FLOATNAME, strVal);
	m_Struct.Value = m_pParentDlg->GetParam(VALUE_TYPE_FLOAT, strVal);
	SetDlgItemText(IDC_EDIT_FLOATVALUE, m_Struct.Value);

//	m_ComboFloatName.AddString(_T("Exposure"));
//	m_ComboFloatName.AddString(_T("Time"));
//	m_ComboFloatName.AddString(_T("Pixel"));
//	m_ComboFloatName.SetCurSel(m_ComboFloatNameIndex);
//	m_ComboFloatName.GetLBText(m_ComboFloatNameIndex, strVal);
//	m_EditFloatValue = m_pParentDlg->GetParam(VALUE_TYPE_FLOAT, strVal);	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void CChildDlg::OnCbnSelchangeComboIntegername()
{
	m_ComboIntegerNameIndex = m_ComboIntegerName.GetCurSel();	
	m_ComboIntegerName.GetLBText(m_ComboIntegerNameIndex, m_Struct.Name);
	m_EditIntegerValue = m_pParentDlg->GetParam(VALUE_TYPE_INTEGER, m_Struct.Name);
	m_Struct.Value = m_EditIntegerValue;
	UpdateData(false);
	m_pParentDlg->PostMessage(USER_MESSAGE_VALUE, PARAM_VALUE_INTEGER, (LPARAM)&m_Struct);		
}
void CChildDlg::OnEnUpdateEditIntegervalue()
{	
	UpdateData(true);
	m_Struct.Value = m_EditIntegerValue.GetBuffer(m_EditIntegerValue.GetLength());
	m_EditIntegerValue.ReleaseBuffer();	
	m_pParentDlg->PostMessage(USER_MESSAGE_VALUE, PARAM_VALUE_INTEGER, (LPARAM)&m_Struct);		
	m_pParentDlg->SetParam(VALUE_TYPE_INTEGER, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::OnCbnSelchangeComboFloatname()
{
	GetDlgItemText(IDC_COMBO_FLOATNAME, m_Struct.Name);
	m_Struct.Value =m_pParentDlg->GetParam(VALUE_TYPE_FLOAT, m_Struct.Name);
	SetDlgItemText(IDC_EDIT_FLOATVALUE, m_Struct.Value);
	m_pParentDlg->PostMessage(USER_MESSAGE_VALUE, PARAM_VALUE_FLOAT, (LPARAM)&m_Struct); // staticText에 정보 show
}
void CChildDlg::OnEnUpdateEditFloatvalue()
{
	GetDlgItemText(IDC_COMBO_FLOATNAME, m_Struct.Name);
	GetDlgItemText(IDC_EDIT_FLOATVALUE, m_Struct.Value);
	m_pParentDlg->PostMessage(USER_MESSAGE_VALUE, PARAM_VALUE_FLOAT, (LPARAM)&m_Struct); // staticText에 정보 show
	m_pParentDlg->SetParam(VALUE_TYPE_FLOAT, m_Struct.Name, m_Struct.Value);
}
void CChildDlg::SetValue(int type, CString strName, CString strValue)
{
	m_pParentDlg->SetParam(type, strName, strValue);
}
CString CChildDlg::GetValue(int type, CString strName)
{
	return m_pParentDlg->GetParam(type, strName);
}
