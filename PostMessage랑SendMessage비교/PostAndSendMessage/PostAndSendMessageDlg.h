
// PostAndSendMessageDlg.h : ��� ����
//

#pragma once

#define		USER_MESSAGE_TEST_1    WM_APP+1
#define		USER_MESSAGE_TEST_2    WM_APP+2
#define		USER_MESSAGE_TEST_3    WM_APP+3


// CPostAndSendMessageDlg ��ȭ ����
class CPostAndSendMessageDlg : public CDialog
{
// �����Դϴ�.
public:
	CPostAndSendMessageDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_POSTANDSENDMESSAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
public:
	afx_msg LRESULT OnUserMessageTest1(WPARAM wParam, LPARAM lParam);


protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
