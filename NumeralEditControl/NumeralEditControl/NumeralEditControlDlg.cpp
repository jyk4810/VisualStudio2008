
// NumeralEditControlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "NumeralEditControl.h"
#include "NumeralEditControlDlg.h"

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


// CNumeralEditControlDlg ��ȭ ����




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
// CNumeralEditControlDlg �޽��� ó����


BOOL CNumeralEditControlDlg::OnInitDialog()
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
	m_pwcharStr = NULL;
	m_pcharStr = NULL;
	m_strlen = 0;
	m_Pointnumber=0;
	m_OldEditNumeralContext = _T("");


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CNumeralEditControlDlg::OnPaint()
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
HCURSOR CNumeralEditControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNumeralEditControlDlg::OnEnChangeEditNumeral()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nSelStart = 0;
	int nSelEnd   = 0;
    
	m_EditNumeralCtrl.GetSel(nSelStart,nSelEnd); // ���� Ŀ�� ��ġ�� nSelStart ������ ����

	UpdateData(true); // Edit Control ������ ��Ʈ�� ������ ����
	
	
	
	TCHAR* tchr = NULL;
	CString cstr = _T("");
	cstr = m_EditNumeralContext.Mid(nSelStart-1,1); //���� Ŀ�� ��ġ�� ���� ���ڸ� cstr�� ����
	tchr = (TCHAR*)(LPCTSTR)cstr; //CString to Tchar*

	if( *tchr  == 46 ) // ���� �ι� �ԷµǸ� �ι�° �Էµ� �� ����
	{	
		m_Pointnumber++;
		if ( m_Pointnumber == 2 )
		{	
			m_Pointnumber = m_Pointnumber-1;
			m_EditNumeralContext = m_OldEditNumeralContext; // Original�� Old ���
			UpdateData(false);
			m_EditNumeralCtrl.SetSel(nSelStart-1,nSelStart-1); // ���� Ŀ���� �̵�
		}
	}
	
	if( !( *tchr >= 48 && *tchr  <= 57 || *tchr  == 46 ) ) // �Է� ���� �ĺ� (���ڿ� ���� ���)
	{	
		m_EditNumeralContext.Remove(*tchr);	
		UpdateData(false);
		m_EditNumeralCtrl.SetSel(nSelStart-1,nSelStart-1);
	}	
	m_OldEditNumeralContext = m_EditNumeralContext; // Old�� Original ����
	
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
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�Ͽ�, IParam ����ũ�� OR �����Ͽ� ������ ENM_SCROLL �÷��׸� �����Ͽ� ��Ʈ�ѿ� EM_SETEVENTMASK �޽����� ������ ������
	// ���� ��Ʈ���� �ٲ� �ؽ�Ʈ�� ǥ���Ϸ��� ���� ��Ÿ���ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.



}

BOOL CNumeralEditControlDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if(pMsg->message == WM_KEYDOWN) 			
	{			
		switch(pMsg->wParam)			
		{			
		case VK_RETURN:			
		case VK_ESCAPE:			
			return TRUE;
		case VK_BACK: // �齺���̽� �������� Ŀ�� 2��° �տ� .�� ������� m_Pointnumber�� 0���� �������ν� ���� �ذ�
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
