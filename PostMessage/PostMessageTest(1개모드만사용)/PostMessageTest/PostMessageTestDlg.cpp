
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
	, m_Height(800)
	, m_Width(600)
	, m_OffsetX(0)
	, m_OffsetY(0)
	, m_Exposure(1000.0f)
	, m_Time(0.0f)
	, m_Pixel(100.0f)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pChildDlg		= NULL;
}

void CPostMessageTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_INTEGERNAME, m_integerName);
	DDX_Control(pDX, IDC_STATIC_INTEGERVALUE, m_integerValue);
	DDX_Control(pDX, IDC_STATIC_FLOATNAME, m_floatName);
	DDX_Control(pDX, IDC_STATIC_FLOATVALUE, m_floatValue);
}

BEGIN_MESSAGE_MAP(CPostMessageTestDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP

	ON_BN_CLICKED(IDC_BUTTON_CHILDDIALOG, &CPostMessageTestDlg::OnBnClickedButtonChilddialog)
	ON_MESSAGE(USER_MESSAGE_DELETE_DIALOG, OnUserMessageDeleteDialog)
	ON_MESSAGE(USER_MESSAGE_VALUE, OnUserMessageIntegerNameValue)	
	
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
	m_floatName.SetWindowTextW(_T("Exposure"));
	CString strTemp;
	strTemp.Format(_T("%d"), m_Height);
	m_integerValue.SetWindowTextW(strTemp);
	strTemp.Format(_T("%f"), m_Exposure);
	m_floatValue.SetWindowTextW(strTemp);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPostMessageTestDlg::OnDestroy()
{
	CDialog::OnDestroy();	
	
}


BOOL CPostMessageTestDlg::PreTranslateMessage(MSG* pMsg)
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
	PSTRUCT pStruct = (PSTRUCT)lParam;
	switch(wParam)
	{
	case PARAM_VALUE_INTEGER:
		m_integerName.SetWindowTextW(pStruct->Name);
		m_integerValue.SetWindowTextW(pStruct->Value);
		break;
	case PARAM_VALUE_FLOAT:
		m_floatName.SetWindowTextW(pStruct->Name);
		m_floatValue.SetWindowTextW(pStruct->Value);
		break;
	default:			
		break;	
	}				
	return (LRESULT)0;
}

void CPostMessageTestDlg::SetParam(int type, CString strName, CString strVal)
{
	switch(type)
	{
	case 0:	//int
		SetIntValue(strName, strVal);
		break;
	case 1:	//float
		SetFloValue(strName, strVal);
		break;
	default:
		break;
	}
}

CString CPostMessageTestDlg::GetParam(int type, CString strName)
{
	CString strVal;

	switch(type)
	{
	case 0:	//int
		strVal = GetIntValue(strName);
		break;
	case 1: //float
		strVal = GetFloValue(strName);
		break;
	default:
		break;
	}
	return strVal;
}

void CPostMessageTestDlg::SetIntValue(CString strName, CString strVal)
{
	if(strName == "Height")
	{
		m_Height = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "Width")
	{
		m_Width = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "OffsetX")
	{
		m_OffsetX = _wtoi(strVal.GetBuffer(0));
	}
	else if(strName == "OffsetY")
	{
		m_OffsetY = _wtoi(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CPostMessageTestDlg::GetIntValue(CString strName)
{
	CString strVal;
	int iVal = 0;

	if(strName == "Height")
	{
		iVal = m_Height;
	}
	else if(strName == "Width")
	{
		iVal = m_Width;
	}
	else if(strName == "OffsetX")
	{
		iVal = m_OffsetX;
	}
	else if(strName == "OffsetY")
	{
		iVal = m_OffsetY;
	}
	strVal.Format(_T("%d"), iVal);

	return strVal;
}

void CPostMessageTestDlg::SetFloValue(CString strName, CString strVal)
{
	if(strName == "Exposure")
	{
		m_Exposure = (float)_wtof(strVal.GetBuffer(0));
	}
	else if(strName == "Time")
	{
		m_Time = (float)_wtof(strVal.GetBuffer(0));
	}
	else if(strName == "Pixel")
	{
		m_Pixel = (float)_wtof(strVal.GetBuffer(0));
	}
	else
		return;
}

CString CPostMessageTestDlg::GetFloValue(CString strName)
{
	CString strVal;
	float iVal = 0.0f;

	if(strName == "Exposure")
	{
		iVal = m_Exposure;
	}
	else if(strName == "Time")
	{
		iVal = m_Time;
	}
	else if(strName == "Pixel")
	{
		iVal = m_Pixel;
	}
	strVal.Format(_T("%f"), iVal);

	return strVal;
}