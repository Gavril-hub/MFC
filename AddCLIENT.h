#pragma once
#include "afxdialogex.h"


// AddCLIENT dialog

class AddCLIENT : public CDialogEx
{
	DECLARE_DYNAMIC(AddCLIENT)

public:
	AddCLIENT(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddCLIENT();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_CLIENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	CString TaxNum;
	CString Name;
	CString City;
	CString Address;
	CString Phone;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRegNum();
	afx_msg void OnSelchangeTaxNum();
	
};
