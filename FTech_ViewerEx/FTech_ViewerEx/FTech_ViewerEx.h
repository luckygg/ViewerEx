
// FTech_ViewerEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTech_ViewerExApp:
// See FTech_ViewerEx.cpp for the implementation of this class
//

class CFTech_ViewerExApp : public CWinApp
{
public:
	CFTech_ViewerExApp();

	ULONG_PTR m_gdiplusToken;
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFTech_ViewerExApp theApp;