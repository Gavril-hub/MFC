// AddCLIENT.cpp : implementation file
//

#include "pch.h"
#include <afxdb.h>
#include "Occasion.h"
#include "afxdialogex.h"
#include "AddCLIENT.h"
#include "CARS.h"
#include "AddCARS.h"
#include"CLIENTS.h"
#include"AddORDER.h"
#include"ORDERS.h"



// AddCLIENT dialog

IMPLEMENT_DYNAMIC(AddCLIENT, CDialogEx)

AddCLIENT::AddCLIENT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_CLIENT, pParent)
	, TaxNum(_T(""))
	, Name(_T(""))
	, City(_T(""))
	, Address(_T(""))
	, Phone(_T(""))
{

}

AddCLIENT::~AddCLIENT()
{
}

void AddCLIENT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TAXNUMM, TaxNum);
	DDX_Text(pDX, IDC_EDIT2_NAME, Name);
	DDX_Text(pDX, IDC_EDIT3_CITY, City);
	DDX_Text(pDX, IDC_EDIT4_ADDRESS, Address);
	DDX_Text(pDX, IDC_EDIT5_PHONE, Phone);
}


BEGIN_MESSAGE_MAP(AddCLIENT, CDialogEx)
	
	
END_MESSAGE_MAP()


// AddCLIENT message handlers


BOOL AddCLIENT::OnInitDialog()
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

	CCLIENTS cl;
	cl.Open();
	cl.MoveFirst();
	CListBox* pcl = (CListBox*)GetDlgItem(IDC_TAXNUMM);
	pcl->ResetContent();
	while (!cl.IsEOF())
	{
		pcl->AddString(cl.m_TaxNum);
		cl.MoveFirst();
	}
	cl.Close();


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void AddCLIENT::OnSelchangeRegNum()
{
	CCLIENTS cl;
	cl.Open();
	CListBox* pcl = (CListBox*)GetDlgItem(IDC_REGNUMM);
	long l = pcl->GetCurSel();
	cl.SetAbsolutePosition(l + 1);
	Name = cl.m_Name;
	City = cl.m_City;
	UpdateData(FALSE);
	cl.Close();
}

void AddCLIENT::OnSelchangeTaxNum()
{
	CCLIENTS cl;
	cl.Open();
	CListBox* pcl = (CListBox*)GetDlgItem(IDC_TAXNUMM);
	long l = pcl->GetCurSel();
	cl.SetAbsolutePosition(l + 1);
	Name = cl.m_Name;
	City = cl.m_City;
	UpdateData(FALSE);
	cl.Close();

}

void AddORDER::OnSelchangeRegNum()
{
	CCARS ca;
	ca.Open();
	ca.MoveFirst();
	CListBox* pca = (CListBox*)GetDlgItem(IDC_REGNUMM);
	long l = pca->GetCurSel();
	m_factory = ca.m_Factory;
	m_brand = ca.m_Brand;
	UpdateData(FALSE);
	ca.Close();
}







