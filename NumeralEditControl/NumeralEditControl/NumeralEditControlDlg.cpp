
// NumeralEditControlDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "NumeralEditControl.h"
#include "NumeralEditControlDlg.h"

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


// CNumeralEditControlDlg 대화 상자




CNumeralEditControlDlg::CNumeralEditControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNumeralEditControlDlg::IDD, pParent)
	, m_EditNumeralContext(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNumeralEditControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_NUMERAL, m_EditNumeralContext);
	DDX_Control(pDX, IDC_EDIT_NUMERAL, m_EditNumeralCtrl);
}

BEGIN_MESSAGE_MAP(CNumeralEditControlDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT_NUMERAL, &CNumeralEditControlDlg::OnEnChangeEditNumeral)
	ON_EN_UPDATE(IDC_EDIT_NUMERAL, &CNumeralEditControlDlg::OnEnUpdateEditNumeral)
END_MESSAGE_MAP()
// CNumeralEditControlDlg 메시지 처리기


BOOL CNumeralEditControlDlg::OnInitDialog()
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
	m_pwcharStr = NULL;
	m_pcharStr = NULL;
	m_strlen = 0;
	m_Pointnumber=0;
	m_OldEditNumeralContext = _T("");


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CNumeralEditControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNumeralEditControlDlg::OnPaint()
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
HCURSOR CNumeralEditControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNumeralEditControlDlg::OnEnChangeEditNumeral()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nSelStart = 0;
	int nSelEnd   = 0;
    
	m_EditNumeralCtrl.GetSel(nSelStart,nSelEnd); // 현재 커서 위치를 nSelStart 변수에 저장

	UpdateData(true); // Edit Control 내용을 컨트롤 변수에 저장
	
	
	
	TCHAR* tchr = NULL;
	CString cstr = _T("");
	cstr = m_EditNumeralContext.Mid(nSelStart-1,1); //현재 커서 위치에 적은 문자를 cstr에 저장
	tchr = (TCHAR*)(LPCTSTR)cstr; //CString to Tchar*

	if( *tchr  == 46 ) // 점이 두번 입력되면 두번째 입력된 점 삭제
	{	
		m_Pointnumber++;
		if ( m_Pointnumber == 2 )
		{	
			m_Pointnumber = m_Pointnumber-1;
			m_EditNumeralContext = m_OldEditNumeralContext; // Original에 Old 사용
			UpdateData(false);
			m_EditNumeralCtrl.SetSel(nSelStart-1,nSelStart-1); // 현재 커서로 이동
		}
	}
	
	if( !( *tchr >= 48 && *tchr  <= 57 || *tchr  == 46 ) ) // 입력 문자 식별 (숫자와 점만 허용)
	{	
		m_EditNumeralContext.Remove(*tchr);	
		UpdateData(false);
		m_EditNumeralCtrl.SetSel(nSelStart-1,nSelStart-1);
	}	
	m_OldEditNumeralContext = m_EditNumeralContext; // Old에 Original 저장
	
	char temp[100] ={0,};
	
	m_pwcharStr = m_EditNumeralContext.GetBuffer(0);
	m_strlen = WideCharToMultiByte(CP_ACP, 0, m_pwcharStr, -1, NULL, 0, NULL, NULL);
	m_pcharStr = new char[m_strlen];
	WideCharToMultiByte(CP_ACP, 0, m_pwcharStr, -1, m_pcharStr, m_strlen, 0,0);
	strcpy_s(temp, m_pcharStr);
	delete m_pcharStr;

	int count = strlen(temp);
	int pointNumber_Num = 0;
    
	for( int i = 0; i < count; i++ )
	{
         if((temp[i] == 46))
		 {
			  pointNumber_Num++;
		 }
    }
	if ( pointNumber_Num ==0 )
		m_Pointnumber =  0;
}

void CNumeralEditControlDlg::OnEnUpdateEditNumeral()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하여, IParam 마스크에 OR 연산하여 설정된 ENM_SCROLL 플래그를 지정하여 컨트롤에 EM_SETEVENTMASK 메시지를 보내지 않으면
	// 편집 컨트롤이 바뀐 텍스트를 표시하려고 함을 나타냅니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.



}

BOOL CNumeralEditControlDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if(pMsg->message == WM_KEYDOWN) 			
	{			
		switch(pMsg->wParam)			
		{			
		case VK_RETURN:			
		case VK_ESCAPE:			
			return TRUE;
		case VK_BACK: // 백스페이스 눌렀을때 커서 2번째 앞에 .이 있을경우 m_Pointnumber를 0으로 해줌으로써 버그 해결
			{
				int nSelStart = 0;
				int nSelEnd = 0;
				m_EditNumeralCtrl.GetSel(nSelStart,nSelEnd);
				if(m_EditNumeralContext.Mid(nSelStart-2,1) == _T("."))
				{
					m_Pointnumber =  0;
				}
			}
			
		default:			
			break;			
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
