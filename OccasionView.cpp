
// OccasionView.cpp : implementation of the COccasionView class
//
#include <afxdb.h>
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Occasion.h"
#endif

#include "OccasionDoc.h"
#include "OccasionView.h"
#include "AddCARS.h"
#include "CARS.h"
#include "CLIENTS.h"
#include "AddCLIENT.h"
#include"AddORDER.h"
#include "Union.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COccasionViewrab

IMPLEMENT_DYNCREATE(COccasionView, CScrollView)

BEGIN_MESSAGE_MAP(COccasionView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	//	ON_COMMAND(ID_APP_EXIT, &CcatalogView::OnAppExit)
	ON_UPDATE_COMMAND_UI(ID_APP_EXIT, &COccasionView::OnUpdateAppExit)
	//ON_COMMAND(ID_APP_CLEAR, &CcatalogView::OnAppClear)
	ON_COMMAND(ID_VIEW_CARS, &COccasionView::OnViewCARS)
	ON_COMMAND(ID_VIEW_CLIENTS, &COccasionView::OnViewCLIENTS)
	ON_COMMAND(ID_VIEW_ORDERS, &COccasionView::OnViewORDERS)
	//ON_COMMAND(ID_SORT_CARS, &COccasionView::OnSortCARS)
	//ON_COMMAND(ID_SORT_CLIENTS, &COccasionView::OnSortCLIENTS)
	ON_COMMAND(ID_VIEW_SORTCARS, &COccasionView::OnViewSortcars)
	ON_COMMAND(ID_VIEW_SORTCLIENTS, &COccasionView::OnViewSortclients)
	ON_COMMAND(ID_ADD_CAR, &COccasionView::OnAddCar)
	ON_COMMAND(ID_ADD_CLIENT, &COccasionView::OnAddClient)
	ON_COMMAND(ID_ADD_ORDER, &COccasionView::OnAddOrder)
END_MESSAGE_MAP()

// COccasionView construction/destruction

COccasionView::COccasionView() noexcept
	: disp(0)
	//, criteria(0)
	, criteriaa(_T(""))
{
	// TODO: add construction code here

}

COccasionView::~COccasionView()
{
}

BOOL COccasionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// COccasionView drawing

void COccasionView::OnDraw(CDC* pDC)
{
	COccasionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	int y = 10;
	CString str;

	switch (disp) {
	case 1: { caset->MoveFirst();
		while (!caset->IsEOF())
		{
			pDC->TextOutW(5, y, caset->m_RegNum);
			pDC->TextOutW(75, y, caset->m_Brand);
			pDC->TextOutW(360, y, caset->m_Factory);
			str.Format(_T("%d"), caset->m_Year);
			pDC->TextOutW(600, y, str);
			pDC->TextOutW(650, y, caset->m_Type);
			str.Format(_T("%.2f"), caset->m_Price);
			pDC->TextOutW(750, y, str);
			caset->MoveNext();
			y += 20;
		}
	} break;
	case 2: { clset->MoveFirst();
		while (!clset->IsEOF()) {
			pDC->TextOutW(5, y, clset->m_TaxNum);
			pDC->TextOutW(120, y, clset->m_Name);
			pDC->TextOutW(280, y, clset->m_City);
			pDC->TextOutW(380, y, clset->m_Address);
			pDC->TextOutW(580, y, clset->m_Phone);
			clset->MoveNext();
			y += 20;

		}
	}break;
	case 3: {uset->MoveFirst();
		while (!uset->IsEOF()) {
			str.Format(_T("%ld"), uset->m_ORDERSNum);
			pDC->TextOutW(5, y, str);
			pDC->TextOutW(45, y, uset->m_CLIENTSName);
			pDC->TextOutW(180, y, uset->m_CARSBrand);
			str.Format(_T("%d"), uset->m_ORDERSCount);
			pDC->TextOutW(450, y, str);
			str = uset->m_ORDERSDateOrder.Format(_T("%d.%m.%y"));
			pDC->TextOutW(510, y, str);
			if (uset->m_ORDERSPayable)
				pDC->TextOutW(600, y, _T("paid"));
			else
				pDC->TextOutW(600, y, _T("not paid"));
			uset->MoveNext();
			y += 20;


		}
	}break;
	case 4:
	{
		caset->Close();
		caset->m_strSort = criteriaa;
		caset->Open();
		caset->MoveFirst();
		while (!caset->IsEOF()) {
			pDC->TextOutW(5, y, caset->m_RegNum);
			pDC->TextOutW(75, y, caset->m_Brand);
			pDC->TextOutW(360, y, caset->m_Factory);
			str.Format(_T("%d"), caset->m_Year);
			pDC->TextOutW(600, y, str);
			pDC->TextOutW(650, y, caset->m_Type);
			str.Format(_T("%.2f"), caset->m_Price);
			pDC->TextOutW(750, y, str);
			caset->MoveNext();
			y += 20;
		}
		caset->Close();
		caset->m_strSort == "";
		caset->Open();
	}break;
	case 5:
	{clset->MoveFirst();
	while (!clset->IsEOF()) {
		pDC->TextOutW(5, y, clset->m_TaxNum);
		pDC->TextOutW(120, y, clset->m_Name);
		pDC->TextOutW(280, y, clset->m_City);
		pDC->TextOutW(380, y, clset->m_Address);
		pDC->TextOutW(580, y, clset->m_Phone);
		clset->MoveNext();
		y += 20;
	}
	clset->Close();
	clset->m_strSort == "";
	clset->Open();
	}break;
	}
}

void COccasionView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);

	caset = &GetDocument()->ca;
	if (caset->IsOpen()) caset->Close();
	caset->Open();

	clset = &GetDocument()->cl;
	if (clset->IsOpen()) clset->Close();
	clset->Open();

	oset = &GetDocument()->o;
	if (oset->IsOpen()) oset->Close();
	oset->Open();

	uset = &GetDocument()->u;
	uset->m_strFilter = "CARS.RegNum = ORDERS.RegNum AND ORDERS.Taxnum = CLIENTS.Taxnum";
	if (uset->IsOpen()) uset->Close();
	uset->Open();
}


