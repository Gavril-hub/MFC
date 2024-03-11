#pragma once
#include <afxdb.h>
class CCLIENTS : public CRecordset
{
public:
	CCLIENTS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCLIENTS)

	CStringW	m_TaxNum;
	CStringW	m_Name;
	CStringW	m_City;
	CStringW	m_Address;
	CStringW	m_Phone;

public:
	virtual CString GetDefaultConnect();	// Default connection string

	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support

	// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};
