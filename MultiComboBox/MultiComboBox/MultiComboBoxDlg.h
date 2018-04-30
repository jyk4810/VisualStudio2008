
// MultiComboBoxDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"

class CChildDlg;

// CMultiComboBoxDlg ��ȭ ����
class CMultiComboBoxDlg : public CDialog
{
// �����Դϴ�.
public:
	CMultiComboBoxDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MULTICOMBOBOX_DIALOG };

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
	CComboBox m_ComboParent;
	CComboBox m_ComboChild;

	
	afx_msg LRESULT OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam);
	
	
	int m_ComboParentIndex;
	int m_ComboChildIndex;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	

private:
	CChildDlg* m_pChildDlg;
	int			m_ValNumber;

public:
	//void	 GetVal(int);
	int		GetEnumCount(int index, int* pCount);
	int		GetEnumEntry(int index, int enumidx, CString* enumEntry);
	int		GetEnumEntryIntValue(int index, int* intValue);


public:
	afx_msg void OnBnClickedButtonChilddialog();

	
};