// COccasionView printing

BOOL COccasionView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COccasionView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COccasionView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// COccasionView diagnostics

#ifdef _DEBUG
void COccasionView::AssertValid() const
{
	CScrollView::AssertValid();
}

void COccasionView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

COccasionDoc* COccasionView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COccasionDoc)));
	return (COccasionDoc*)m_pDocument;
}
#endif //_DEBUG


// COccasionView message handlers
void COccasionView::OnUpdateAppExit(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}





void COccasionView::OnViewCARS()
{
	// TODO: Add your command handler code here
	disp = 1;
	Invalidate();
}



void COccasionView::OnViewCLIENTS()
{
	// TODO: Add your command handler code here
	disp = 2;
	Invalidate();
}


void COccasionView::OnViewORDERS()
{
	// TODO: Add your command handler code here
	disp = 3;
	Invalidate();
}


void COccasionView::OnViewSortcars()
{
	// TODO: Add your command handler code here
	Criteria dlg;
	if (dlg.DoModal() == IDOK) {

		if (dlg.criteria == "Year") criteriaa = "Year";
		else if (dlg.criteria == "Brand") criteriaa = "Brand";
		else if (dlg.criteria == "RegNum") criteriaa = "RegNum";
	}

	disp = 4;
	Invalidate();
}



//void COccasionView::OnSortCARS()
//{
//	// TODO: Add your command handler code here
//	Criteria dlg;
//	if (dlg.DoModal() == IDOK) {
//
//		if (dlg.criteria == "Year") criteriaa = "Year";
//		else if (dlg.criteria == "Brand") criteriaa = "Brand";
//		else if (dlg.criteria == "RegNum") criteriaa = "RegNum";
//	}
//
//	disp = 4;
//	Invalidate();
//}


//void COccasionView::OnSortCLIENTS()
//{
//	// TODO: Add your command handler code here
//	Criteria dlg;
//	if (dlg.DoModal() == IDOK) {
//		if (dlg.criteria == "Name") criteriaa = "Name";
//		else if (dlg.criteria = "City") criteriaa = "City";
//
//		disp = 5;
//		Invalidate();
//
//	}
//}



void COccasionView::OnViewSortclients()
{
	// TODO: Add your command handler code here
	Criteria dlg;
	if (dlg.DoModal() == IDOK) {
		if (dlg.criteria == "Name") criteriaa = "Name";
		else if (dlg.criteria = "City") criteriaa = "City";

		disp = 5;
		Invalidate();

	}
}


void COccasionView::OnAddCar()
{
	// TODO: Add your command handler code here
	AddCARS dlg;
	caset->AddNew();
	if (dlg.DoModal() == IDOK)
	{
		caset->m_RegNum = dlg.REGNUM;
		caset->m_Brand = dlg.BRAND;
		caset->m_Factory = dlg.FACTORY;
		caset->m_Year = dlg.YEAR;
		caset->m_Type = dlg.TYPE;
		caset->m_Price = dlg.PRICE;
		caset->Update();
		caset->Requery();
		caset->MoveLast();

	}
}


void COccasionView::OnAddClient()
{
	// TODO: Add your command handler code here
	AddCLIENT dlg;
	clset->AddNew();
	if (dlg.DoModal() == IDOK)
	{
		clset->m_TaxNum = dlg.TaxNum;
		clset->m_Name = dlg.Name;
		clset->m_City = dlg.City;
		clset->m_Address = dlg.Address;
		clset->m_Phone = dlg.Phone;
		clset->Update();
		clset->Requery();
		clset->MoveLast();
	}

}


void COccasionView::OnAddOrder()
{
	// TODO: Add your command handler code here
	AddORDER dlg;
	if (dlg.DoModal() == IDOK)
	{
		oset->MoveFirst();
		long New_id = oset->m_Num + 1;
		oset->AddNew();
		oset->m_Num - New_id;
		oset->m_TaxNum = dlg.m_taxnum;
		oset->m_RegNum = dlg.m_regnum;
		oset->m_Count = dlg.m_count;
		oset->m_Limit = dlg.m_limit;
		oset->m_Payable = dlg.m_payable;
		oset->Update();
		oset->Requery();
		oset->MoveLast();

	}
}
