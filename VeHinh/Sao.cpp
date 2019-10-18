#include "StdAfx.h"
#include "Sao.h"
#include "math.h"

Sao::Sao(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

Sao::Sao(CPoint p1, CPoint p2)
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

void Sao::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1; y1 = my1;
	x2 = mx2; y2 = my2;
}

void Sao::ve(CClientDC* pDC)
{
	x3 = x2-(x2 - x1) / 8;
	y3 = y1;
	x4 = x1+(x2-x1)/8;
	y4 = y2;
	x5 = ((x2 + x1) / 2);
	y5 = y1-(y2 - y1) /50;
	x6 = x2+(x2-x1)/9; 
	y6 = (y2 + y1) / 2.2;
	x7 = x1- (x2 - x1) / 13;
	y7 = y6;

	pDC->MoveTo(x5, y5);
	pDC->LineTo(x2, y2);
	pDC->MoveTo(x2, y2);
	pDC->LineTo(x7, y7);
	pDC->MoveTo(x7, y7);
	pDC->LineTo(x6, y6);
	pDC->MoveTo(x6, y6);
	pDC->LineTo(x4, y4);
	pDC->MoveTo(x4, y4);
	pDC->LineTo(x5, y5);

	CString S,P;
	S.Format(_T("  Dien tich ngoi sao la : %f   "), dientich());
	P.Format(_T("  Chu vi ngoi sao la : %f   "), chuvi());
	pDC->TextOutW(610, 20, S);
	pDC->TextOutW(880, 20, P);
}

CPoint Sao::getA()
{
	return CPoint(x1, y1);
}

CPoint Sao::getC()
{
	return CPoint(x2, y2);
}

int Sao::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

float Sao::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2 - y1)+1987;
	return kq;
}

float Sao::chuvi()
{
	int kq;
	kq = (x2 - 2 * (x2 - x1) - x1 + y2 - y1+3567) * 4;
	return kq;
}

void Sao::dichuyenlen()
{
	y1 -= 10; y2 -= 10;
}

void Sao::dichuyenxuong()
{
	y1 += 10; y2 += 10;
}

void Sao::dichuyentrai()
{
	x1 -= 10; x2 -= 10;
}

void Sao::dichuyenphai()
{
	x1 += 10; x2 += 10;
}

void Sao::phongto()
{
	x1-=5;y1-=5;
	x2+=5;y2+=5;
}

void Sao::thunho()
{
	x1+=5;y1+=5;
	x2-=5;y2-=5;
}

void Sao::butden(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}

void Sao::buttrang(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}

Sao::Sao(void)
{
}


Sao::~Sao(void)
{
}
