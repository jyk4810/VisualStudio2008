
// ListBoxDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ListBox.h"
#include "ListBoxDlg.h"

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


// CListBoxDlg ��ȭ ����




CListBoxDlg::CListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListBoxDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CListBoxDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CListBoxDlg::OnBnClickedButtonLeft)
	ON_LBN_SETFOCUS(IDC_LIST_RIGHT, &CListBoxDlg::OnLbnSetfocusListRight)
	ON_LBN_SETFOCUS(IDC_LIST_LEFT, &CListBoxDlg::OnLbnSetfocusListLeft)
END_MESSAGE_MAP()


// CListBoxDlg �޽��� ó����

BOOL CListBoxDlg::OnInitDialog()
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

void CListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListBoxDlg::OnPaint()
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
HCURSOR CListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CListBoxDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN && GetDlgItem(IDC_EDIT_ADD) == GetFocus())
	{
		switch(pMsg->wParam)
		{			
		case VK_RETURN:
			{
				CString strTemp = _T("");
				CString strEmpty = _T("");	
				GetDlgItemText(IDC_EDIT_ADD,strTemp);
				SetDlgItemText(IDC_EDIT_ADD,strEmpty);
				((CListBox*)GetDlgItem(IDC_LIST_LEFT))->AddString(strTemp);				
			}
		default:
			break;
		}
	}

	if(pMsg->message == WM_KEYDOWN)			
	{
		switch(pMsg->wParam)
		{			
		case VK_RETURN:			
			
		case VK_ESCAPE:	
			return TRUE;
		case VK_DELETE:
			{				
				if(LB_ERR == ((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->GetCurSel())
				{
					int nIndex = ((CListBox*)GetDlgItem(IDC_LIST_LEFT))->GetCurSel();
					((CListBox*)GetDlgItem(IDC_LIST_LEFT))->DeleteString(nIndex);
				}
				else if(LB_ERR == ((CListBox*)GetDlgItem(IDC_LIST_LEFT))->GetCurSel())
				{
					int nIndex = ((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->GetCurSel();
					((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->DeleteString(nIndex);
				}
				else
					return TRUE;
			}

		default:			
			break;			
		}
	}


	return CDialog::PreTranslateMessage(pMsg);
}

void CListBoxDlg::OnBnClickedButtonRight()
{
	
		if(LB_ERR == ((CListBox*)GetDlgItem(IDC_LIST_LEFT))->GetCurSel())
		{
			AfxMessageBox(_T(" ���ʿ��� ���õ� ����� �����ϴ�. "));
			return;
		}

		int nIndex = ((CListBox*)GetDlgItem(IDC_LIST_LEFT))->GetCurSel();
		
		CString strTemp = _T("");
		((CListBox*)GetDlgItem(IDC_LIST_LEFT))->GetText(nIndex,strTemp);
		((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->AddString(strTemp);
		((CListBox*)GetDlgItem(IDC_LIST_LEFT))->DeleteString(nIndex); // �׸� ����
		
		((CListBox*)GetDlgItem(IDC_LIST_LEFT))->SetCurSel(nIndex); // ������ �ڸ��� SetCurSel.
		int ListCount = ((CListBox*)GetDlgItem(IDC_LIST_LEFT))->GetCount(); // ����Ʈ ����
		
		if( nIndex == ListCount) // �����ϰ� ���� ����Ʈ�� ������� ���� SetCurSel
		{
			((CListBox*)GetDlgItem(IDC_LIST_LEFT))->SetCurSel(nIndex-1); 
		}
}

void CListBoxDlg::OnBnClickedButtonLeft()
{
		if(LB_ERR == ((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->GetCurSel())
		{
			AfxMessageBox(_T(" �����ʿ��� ���õ� ����� �����ϴ�. "));
			return;
		}

		int nIndex = ((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->GetCurSel();
		CString strTemp = _T("");
		((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->GetText(nIndex,strTemp);
		((CListBox*)GetDlgItem(IDC_LIST_LEFT))->AddString(strTemp);
		((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->DeleteString(nIndex); // �ε��� ��ȣ�� �ִ� ��Ʈ�� ����

		((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->SetCurSel(nIndex); // ������ �ڸ��� SetCurSel.
		int ListCount = ((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->GetCount();
		
		if( nIndex == ListCount)
		{
			((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->SetCurSel(nIndex-1);
		}
}

void CListBoxDlg::OnLbnSetfocusListRight()
{
	((CListBox*)GetDlgItem(IDC_LIST_LEFT))->SetCurSel(-1); // ������ ����Ʈ Ŭ���� ���� ����Ʈ Ŀ��(�Ķ�����ŷ) ����
}

void CListBoxDlg::OnLbnSetfocusListLeft()
{	
	((CListBox*)GetDlgItem(IDC_LIST_RIGHT))->SetCurSel(-1);
}
