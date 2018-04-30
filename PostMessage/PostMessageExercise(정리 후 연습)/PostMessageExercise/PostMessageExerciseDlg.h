
// PostMessageExerciseDlg.h : ��� ����
//

#pragma once

class CChildDlg;

// CPostMessageExerciseDlg ��ȭ ����
class CPostMessageExerciseDlg : public CDialog
{
// �����Դϴ�.
public:
	CPostMessageExerciseDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_POSTMESSAGEEXERCISE_DIALOG };

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
	afx_msg LRESULT OnUserMessageDeleteDialog(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUserMessageIntegerNameValue(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChilddialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

private:
	CChildDlg*		 m_pChildDlg;

	int				m_Height;
	int				m_Width;
	int				m_OffsetX;
	int				m_OffsetY;

	float			m_TriggerDelay;
	float			m_ExposureTime;
	float			m_AcquisitionFrameRate;
	float			m_TimerDuration;

	int				m_DeviceScanType;
	int				m_PixelFormat;
	int				m_TestPattern;
	int				m_AcquisitionMode;

	int				m_AcquisitionStart;
	int				m_AcquisitionStop;
	int				m_TriggerSoftware;
	int				m_GevTimestampControlLatch;

	int				m_DeviceID;
	int				m_DeviceVendorName;
	int				m_DeviceModelName;
	int				m_DeviceManufacturerInfo;

	int				m_LineInverter;
	int				m_LineStatus;
	int				m_UserOutputValue;
	int				m_LUTEnable;

public:
	CString			GetParam(int, CString);
	CString			GetIntValue(CString);
	CString			GetFloValue(CString);
	CString			GetEnumValue(CString);
	CString			GetComValue(CString);
	CString			GetStrValue(CString);
	CString			GetBooValue(CString);
	void			SetParam(int, CString, CString);
	void			SetIntValue(CString strName, CString strVal);
	void			SetFloValue(CString strName, CString strVal);
	void			SetEnumValue(CString strName, CString strVal);
	void			SetComValue(CString strName, CString strVal);
	void			SetStrValue(CString strName, CString strVal);
	void			SetBooValue(CString strName, CString strVal);
};
