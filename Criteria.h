#pragma once
#include "afxdialogex.h"


// Criteria dialog

class Criteria : public CDialogEx
{
	DECLARE_DYNAMIC(Criteria)

public:
	Criteria(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Criteria();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CRITERIA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString criteria;
};
