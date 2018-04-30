#pragma once


// CChildDlg 대화 상자입니다.
class CMultiComboBoxDlg;
#define		USER_MESSAGE_DELETE_DIALOG				WM_APP+1

class CChildDlg : public CDialog
{
	DECLARE_DYNAMIC(CChildDlg)

public:
	CChildDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CChildDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CHILDDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnDestroy();

private:
	CMultiComboBoxDlg* m_pParentDlg;

	void	SetEnumEntry();

public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboNumber();
};
