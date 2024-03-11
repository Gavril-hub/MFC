
// Occasion.h : main header file for the Occasion application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// COccasionApp:
// See Occasion.cpp for the implementation of this class
//

class COccasionApp : public CWinApp
{
public:
	COccasionApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	//afx_msg void OnViewCARS();
	DECLARE_MESSAGE_MAP()
};

extern COccasionApp theApp;
