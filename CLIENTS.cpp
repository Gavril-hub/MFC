
//#include "stdafx.h" 
#include "pch.h"
#include <afxdb.h>
#include "CLIENTS.h"
IMPLEMENT_DYNAMIC(CCLIENTS, CRecordset)

CCLIENTS::CCLIENTS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_TaxNum = L"";
	m_Name = L"";
	m_City = L"";
	m_Address = L"";
	m_Phone = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CCLIENTS::GetDefaultConnect()
{
	return _T("DSN=CCatalog;DBQ=D:\\CCatalog.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CCLIENTS::GetDefaultSQL()
{
	return _T("[CLIENTS]");
}

void CCLIENTS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	// Macros such as RFX_Text() and RFX_Int() are dependent on the
	// type of the member variable, not the type of the field in the database.
	// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[TaxNum]"), m_TaxNum);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[City]"), m_City);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	RFX_Text(pFX, _T("[Phone]"), m_Phone);

}
/////////////////////////////////////////////////////////////////////////////
// CFirms diagnostics

#ifdef _DEBUG
void CCLIENTS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCLIENTS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG