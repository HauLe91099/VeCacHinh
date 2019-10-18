#include "StdAfx.h"
#include "TG.h"

TG::TG(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

TG::TG(CPoint p1, CPoint p2)
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

void TG::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void TG::ve(CClientDC *pDC)
{
	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);
	pDC->LineTo(x2-2*(x2-x1), y2);
	pDC->LineTo(x1, y1);

	CString S,P;
	S.Format(_T("  Dien tich tam giac la : %f"), dientich());
	P.Format(_T("  Chu vi tam giac la : %f"), chuvi());
	pDC->TextOutW(610, 20, S);
	pDC->TextOutW(880, 20, P);
}

CPoint TG::getA()
{
	return CPoint(x1, y1);
}

CPoint TG::getC()
{
	return CPoint(x2, y2);
}

float TG::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2 - y1)+1987;
	return kq;
}

float TG::chuvi()
{
	int kq;
	kq = (x2 - 2 * (x2 - x1) - x1 + y2 - y1+3567) * 4;
	return kq;
}

int TG::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x2-2*(x2-x1) && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

void TG::dichuyenlen()
{
	y1 -= 10; y2 -= 10;
}

void TG::dichuyenxuong()
{
	y1 += 10; y2 += 10;
}

void TG::dichuyentrai()
{
	x1 -= 10; x2 -= 10;
}

void TG::dichuyenphai()
{
	x1 += 10; x2 += 10;
}

void TG::phongto()
{
	x1-=5;y1-=5;
	x2+=5;y2+=5;
}

void TG::thunho()
{
	x1+=5;y1+=5;
	x2-=5;y2-=5;
}

void TG::butden(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}

void TG::buttrang(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}

TG::TG(void)
{
}


TG::~TG(void)
{
}
