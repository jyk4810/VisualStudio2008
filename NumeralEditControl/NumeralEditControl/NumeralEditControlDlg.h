
// NumeralEditControlDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CNumeralEditControlDlg ��ȭ ����
class CNumeralEditControlDlg : public CDialog
{
// �����Դϴ�.
public:
	CNumeralEditControlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NUMERALEDITCONTROL_DIALOG };

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

	afx_msg void OnEnChangeEditNumeral();
	afx_msg void OnEnUpdateEditNumeral();	

	wchar_t* m_pwcharStr;
	char* m_pcharStr;
	int m_strlen;
	int m_Pointnumber;

	CEdit m_EditNumeralCtrl;
	CString m_OldEditNumeralContext;
	CString m_EditNumeralContext;

};
