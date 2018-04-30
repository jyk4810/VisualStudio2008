
// OnPaintDlg.h : ��� ����
//

#pragma once

#define MAX_CLICK_COUNT 100

struct ClickInformation
{
 int flag;
 int x;
 int y;
};

// COnPaintDlg ��ȭ ����
class COnPaintDlg : public CDialog
{
// �����Դϴ�.
public:
	COnPaintDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ONPAINT_DIALOG };

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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	HDC* pdc;
	HDC dccc;

private:
	ClickInformation m_pos_list[MAX_CLICK_COUNT];
	int m_click_count;
};
