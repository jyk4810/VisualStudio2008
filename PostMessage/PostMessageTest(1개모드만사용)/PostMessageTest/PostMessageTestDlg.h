
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

private:
	CChildDlg*		 m_pChildDlg;
	CStatic			 m_integerName;
	CStatic			 m_integerValue;	
	CStatic			 m_floatName;
	CStatic			 m_floatValue;

	int				m_Height;
	int				m_Width;
	int				m_OffsetX;
	int				m_OffsetY;

	float			 m_Exposure;
	float			 m_Time;
	float			 m_Pixel;

public:	
	void			SetParam(int type, CString strName, CString strVal);
	CString			GetParam(int type, CString strName);

	void			SetIntValue(CString strName, CString strVal);
	void			SetFloValue(CString strName, CString strVal);
	CString			GetIntValue(CString strName);
	CString			GetFloValue(CString strName);

};
