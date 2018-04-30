
// ListCtrlDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ListCtrl.h"
#include "ListCtrlDlg.h"

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


// CListCtrlDlg 대화 상자




CListCtrlDlg::CListCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListCtrlDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_RADIO_ALL, &CListCtrlDlg::OnBnClickedRadioAll)
	ON_BN_CLICKED(IDC_RADIO_INT, &CListCtrlDlg::OnBnClickedRadioInt)
	ON_BN_CLICKED(IDC_RADIO_FLOAT, &CListCtrlDlg::OnBnClickedRadioFloat)
	ON_BN_CLICKED(IDC_RADIO_ENUM, &CListCtrlDlg::OnBnClickedRadioEnum)
	ON_BN_CLICKED(IDC_RADIO_COM, &CListCtrlDlg::OnBnClickedRadioCom)
	ON_BN_CLICKED(IDC_RADIO_STR, &CListCtrlDlg::OnBnClickedRadioStr)
	ON_BN_CLICKED(IDC_RADIO_BOOL, &CListCtrlDlg::OnBnClickedRadioBool)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CListCtrlDlg 메시지 처리기

BOOL CListCtrlDlg::OnInitDialog()
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

	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(0, _T("FeatureName"), LVCFMT_LEFT, 140, -1);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(1, _T("Value"), LVCFMT_CENTER, 109, -1);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(2, _T("Type"), LVCFMT_CENTER, 109, -1);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListCtrlDlg::OnPaint()
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
HCURSOR CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListCtrlDlg::OnBnClickedRadioAll()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems(); // 리스트 초기화 (버튼이 두번눌릴때 추가 ADDSTRING방지)

	//INT
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("Width"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("Height"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("WidthMax"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );

	//FLOAT
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(3, _T("TriggerDelay"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(4, _T("ExposureTime"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(5, _T("AcquisitionFrameRate"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(3,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(4,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(5,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(3,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(4,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(5,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );

	//ENUM
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(6, _T("DeviceScanType"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(7, _T("PixelFormat"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(8, _T("TestPattern"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(6,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(7,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(8,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(6,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(7,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(8,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );

	//COM
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(9, _T("AcquisitionStart"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(10, _T("AcquisitionStop"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(11, _T("TriggerSoftware"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(9,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(10,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(11,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(9,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(10,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(11,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );

	//STR
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(12, _T("DeviceID"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(13, _T("DeviceVendorName"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(14, _T("DeviceModelName"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(12,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(13,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(14,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(12,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(13,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(14,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );

	//BOOL
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(15, _T("LineInverter"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(16, _T("LineStatus"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(17, _T("UserOutputValue"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(15,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(16,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(17,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(15,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(16,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(17,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );

}

void CListCtrlDlg::OnBnClickedRadioInt()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("Width"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("Height"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("WidthMax"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("INT"), 0, 0, 0, NULL );
}

void CListCtrlDlg::OnBnClickedRadioFloat()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("TriggerDelay"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("ExposureTime"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("AcquisitionFrameRate"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("FLOAT"), 0, 0, 0, NULL );
}

void CListCtrlDlg::OnBnClickedRadioEnum()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("DeviceScanType"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("PixelFormat"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("TestPattern"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("ENUM"), 0, 0, 0, NULL );
}

void CListCtrlDlg::OnBnClickedRadioCom()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("AcquisitionStart"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("AcquisitionStop"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("TriggerSoftware"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("COM"), 0, 0, 0, NULL );
}

void CListCtrlDlg::OnBnClickedRadioStr()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("DeviceID"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("DeviceVendorName"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("DeviceModelName"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("STR"), 0, 0, 0, NULL );
}

void CListCtrlDlg::OnBnClickedRadioBool()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(0, _T("LineInverter"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(1, _T("LineStatus"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertItem(2, _T("UserOutputValue"));
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,1,LVIF_TEXT, _T("600"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,1,LVIF_TEXT, _T("800"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(0,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(1,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
	((CListCtrl*)GetDlgItem(IDC_LIST))->SetItem(2,2,LVIF_TEXT, _T("BOOL"), 0, 0, 0, NULL );
}

BOOL CListCtrlDlg::PreTranslateMessage(MSG* pMsg)
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

void CListCtrlDlg::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	CDialog::OnCancel();
}

void CListCtrlDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

void CListCtrlDlg::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CDialog::OnClose();
}
