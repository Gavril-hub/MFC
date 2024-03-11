
// OccasionView.h : interface of the COccasionView class
//

#pragma once
#include <afxdb.h>
#include"CARS.h"
#include"CLIENTS.h"
#include"ORDERS.h"
#include"Union.h"
#include"Criteria.h"
#include "AddCLIENT.h"
#include "AddORDER.h"
#include "Criteria.h"
#include "Occasion.h"
//#include"DeleteCAR.h"
#include"AddCARS.h"
#include"AddCLIENT.h"


class COccasionView : public CScrollView
{
protected: // create from serialization only
	COccasionView() noexcept;
	DECLARE_DYNCREATE(COccasionView)

// Attributes
public:
	COccasionDoc* GetDocument() const;
	CCARS* caset;
	CCLIENTS* clset;
	CORDERS* oset;
	CUnion* uset;
// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~COccasionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	int disp;
	//	afx_msg void OnAppExit();
	afx_msg void OnUpdateAppExit(CCmdUI* pCmdUI);
	//	afx_msg void OnAppClear();

	afx_msg void OnViewCARS();
	afx_msg void OnViewCLIENTS();
	afx_msg void OnViewORDERS();
	//afx_msg void OnSortCARS();
	//int criteria;
	CString criteriaa;
	//afx_msg void OnSortCLIENTS();
	afx_msg void OnViewSortcars();
	afx_msg void OnViewSortclients();
	afx_msg void OnAddCar();
	afx_msg void OnAddClient();
	afx_msg void OnAddOrder();
};

#ifndef _DEBUG  // debug version in OccasionView.cpp
inline COccasionDoc* COccasionView::GetDocument() const
   { return reinterpret_cast<COccasionDoc*>(m_pDocument); }
#endif

