
// ListCtrlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ListCtrl.h"
#include "ListCtrlDlg.h"

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


// CListCtrlDlg ��ȭ ����




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


// CListCtrlDlg �޽��� ó����

BOOL CListCtrlDlg::OnInitDialog()
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

	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems();
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(0, _T("FeatureName"), LVCFMT_LEFT, 140, -1);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(1, _T("Value"), LVCFMT_CENTER, 109, -1);
	((CListCtrl*)GetDlgItem(IDC_LIST))->InsertColumn(2, _T("Type"), LVCFMT_CENTER, 109, -1);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CListCtrlDlg::OnPaint()
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
HCURSOR CListCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CListCtrlDlg::OnBnClickedRadioAll()
{
	((CListCtrl*)GetDlgItem(IDC_LIST))->DeleteAllItems(); // ����Ʈ �ʱ�ȭ (��ư�� �ι������� �߰� ADDSTRING����)

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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	CDialog::OnCancel();
}

void CListCtrlDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}

void CListCtrlDlg::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	CDialog::OnClose();
}
