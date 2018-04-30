
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
