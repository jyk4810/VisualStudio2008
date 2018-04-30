#pragma once
#include "afxwin.h"

class CPostMessageTestDlg;

#define		USER_MESSAGE_DELETE_DIALOG				WM_APP+1
#define		USER_MESSAGE_INTEGER_NAMEVALUE			WM_APP+2
#define		USER_MESSAGE_INTEGER_NAME				WM_APP+3
#define		USER_MESSAGE_INTEGER_VALUE				WM_APP+4
#define		INTEGER_NAME							0
#define		INTEGER_VALUE							1

#define		MESSAGE_TYPE_MODE						MESSAGE_TYPE_MODE_1
#define		MESSAGE_TYPE_MODE_1						1
#define		MESSAGE_TYPE_MODE_2						2

typedef struct s_Integer
{
	CString IntegerName;
	CString IntegerValue;
}S_INTEGER, *PS_INTEGER;

// CChildDlg 대화 상자입니다.
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
	virtual						BOOL PreTranslateMessage(MSG* pMsg);
	virtual						BOOL OnInitDialog();
	afx_msg void 				OnDestroy();
	afx_msg void 				OnClose();
	afx_msg void OnCbnSelchangeComboIntegername();
	afx_msg void OnEnUpdateEditIntegervalue();

private:
	CPostMessageTestDlg*		m_pParentDlg;
	CString						m_EditIntegerValue;
	CString						m_EditFloatValue;
	CComboBox					m_ComboIntegerName;
	CComboBox					m_ComboFloatName;
	int							m_ComboIntegerNameIndex;
	int							m_ComboFloatNameIndex;
	S_INTEGER					m_sInteger;

public:
	void						SetValue(int index, CString value);	
	void						SettingValue(int m_ComboIntegerNameIndex , CString* pIntVal_edit , CString* pIntVal_struct , CPostMessageTestDlg* m_pParentDlg);
};
