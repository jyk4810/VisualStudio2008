#pragma once


// CModalessDlg ��ȭ �����Դϴ�.

class CModalessDlg : public CDialog //CHILD ���̾�α�
{
	DECLARE_DYNAMIC(CModalessDlg)

public:
	CModalessDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CModalessDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MODALESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();

public:

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnClose();

	
	afx_msg void OnDestroy();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
