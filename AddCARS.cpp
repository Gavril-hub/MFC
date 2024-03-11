// AddCARS.cpp : implementation file
//

#include "pch.h"
#include <afxdb.h>
#include "Occasion.h"
#include "afxdialogex.h"
#include "AddCARS.h"
#include "CARS.h"




// AddCARS dialog

IMPLEMENT_DYNAMIC(AddCARS, CDialogEx)

AddCARS::AddCARS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_CAR, pParent)
	
	, REGNUM(_T(""))
	, BRAND(_T(""))
	, FACTORY(_T(""))
	, TYPE(_T(""))
	, PRICE(0)
	, YEAR(0)
{

}

AddCARS::~AddCARS()
{
}

void AddCARS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_REGNUMM, REGNUM);
	DDX_Text(pDX, IDC_BRAND, BRAND);
	DDX_Text(pDX, IDC_FACTORY, FACTORY);
	DDX_CBString(pDX, IDC_TYPE, TYPE);
	DDX_Text(pDX, IDC_PRICE, PRICE);
	DDX_Text(pDX, IDC_YEAR, YEAR);
}


BEGIN_MESSAGE_MAP(AddCARS, CDialogEx)
END_MESSAGE_MAP()


// AddCARS message handlers


BOOL AddCARS::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CCARS ca;
	ca.Open();
	CComboBox* p = (CComboBox*)GetDlgItem(IDC_TYPE);
	p->ResetContent();
	ca.MoveFirst();
	while (!ca.IsEOF())
	{
		p->AddString(ca.m_Type);
		ca.MoveNext();
	}


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
