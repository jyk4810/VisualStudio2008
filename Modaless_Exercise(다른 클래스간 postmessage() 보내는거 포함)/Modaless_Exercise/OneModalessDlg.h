#pragma once


// COneModalessDlg ��ȭ �����Դϴ�.

class CModaless_ExerciseDlg;

class COneModalessDlg : public CDialog
{
	DECLARE_DYNAMIC(COneModalessDlg)

public:
	COneModalessDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COneModalessDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ONEMODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnClose();

	CModaless_ExerciseDlg* m_pParentDlg;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
