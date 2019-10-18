#include "StdAfx.h"
#include "NutBam.h"

void NutBam::ve(CClientDC *pDC)
{
	pDC->Rectangle(getA().x, getA().y, getC().x, getC().y);
	pDC->TextOutW(getA().x + 10, getA().y +18, chu);
}
NutBam::NutBam(void)
{
}


NutBam::~NutBam(void)
{
}
