
// TryCatchDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TryCatch.h"
#include "TryCatchDlg.h"

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


// CTryCatchDlg ��ȭ ����




CTryCatchDlg::CTryCatchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTryCatchDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTryCatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTryCatchDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_STN_CLICKED(IDC_STATIC_A1, &CTryCatchDlg::OnStnClickedStaticA1)
END_MESSAGE_MAP()


// CTryCatchDlg �޽��� ó����

BOOL CTryCatchDlg::OnInitDialog()
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

void CTryCatchDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTryCatchDlg::OnPaint()
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
HCURSOR CTryCatchDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTryCatchDlg::OnEnUpdateEditInteger()
{


}

BOOL CTryCatchDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->message == WM_KEYDOWN && GetDlgItem(IDC_EDIT_A1) == GetFocus())			
	{
		switch(pMsg->wParam)			
		{			
		case VK_RETURN:
			{
				SetIntegerParam(TYPE_A1);
			}
		default:
			break;
		}
	}
	else if(pMsg->message == WM_KEYDOWN && GetDlgItem(IDC_EDIT_A2) == GetFocus())			
	{
		switch(pMsg->wParam)			
		{			
		case VK_RETURN:
			{
				SetIntegerParam(TYPE_A2);
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
		default:			
			break;			
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CTryCatchDlg::SetIntegerParam( int type )
{	
	switch(type)
	{
	case TYPE_A1:
		{
			try // Ʈ����
			{
				int value = GetDlgItemInt(IDC_EDIT_A1);
			
				if( value>=10 )
				{
					int b = 0;
					throw(b);
				}
			}
			
			catch(int e) // throw�� int�� ������ catch
			{
				e = e;
			}
			catch(CString strE)	//throw�� CString�� ������ catch
			{
				strE = strE;
			}
			catch(...) // �� ��(default) catch
			{
				CString strTemp = _T("");
				char cc[10] = {0,};
				(CStatic*)GetDlgItem(IDC_STATIC_A1)->GetWindowText((LPTSTR)cc,3);
				strTemp = (LPCTSTR)cc;
				CString strMessage = _T("");
				strMessage.Format( _T(" %s ���� %d ���� �߻� "), strTemp , RANGE_ERR);
				AfxMessageBox(strMessage);
			}
		}
		break;
	case TYPE_A2:
		{
			try
			{
				int value = GetDlgItemInt(IDC_EDIT_A2);

				if( value>=10 )
				{
					int b = 0;
					throw(b);
				}
			}
			catch(...) //default ���� ĳġ
			{
				CString strTemp = _T("");
				char cc[10] = {0,};
				(CStatic*)GetDlgItem(IDC_STATIC_A2)->GetWindowText((LPTSTR)cc,3);
				strTemp = (LPCTSTR)cc;
				CString strMessage = _T("");
				strMessage.Format( _T(" %s ���� %d ���� �߻� "), strTemp , RANGE_ERR);
				AfxMessageBox(strMessage);
			}
		}
		break;
	default:
		break;

	}
		
	
}
void CTryCatchDlg::OnStnClickedStaticA1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
