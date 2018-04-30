#pragma once

class CModaless_ExerciseDlg;

#define		USER_MESSAGE_DELETE_DIALOG    WM_APP+1

// COneModaless2Dlg 대화 상자입니다.

class COneModaless2Dlg : public CDialog
{
	DECLARE_DYNAMIC(COneModaless2Dlg)

public:
	COneModaless2Dlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COneModaless2Dlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ONEMODALESS2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();

public:
	
	afx_msg void OnClose();

	CModaless_ExerciseDlg* m_pParentDlg;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
