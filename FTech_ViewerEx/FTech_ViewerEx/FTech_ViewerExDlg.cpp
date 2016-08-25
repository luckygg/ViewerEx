
// FTech_ViewerExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_ViewerEx.h"
#include "FTech_ViewerExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_ViewerExDlg dialog




CFTech_ViewerExDlg::CFTech_ViewerExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_ViewerExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTech_ViewerExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CS_DISPLAY, m_wndViewer);
}

BEGIN_MESSAGE_MAP(CFTech_ViewerExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CFTech_ViewerExDlg message handlers

BOOL CFTech_ViewerExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_wndViewer.InitControl(this);

	SetTimer(100,30,NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_ViewerExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTech_ViewerExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFTech_ViewerExDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 100)
	{
		if (m_wndViewer.GetBPP() == 8)
		{
			CString tmp=L"";
			CPoint pt = m_wndViewer.GetMousePoint();
			int value = m_wndViewer.GetValueY();
			tmp.Format(L"(%d:%d) : %d",pt.x, pt.y, value);
			SetDlgItemText(IDC_LB_POSITION, tmp);
		}
		else
		{
			CString tmp=L"";
			CPoint pt = m_wndViewer.GetMousePoint();
			COLORREF value = m_wndViewer.GetValueRGB();
			int r = GetBValue(value);
			int g = GetGValue(value);
			int b = GetRValue(value);
			tmp.Format(L"(%d:%d) : %d:%d:%d",pt.x, pt.y, r,g,b);
			SetDlgItemText(IDC_LB_POSITION, tmp);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CFTech_ViewerExDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	KillTimer(100);
}
