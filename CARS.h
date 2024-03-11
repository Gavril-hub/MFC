#pragma once
#include <afxdb.h>
class CCARS : public CRecordset
{
public:
	CCARS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCARS)


CStringW	m_RegNum;
CStringW	m_Brand;
CStringW	m_Factory;
long	m_Year;
CStringW	m_Type;
CStringW	m_Dilership;
float	m_Price;

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