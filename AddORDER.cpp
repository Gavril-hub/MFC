// AddORDER.cpp : implementation file
//

#include "pch.h"
#include <afxdb.h>
#include "Occasion.h"
#include "afxdialogex.h"
#include "AddORDER.h"
#include "AddCARS.h"
#include "CARS.h"
#include "CLIENTS.h"
#include "AddCLIENT.h"
#include"ORDERS.h"


// AddORDER dialog

IMPLEMENT_DYNAMIC(AddORDER, CDialogEx)

AddORDER::AddORDER(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_ORDER, pParent)
	, m_regnum(_T(""))
	, m_brand(_T(""))
	, m_factory(_T(""))
	, m_taxnum(_T(""))
	, m_name(_T(""))
	, m_city(_T(""))
	, m_count(0)
	, m_payable(FALSE)
	, m_limit(0)
{

}

AddORDER::~AddORDER()
{
}

void AddORDER::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_LBString(pDX, IDC_EDIT_REGNUM, m_regnum);
	DDX_Text(pDX, IDC_EDIT1_BRAND, m_brand);
	DDX_Text(pDX, IDC_EDIT2_FACTORY, m_factory);
	DDX_LBString(pDX, IDC_LIST2_TAXNUM, m_taxnum);
	DDX_Text(pDX, IDC_EDIT3_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT4_CITY, m_city);
	DDX_Text(pDX, IDC_EDIT5_COUNT, m_count);
	DDX_Check(pDX, IDC_CHECK1_PAYABLE, m_payable);
	DDX_Text(pDX, IDC_EDIT6_LIMIT, m_limit);
}


BEGIN_MESSAGE_MAP(AddORDER, CDialogEx)
	//ON_BN_CLICKED(IDC_CHECK1_PAYABLE, &AddORDER::OnBnClickedCheck1Payable)
	
END_MESSAGE_MAP()


// AddORDER message handlers


BOOL AddORDER::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CCARS ca;
	ca.Open();
	ca.MoveFirst();
	CListBox* pca = (CListBox*)GetDlgItem(IDC_REGNUMM);
	pca->ResetContent();
	while (!ca.IsEOF())
	{
		pca->AddString(ca.m_RegNum);
		ca.MoveNext();
	}
	ca.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//void AddORDER::OnSelchangeTaxNum()
//{
//	/*CCLIENTS cl;
//	cl.Open();
//	CListBox* pcl = (CListBox*)GetDlgItem(IDC_LIST2_TAXNUM);
//	long l = pcl->GetCurSel();
//	cl.SetAbsolutePosition(l + 1);
//	m_name = cl.m_Name;
//	m_city = cl.m_City;
//	UpdateData(FALSE);
//	cl.Close();*/
//}

//void AddORDER::OnSelchangeRegNum()
//{
///*	CCARS ca;
//	ca.Open();
//	ca.MoveFirst();
//	CListBox* pca = (CListBox*)GetDlgItem(IDC_REGNUMM);
//	long l = pca->GetCurSel();
//	m_factory = ca.m_Factory;
//	m_brand = ca.m_Brand;
//	UpdateData(FALSE);
//	ca.Close();*/
//}

//void AddCLIENT::OnSelchangeTaxNum()
//{
//	/*CCLIENTS cl;
//	cl.Open();
//	CListBox* pcl = (CListBox*)GetDlgItem(IDC_LIST2_TAXNUM);
//	long l = pcl->GetCurSel();
//	cl.SetAbsolutePosition(l + 1);
//	Name = cl.m_Name;
//	City = cl.m_City;
//	UpdateData(FALSE);
//	cl.Close();*/
//
//}


//void AddORDER::OnBnClickedCheck1Payable()
//{
//	// TODO: Add your control notification handler code here
//	/*UpdateData(TRUE);
//	if (m_payable)
//		GetDlgItem(IDC_CHECK1)->EnableWindow(FALSE);
//	else GetDlgItem(IDC_CHECK1)->EnableWindow(TRUE);
//	*/
//}


