
// TryCatchDlg.h : ��� ����
//

#pragma once

#define		RANGE_ERR			              		-1001
#define		TYPE_A1									1
#define		TYPE_A2									2

// CTryCatchDlg ��ȭ ����
class CTryCatchDlg : public CDialog
{
// �����Դϴ�.
public:
	CTryCatchDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_TRYCATCH_DIALOG };

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
	afx_msg void OnEnUpdateEditInteger();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	void		SetIntegerParam(int);
	afx_msg void OnStnClickedStaticA1();
};
