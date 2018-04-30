
// NumeralEditControlDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CNumeralEditControlDlg 대화 상자
class CNumeralEditControlDlg : public CDialog
{
// 생성입니다.
public:
	CNumeralEditControlDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_NUMERALEDITCONTROL_DIALOG };

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
