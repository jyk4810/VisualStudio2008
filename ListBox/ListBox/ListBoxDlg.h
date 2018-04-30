
// ListBoxDlg.h : ��� ����
//

#pragma once


// CListBoxDlg ��ȭ ����
class CListBoxDlg : public CDialog
{
// �����Դϴ�.
public:
	CListBoxDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LISTBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonLeft();
	afx_msg void OnLbnSetfocusListRight();
	afx_msg void OnLbnSetfocusListLeft();
};
