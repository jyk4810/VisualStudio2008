
// Modaless_ExerciseDlg.h : 헤더 파일
//

#pragma once
class COneModalessDlg;
class COneModaless2Dlg;


// CModaless_ExerciseDlg 대화 상자
class CModaless_ExerciseDlg : public CDialog //MAIN 다이얼로그
{
// 생성입니다.
public:
	CModaless_ExerciseDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MODALESS_EXERCISE_DIALOG };

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
	afx_msg void OnBnClickedButtonModaless();
	afx_msg void OnBnClickedButtonOnemodaless();
	afx_msg LRESULT OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam);


protected:
	virtual void PostNcDestroy();

public:
	COneModalessDlg* m_pOneModalessDlg;
	COneModaless2Dlg* m_pOneModaless2Dlg;
	BOOL m_bIsCreatedOneModalessDlg;
	
	

	afx_msg void OnBnClickedButtonOnemodaless2();
	afx_msg void OnDestroy();
};
