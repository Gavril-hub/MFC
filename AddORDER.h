#pragma once
#include "afxdialogex.h"


// AddORDER dialog

class AddORDER : public CDialogEx
{
	DECLARE_DYNAMIC(AddORDER)

public:
	AddORDER(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddORDER();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_ORDER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_regnum;
	CString m_brand;
	CString m_factory;
	CString m_taxnum;
	CString m_name;
	CString m_city;
	BYTE m_count;
	BOOL m_payable;
	BYTE m_limit;

	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRegNum();
	afx_msg void OnSelchangeTaxNum();
	afx_msg void OnBnClickedCheck1Payable();
	
};
