
// PostAndSendMessageDlg.h : 헤더 파일
//

#pragma once

#define		USER_MESSAGE_TEST_1    WM_APP+1
#define		USER_MESSAGE_TEST_2    WM_APP+2
#define		USER_MESSAGE_TEST_3    WM_APP+3


// CPostAndSendMessageDlg 대화 상자
class CPostAndSendMessageDlg : public CDialog
{
// 생성입니다.
public:
	CPostAndSendMessageDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_POSTANDSENDMESSAGE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
public:
	afx_msg LRESULT OnUserMessageTest1(WPARAM wParam, LPARAM lParam);


protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
