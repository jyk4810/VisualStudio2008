
// PostMessageTestDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "PostMessageTest.h"
#include "PostMessageTestDlg.h"
#include "ChildDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CPostMessageTestDlg 대화 상자

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
// CPostMessageTestDlg 메시지 처리기

BOOL CPostMessageTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_integerName.SetWindowTextW(_T("Height"));
	m_integerValue.SetWindowTextW(m_HeightValue);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPostMessageTestDlg::OnDestroy()
{
	CDialog::OnDestroy();	
	
}


BOOL CPostMessageTestDlg::PreTranslateMessage(MSG* pMsg)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPostMessageTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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