
// Modaless_ExerciseDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Modaless_Exercise.h"
#include "Modaless_ExerciseDlg.h"
#include "ModalessDlg.h"
#include "OneModalessDlg.h"
#include "OneModaless2Dlg.h"

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


// CModaless_ExerciseDlg ��ȭ ����




CModaless_ExerciseDlg::CModaless_ExerciseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModaless_ExerciseDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pOneModalessDlg = NULL;
	m_pOneModaless2Dlg = NULL;
	m_bIsCreatedOneModalessDlg = FALSE;
	
}

void CModaless_ExerciseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CModaless_ExerciseDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(USER_MESSAGE_DELETE_DIALOG, OnUserMessageDeleteDialog)

	ON_BN_CLICKED(IDC_BUTTON_MODALESS, &CModaless_ExerciseDlg::OnBnClickedButtonModaless)
	ON_BN_CLICKED(IDC_BUTTON_ONEMODALESS, &CModaless_ExerciseDlg::OnBnClickedButtonOnemodaless)
	ON_BN_CLICKED(IDC_BUTTON_ONEMODALESS2, &CModaless_ExerciseDlg::OnBnClickedButtonOnemodaless2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CModaless_ExerciseDlg �޽��� ó����

BOOL CModaless_ExerciseDlg::OnInitDialog()
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



void CModaless_ExerciseDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}



void CModaless_ExerciseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CModaless_ExerciseDlg::OnPaint()
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
HCURSOR CModaless_ExerciseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CModaless_ExerciseDlg::OnBnClickedButtonModaless()
{	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CModalessDlg* pModalessDlg1 = new CModalessDlg();
	pModalessDlg1->Create(IDD_DIALOG_MODALESS);
	pModalessDlg1->ShowWindow(SW_SHOW);

}

void CModaless_ExerciseDlg::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	
	CDialog::PostNcDestroy();
}



void CModaless_ExerciseDlg::OnBnClickedButtonOnemodaless()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if( m_bIsCreatedOneModalessDlg == FALSE )
	{
		m_pOneModalessDlg = new COneModalessDlg(this);
		m_pOneModalessDlg->Create(IDD_DIALOG_ONEMODALESS);
		m_pOneModalessDlg->ShowWindow(SW_SHOW);
		m_bIsCreatedOneModalessDlg = TRUE;
	}
}

void CModaless_ExerciseDlg::OnBnClickedButtonOnemodaless2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if( m_pOneModaless2Dlg == NULL )
	{
		m_pOneModaless2Dlg = new COneModaless2Dlg(this);
		m_pOneModaless2Dlg->Create(IDD_DIALOG_ONEMODALESS2);
		m_pOneModaless2Dlg->ShowWindow(SW_SHOW);
	}
}


LRESULT CModaless_ExerciseDlg::OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam)
{
	delete m_pOneModaless2Dlg;
	m_pOneModaless2Dlg = NULL;
	return (LRESULT)0;

}