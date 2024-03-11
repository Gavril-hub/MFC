#pragma once
#include "afxdialogex.h"


// AddCARS dialog

class AddCARS : public CDialogEx
{
	DECLARE_DYNAMIC(AddCARS)

public:
	AddCARS(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AddCARS();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_CAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString REGNUM;
	CString BRAND;
	CString FACTORY;
	//CComboBox TYPE;
	CString TYPE;
	float PRICE;
	int YEAR;
	virtual BOOL OnInitDialog();
};

