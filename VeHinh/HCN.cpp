#include "StdAfx.h"
#include "HCN.h"

HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

HCN::HCN(CPoint p1, CPoint p2)
{
	diem1.x = p1.x;
	diem1.y = p1.y;
	diem2.x = p2.x;
	diem2.y = p2.y;
	x1 = p1.x;
	x2 = p2.x;
	y1 = p1.y;
	y2 = p2.y;
}

void HCN::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void HCN::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1, y1, x2, y2);
	CString S,P;
	S.Format(_T("  Dien tich hcn la : %f          "), dientich());
	P.Format(_T("  Chu vi hcn la : %f            "), chuvi());
	pDC->TextOutW(610, 20, S);
	pDC->TextOutW(880, 20, P);
}

int HCN::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

CPoint HCN::getA()
{
	return CPoint(x1, y1);
}

CPoint HCN::getC()
{
	return CPoint(x2, y2);
}

float HCN::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2 - y1);
	return kq;
}

float HCN::chuvi()
{
	int kq;
	kq = ((x2 - x1)+(y2-y1))*2;
	return kq;
}

void HCN::dichuyenlen()
{
	y1 -= 10; y2 -= 10;
}

void HCN::dichuyenxuong()
{
	y1 += 10; y2 += 10;
}

void HCN::dichuyentrai()
{
	x1 -= 10; x2 -= 10;
}

void HCN::dichuyenphai()
{
	x1 += 10; x2 += 10;
}

void HCN::phongto()
{
	x1-=5;y1-=5;
	x2+=5;y2+=5;
}

void HCN::thunho()
{
	x1+=5;y1+=5;
	x2-=5;y2-=5;
}

void HCN::butden(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}

void HCN::buttrang(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}

HCN::HCN(void)
{
}


HCN::~HCN(void)
{
}
