
// PostMessageTestDlg.h : 헤더 파일

#pragma once
#include "afxwin.h"

class CChildDlg;

// CPostMessageTestDlg 대화 상자
class CPostMessageTestDlg : public CDialog
{
// 생성입니다.
public:
	CPostMessageTestDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_POSTMESSAGETEST_DIALOG };

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
