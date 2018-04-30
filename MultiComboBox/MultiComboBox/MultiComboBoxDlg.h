
// MultiComboBoxDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"

class CChildDlg;

// CMultiComboBoxDlg 대화 상자
class CMultiComboBoxDlg : public CDialog
{
// 생성입니다.
public:
	CMultiComboBoxDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MULTICOMBOBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
