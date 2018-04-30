
// ListCtrlImgDlg.h : 헤더 파일
//

#pragma once

#define IMAGE_INT		0
#define IMAGE_FLOAT		1
#define IMAGE_ENUM		2
#define IMAGE_COM		3
#define IMAGE_STR		4
#define IMAGE_BOOL		5

// CListCtrlImgDlg 대화 상자
class CListCtrlImgDlg : public CDialog
{
// 생성입니다.
public:
	CListCtrlImgDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LISTCTRLIMG_DIALOG };

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
	afx_msg void OnBnClickedRadioAll();

private:
	CImageList* m_pImageList;
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedRadioInt();
	afx_msg void OnBnClickedRadioFloat();
	afx_msg void OnBnClickedRadioEnum();
	afx_msg void OnBnClickedRadioCom();
	afx_msg void OnBnClickedRadioStr();
	afx_msg void OnBnClickedRadioBool();
};
