#pragma once

class CORDERS : public CRecordset
{
public:
	CORDERS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CORDERS)

	long	m_Num;
	CStringW	m_TaxNum;
	CStringW	m_RegNum;
	CTime	m_DateOrder;
	BYTE	m_Count;
	BOOL	m_Payable;
	BYTE	m_Limit;

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
