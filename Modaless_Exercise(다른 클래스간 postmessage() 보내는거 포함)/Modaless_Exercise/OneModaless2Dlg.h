#pragma once

class CModaless_ExerciseDlg;

#define		USER_MESSAGE_DELETE_DIALOG    WM_APP+1

// COneModaless2Dlg ��ȭ �����Դϴ�.

class COneModaless2Dlg : public CDialog
{
	DECLARE_DYNAMIC(COneModaless2Dlg)

public:
	COneModaless2Dlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COneModaless2Dlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ONEMODALESS2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();

public:
	
	afx_msg void OnClose();

	CModaless_ExerciseDlg* m_pParentDlg;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
