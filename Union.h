#pragma once

class CUnion : public CRecordset
{
public:
	CUnion(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUnion)

	CStringW	m_CARSRegNum;
	CStringW	m_CARSBrand;
	CStringW	m_CARSFactory;
	long	m_CARSYear;
	CStringW	m_CARSType;
	float	m_CARSPrice;
	CStringW	m_CLIENTSTaxNum;
	CStringW	m_CLIENTSName;
	CStringW	m_CLIENTSCity;
	CStringW	m_CLIENTSAddress;
	CStringW	m_CLIENTSPhone;
	long	m_ORDERSNum;
	CStringW	m_ORDERSTaxNum;
	CStringW	m_ORDERSRegNum;
	CTime	m_ORDERSDateOrder;
	BYTE	m_ORDERSCount;
	BOOL	m_ORDERSPayable;
	BYTE	m_ORDERSLimit;

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
