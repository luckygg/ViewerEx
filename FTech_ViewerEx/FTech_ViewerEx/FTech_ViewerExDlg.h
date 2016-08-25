
// FTech_ViewerExDlg.h : header file
//

#pragma once
#include "ViewerEx.h"

// CFTech_ViewerExDlg dialog
class CFTech_ViewerExDlg : public CDialogEx
{
// Construction
public:
	CFTech_ViewerExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTech_ViewerEx_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public :
	CViewerEx m_wndViewer;
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
};
