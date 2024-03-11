#include "pch.h"
#include <afxdb.h>
//#include "stdafx.h" 

#include "ORDERS.h"
IMPLEMENT_DYNAMIC(CORDERS, CRecordset)

CORDERS::CORDERS(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Num = 0;
	m_TaxNum = L"";
	m_RegNum = L"";
	m_DateOrder;
	m_Count = 0;
	m_Payable = FALSE;
	m_Limit = 0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CORDERS::GetDefaultConnect()
{
	return _T("DSN=CCatalog;DBQ=D:\\CCatalog.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CORDERS::GetDefaultSQL()
{
	return _T("[ORDERS]");
}

void CORDERS::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	// Macros such as RFX_Text() and RFX_Int() are dependent on the
	// type of the member variable, not the type of the field in the database.
	// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[Num]"), m_Num);
	RFX_Text(pFX, _T("[TaxNum]"), m_TaxNum);
	RFX_Text(pFX, _T("[RegNum]"), m_RegNum);
	RFX_Date(pFX, _T("[DateOrder]"), m_DateOrder);
	RFX_Byte(pFX, _T("[Count]"), m_Count);
	RFX_Bool(pFX, _T("[Payable]"), m_Payable);
	RFX_Byte(pFX, _T("[Limit]"), m_Limit);

}
/////////////////////////////////////////////////////////////////////////////
// COrders diagnostics

#ifdef _DEBUG
void CORDERS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CORDERS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG