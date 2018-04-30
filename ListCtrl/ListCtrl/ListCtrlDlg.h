
// ListCtrlDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CListCtrlDlg ��ȭ ����
class CListCtrlDlg : public CDialog
{
// �����Դϴ�.
public:
	CListCtrlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LISTCTRL_DIALOG };

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
	afx_msg void OnBnClickedRadioAll();
	afx_msg void OnBnClickedRadioInt();
	afx_msg void OnBnClickedRadioFloat();
	afx_msg void OnBnClickedRadioEnum();
	afx_msg void OnBnClickedRadioCom();
	afx_msg void OnBnClickedRadioStr();
	afx_msg void OnBnClickedRadioBool();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	CImageList* m_pImageList;

protected:
	virtual void OnCancel();
public:
	afx_msg void OnDestroy();
	afx_msg void OnClose();
};
