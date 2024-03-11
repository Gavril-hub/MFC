// Criteria.cpp : implementation file
//

#include "pch.h"
#include <afxdb.h>
#include "Occasion.h"
#include "afxdialogex.h"
#include "Criteria.h"


// Criteria dialog

IMPLEMENT_DYNAMIC(Criteria, CDialogEx)

Criteria::Criteria(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CRITERIA, pParent)
	, criteria(_T(""))
{

}

Criteria::~Criteria()
{
}

void Criteria::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, criteria);
}


BEGIN_MESSAGE_MAP(Criteria, CDialogEx)
END_MESSAGE_MAP()


// Criteria message handlers
