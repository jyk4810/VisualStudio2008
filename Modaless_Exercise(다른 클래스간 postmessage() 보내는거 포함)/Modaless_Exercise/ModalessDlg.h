#pragma once


// CModalessDlg 대화 상자입니다.

class CModalessDlg : public CDialog //CHILD 다이얼로그
{
	DECLARE_DYNAMIC(CModalessDlg)

public:
	CModalessDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CModalessDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_MODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();

public:

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnClose();

	
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
