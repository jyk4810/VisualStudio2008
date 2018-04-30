
// PostMessageTestDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "PostMessageTest.h"
#include "PostMessageTestDlg.h"
#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CPostMessageTestDlg ��ȭ ����

CPostMessageTestDlg::CPostMessageTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPostMessageTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pChildDlg		= NULL;
	m_HeightValue   = _T("800");
	m_WidthValue	= _T("600");
	m_AAAAAValue	= _T("1000");	
}

void CPostMessageTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_INTEGERNAME, m_integerName);
	DDX_Control(pDX, IDC_STATIC_INTEGERVALUE, m_integerValue);
}

BEGIN_MESSAGE_MAP(CPostMessageTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP

	ON_BN_CLICKED(IDC_BUTTON_CHILDDIALOG, &CPostMessageTestDlg::OnBnClickedButtonChilddialog)
	ON_MESSAGE(USER_MESSAGE_DELETE_DIALOG, OnUserMessageDeleteDialog)
	ON_MESSAGE(USER_MESSAGE_INTEGER_NAMEVALUE, OnUserMessageIntegerNameValue)
	ON_MESSAGE(USER_MESSAGE_INTEGER_NAME, OnUserMessageIntegerName)
	ON_MESSAGE(USER_MESSAGE_INTEGER_VALUE, OnUserMessageIntegerValue)
	
	ON_WM_DESTROY()
END_MESSAGE_MAP()
// CPostMessageTestDlg �޽��� ó����

BOOL CPostMessageTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_integerName.SetWindowTextW(_T("Height"));
	m_integerValue.SetWindowTextW(m_HeightValue);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPostMessageTestDlg::OnDestroy()
{
	CDialog::OnDestroy();	
	
}


BOOL CPostMessageTestDlg::PreTranslateMessage(MSG* pMsg)
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



void CPostMessageTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CPostMessageTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CPostMessageTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPostMessageTestDlg::OnBnClickedButtonChilddialog()
{
	if( m_pChildDlg == NULL )
	{
		m_pChildDlg = new CChildDlg(this);
		m_pChildDlg->Create(IDD_DIALOG_CHILDDIALOG);
		m_pChildDlg->ShowWindow(SW_SHOW);
	}
}

LRESULT CPostMessageTestDlg::OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam)
{
	delete m_pChildDlg;
	m_pChildDlg = NULL;
	
	return (LRESULT)0;
}

LRESULT CPostMessageTestDlg::OnUserMessageIntegerNameValue(WPARAM wParam, LPARAM lParam)
{	
	PS_INTEGER temp = (PS_INTEGER)lParam;
	switch(wParam)
	{
	case INTEGER_NAME:
		m_integerName.SetWindowTextW(temp->IntegerName);
		break;	
	case INTEGER_VALUE:
		m_integerValue.SetWindowTextW(temp->IntegerValue);
		break;
	default:
		break;
	}				
	return (LRESULT)0;
}
LRESULT CPostMessageTestDlg::OnUserMessageIntegerName(WPARAM wParam, LPARAM lParam)
{
	CString* tempName = (CString*)lParam;		
	m_integerName.SetWindowTextW(*tempName);
	return (LRESULT)0;
}
LRESULT CPostMessageTestDlg::OnUserMessageIntegerValue(WPARAM wParam, LPARAM lParam)
{	
	CString* tempValue = (CString*)lParam;	
	m_integerValue.SetWindowTextW(*tempValue);					
	return (LRESULT)0;
}

CString CPostMessageTestDlg::SetHV()
{
	return   m_HeightValue;
}
void CPostMessageTestDlg::SetHeightValue(CString value)
{
	m_HeightValue = value;
}
CString CPostMessageTestDlg::SetWV()
{
	return   m_WidthValue;
}
void CPostMessageTestDlg::SetWidthValue(CString value)
{
	m_WidthValue = value;
}
CString CPostMessageTestDlg::SetAV()
{
	return   m_AAAAAValue;
}
void CPostMessageTestDlg::SetAAAAAValue(CString value)
{
	m_AAAAAValue = value;
}
//////////////////////////////////////////
CString CPostMessageTestDlg::SetV(int m_ComboIntegerNameIndex)
{
	switch(m_ComboIntegerNameIndex)
	{
	case 0:
		return   m_HeightValue;
		break;
	case 1:
		return   m_WidthValue;
		break;
	case 2:
		return   m_AAAAAValue;
		break;
	}
}

void CPostMessageTestDlg::SetParam(int index, CString strVal)
{
	switch(index)
	{
	case 0:
		m_HeightValue = strVal;
		break;
	case 1:
		m_WidthValue = strVal;
		break;
	case 2:
		m_AAAAAValue = strVal;
		break;
	default:
		break;
	}
}

CString CPostMessageTestDlg::GetParam(int index)
{
	CString strVal = _T("");

	switch(index)
	{
	case 0:
		strVal = m_HeightValue;
		break;
	case 1:
		strVal = m_WidthValue;
		break;
	case 2:
		strVal = m_AAAAAValue;
		break;
	default:
		break;
	}

	return strVal;
}