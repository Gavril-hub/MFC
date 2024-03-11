//#include "stdafx.h"


#include "pch.h"
#include <afxdb.h>
#include "Union.h"
#include "AddCLIENT.h"
#include "CARS.h"
#include "Criteria.h"
IMPLEMENT_DYNAMIC(CUnion, CRecordset)

CUnion::CUnion(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_CARSRegNum = L"";
	m_CARSBrand = L"";
	m_CARSFactory = L"";
	m_CARSYear = 0;
	m_CARSType = L"";
	//m_BOOKSPubl = L"";
	m_CARSPrice = 0.0;
	m_CLIENTSTaxNum = L"";
	m_CLIENTSName = L"";
	m_CLIENTSCity = L"";
	m_CLIENTSAddress = L"";
	m_CLIENTSPhone = L"";
	m_ORDERSNum = 0;
	m_ORDERSTaxNum = L"";
	m_ORDERSRegNum = L"";
	m_ORDERSDateOrder;
	m_ORDERSCount = 0;
	m_ORDERSPayable = FALSE;
	m_ORDERSLimit = 0;
	m_nFields = 19;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString CUnion::GetDefaultConnect()
{
	return _T("DSN=CCatalog;DBQ=D:\\CCatalog.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CUnion::GetDefaultSQL()
{
	return _T("[CARS],[CLIENTS],[ORDERS]");
}

void CUnion::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
	// Macros such as RFX_Text() and RFX_Int() are dependent on the
	// type of the member variable, not the type of the field in the database.
	// ODBC will try to automatically convert the column value to the requested type
	RFX_Text(pFX, _T("[CARS].[RegNum]"), m_CARSRegNum);
	RFX_Text(pFX, _T("[CARS].[Brand]"), m_CARSBrand);
	RFX_Text(pFX, _T("[CARS].[Factory]"), m_CARSFactory);
	RFX_Long(pFX, _T("[CARS].[Year]"), m_CARSYear);
	RFX_Text(pFX, _T("[CARS].[Type]"), m_CARSType);
	RFX_Single(pFX, _T("[CARS].[Price]"), m_CARSPrice);
	RFX_Text(pFX, _T("[CLIENTS].[TaxNum]"), m_CLIENTSTaxNum);
	RFX_Text(pFX, _T("[CLIENTS].[Name]"), m_CLIENTSName);
	RFX_Text(pFX, _T("[CLIENTS].[City]"), m_CLIENTSCity);
	RFX_Text(pFX, _T("[CLIENTS].[Address]"), m_CLIENTSAddress);
	RFX_Text(pFX, _T("[CLIENTS].[Phone]"), m_CLIENTSPhone);
	RFX_Long(pFX, _T("[ORDERS].[Num]"), m_ORDERSNum);
	RFX_Text(pFX, _T("[ORDERS].[TaxNum]"), m_ORDERSTaxNum);
	RFX_Text(pFX, _T("[ORDERS].[RegNum]"), m_ORDERSRegNum);
	RFX_Date(pFX, _T("[ORDERS].[DateOrder]"), m_ORDERSDateOrder);
	RFX_Byte(pFX, _T("[ORDERS].[Count]"), m_ORDERSCount);
	RFX_Bool(pFX, _T("[ORDERS].[Payable]"), m_ORDERSPayable);
	RFX_Byte(pFX, _T("[ORDERS].[Limit]"), m_ORDERSLimit);

}
/////////////////////////////////////////////////////////////////////////////
// CUnion diagnostics

#ifdef _DEBUG
void CUnion::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUnion::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG