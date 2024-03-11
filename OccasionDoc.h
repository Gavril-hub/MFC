
// OccasionDoc.h : interface of the COccasionDoc class
//


#pragma once

#include "CARS.h"
#include "CLIENTS.h"
#include "ORDERS.h"
#include "Union.h"

class COccasionDoc : public CDocument
{
protected: // create from serialization only
	COccasionDoc() noexcept;
	DECLARE_DYNCREATE(COccasionDoc)

// Attributes
public:

// Operations
public:
	CCARS ca;
	CCLIENTS cl;
	CORDERS o;
	CUnion u;

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~COccasionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
