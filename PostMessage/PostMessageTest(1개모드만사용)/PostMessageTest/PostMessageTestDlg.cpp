
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
	m_floatName.SetWindowTextW(_T("Exposure"));
	CString strTemp;
	strTemp.Format(_T("%d"), m_Height);
	m_integerValue.SetWindowTextW(strTemp);
	strTemp.Format(_T("%f"), m_Exposure);
	m_floatValue.SetWindowTextW(strTemp);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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