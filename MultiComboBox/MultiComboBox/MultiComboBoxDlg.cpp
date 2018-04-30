
// MultiComboBoxDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MultiComboBox.h"
#include "MultiComboBoxDlg.h"
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


// CMultiComboBoxDlg 대화 상자




CMultiComboBoxDlg::CMultiComboBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMultiComboBoxDlg::IDD, pParent)
	, m_ComboParentIndex(0)
	, m_ComboChildIndex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pChildDlg = NULL;
	m_ValNumber = 0;
}

void CMultiComboBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PARENT, m_ComboParent);
	DDX_Control(pDX, IDC_COMBO_CHILD, m_ComboChild);
	DDX_CBIndex(pDX, IDC_COMBO_PARENT, m_ComboParentIndex);
	DDX_CBIndex(pDX, IDC_COMBO_CHILD, m_ComboChildIndex);
}

BEGIN_MESSAGE_MAP(CMultiComboBoxDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_CHILDDIALOG, &CMultiComboBoxDlg::OnBnClickedButtonChilddialog)
	ON_MESSAGE(USER_MESSAGE_DELETE_DIALOG, OnUserMessageDeleteDialog)
END_MESSAGE_MAP()


// CMultiComboBoxDlg 메시지 처리기

BOOL CMultiComboBoxDlg::OnInitDialog()
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
	

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMultiComboBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMultiComboBoxDlg::OnPaint()
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
HCURSOR CMultiComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CMultiComboBoxDlg::PreTranslateMessage(MSG* pMsg)
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


void CMultiComboBoxDlg::OnBnClickedButtonChilddialog()
{
	if( m_pChildDlg == NULL )
	{
		m_pChildDlg = new CChildDlg(this);
		m_pChildDlg->Create(IDD_DIALOG_CHILDDIALOG);
		m_pChildDlg->ShowWindow(SW_SHOW);
	}
}

LRESULT CMultiComboBoxDlg::OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam)
{
	delete m_pChildDlg;
	m_pChildDlg = NULL;
	
	return (LRESULT)0;
}
//
//void CMultiComboBoxDlg::GetVal(int iVal)
//{
//	
//	m_ValNumber = iVal;
//	
//}

int CMultiComboBoxDlg::GetEnumCount(int index, int* pCount)
{
	int count = 0;
	switch(index)
	{
	case 0:
		count = 3;
		break;
	case 1:
		count = 4;
		break;
	case 2:
		count = 5;
		break;
	default:
		break;
	}

	*pCount = count;

	return 0;
}


int CMultiComboBoxDlg::GetEnumEntry(int index, int enumidx, CString* enumEntry)
{
	int count = 0;
	switch(index)
	{
	case 0:
		{
			switch(enumidx)
			{
			case 0:
				*enumEntry = _T("A1");
				break;
			case 1:
				*enumEntry = _T("B1");
				break;
			case 2:
				*enumEntry = _T("C1");
				break;
			}
		}		
		break;
	case 1:
		{
			switch(enumidx)
			{
			case 0:
				*enumEntry = _T("A2");
				break;
			case 1:
				*enumEntry = _T("B2");
				break;
			case 2:
				*enumEntry = _T("C2");
				break;
			case 3:
				*enumEntry = _T("D2");
				break;
			}
		}			
		break;
	case 2:
		{
			switch(enumidx)
			{
			case 0:
				*enumEntry = _T("A3");
				break;
			case 1:
				*enumEntry = _T("B3");
				break;
			case 2:
				*enumEntry = _T("C3");
				break;
			case 3:
				*enumEntry = _T("D3");
				break;
			case 4:
				*enumEntry = _T("E3");
				break;
			}
		}	
		
		break;
	default:
		break;
	}	

	return 0;
}

int CMultiComboBoxDlg::GetEnumEntryIntValue(int index, int* intValue)
{
	int count = 0;
	switch(index)
	{
	case 0:
		count = 0;
		break;
	case 1:
		count = 1;
		break;
	case 2:
		count = 2;
		break;
	default:
		break;
	}

	*intValue = count;


	return 0;
}
