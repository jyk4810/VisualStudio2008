
// Modaless_ExerciseDlg.h : ��� ����
//

#pragma once
class COneModalessDlg;
class COneModaless2Dlg;


// CModaless_ExerciseDlg ��ȭ ����
class CModaless_ExerciseDlg : public CDialog //MAIN ���̾�α�
{
// �����Դϴ�.
public:
	CModaless_ExerciseDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MODALESS_EXERCISE_DIALOG };

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
