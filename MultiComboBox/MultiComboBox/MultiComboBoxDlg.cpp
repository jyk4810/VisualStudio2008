
// MultiComboBoxDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MultiComboBox.h"
#include "MultiComboBoxDlg.h"
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


// CMultiComboBoxDlg ��ȭ ����




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


// CMultiComboBoxDlg �޽��� ó����

BOOL CMultiComboBoxDlg::OnInitDialog()
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
	

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMultiComboBoxDlg::OnPaint()
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
HCURSOR CMultiComboBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CMultiComboBoxDlg::PreTranslateMessage(MSG* pMsg)
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
