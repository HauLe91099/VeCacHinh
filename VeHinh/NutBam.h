#pragma once
#include "hcn.h"
class NutBam :
	public HCN
{
public:
	CString chu;
	void ve(CClientDC *pdc);
	NutBam(void);
	~NutBam(void);
};

