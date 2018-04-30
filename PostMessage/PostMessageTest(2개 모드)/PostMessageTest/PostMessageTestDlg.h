
// PostMessageTestDlg.h : ��� ����

#pragma once
#include "afxwin.h"

class CChildDlg;

// CPostMessageTestDlg ��ȭ ����
class CPostMessageTestDlg : public CDialog
{
// �����Դϴ�.
public:
	CPostMessageTestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_POSTMESSAGETEST_DIALOG };

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
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonChilddialog();
	afx_msg LRESULT OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserMessageIntegerNameValue(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserMessageIntegerName(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserMessageIntegerValue(WPARAM wParam, LPARAM lParam);

private:
	CChildDlg*		 m_pChildDlg;
	CStatic			 m_integerName;
	CStatic			 m_integerValue;
	CString			 m_HeightValue;
	CString			 m_WidthValue;
	CString			 m_AAAAAValue;

public:	
	CString			 SetHV();
	CString			 SetWV();
	CString			 SetAV();
	CString			 SetV(int);
	void			 SetHeightValue(CString);
	void			 SetWidthValue(CString);
	void			 SetAAAAAValue(CString);


	void			SetParam(int index, CString strVal);
	CString			GetParam(int index);

};
