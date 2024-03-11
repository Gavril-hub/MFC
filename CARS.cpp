

#include "pch.h" 
#include <afxdb.h>
#include "CARS.h"
IMPLEMENT_DYNAMIC(CCARS, CRecordset)

CCARS::CCARS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_RegNum = L"";
	m_Brand = L"";
	m_Factory = L"";
	m_Year = 0;
	m_Type = L"";
	m_Price = 0.0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CCARS::GetDefaultConnect()
{
	return _T("DSN=CCatalog;DBQ=D:\\CCatalog.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CCARS::GetDefaultSQL()
{
	return _T("[CARS]");
}

void CCARS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	// Macros such as RFX_Text() and RFX_Int() are dependent on the
	// type of the member variable, not the type of the field in the database.
	// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[RegNum]"), m_RegNum);
	RFX_Text(pFX, _T("[Brand]"), m_Brand);
	RFX_Text(pFX, _T("[Factory]"), m_Factory);
	RFX_Long(pFX, _T("[Year]"), m_Year);
	RFX_Text(pFX, _T("[Type]"), m_Type);
	RFX_Single(pFX, _T("[Price]"), m_Price);

}
/////////////////////////////////////////////////////////////////////////////
// CBooks diagnostics

#ifdef _DEBUG
void CCARS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCARS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
