#pragma once


// COneModalessDlg 대화 상자입니다.

class CModaless_ExerciseDlg;

class COneModalessDlg : public CDialog
{
	DECLARE_DYNAMIC(COneModalessDlg)

public:
	COneModalessDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COneModalessDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ONEMODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnClose();

	CModaless_ExerciseDlg* m_pParentDlg;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
