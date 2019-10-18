#include "StdAfx.h"
#include "Vuong.h"
#include "math.h"

Vuong::Vuong(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

Vuong::Vuong(CPoint p1, CPoint p2)
{
	x1=p1.x;
	x2=p2.x;
	if(p1.y<p2.y)
	{
		y1=p1.y;
		y2=(sqrt((float)(x2-x1)*(x2-x1))-(p2.y-y1))+p2.y;
	}
	else
	{
		y1=p2.y;
		y2=(sqrt((float)(x2-x1)*(x2-x1))-(p2.y-y1))+p2.y;
	}
}

void Vuong::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void Vuong::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1, y1, x2, y2);
	CString S,P;
	S.Format(_T("  Dien tich hinh vuong la : %f  "), dientich());
	P.Format(_T("  Chu vi hinh vuong la : %f  "), chuvi());
	pDC->TextOutW(610, 20, S);
	pDC->TextOutW(880, 20, P);
}

int Vuong::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

CPoint Vuong::getA()
{
	return CPoint(x1, y1);
}

CPoint Vuong::getC()
{
	return CPoint(x2, y2);
}

float Vuong::dientich()
{
	float kq;
	kq = (x2 - x1)*(y2-y1);
	return kq;
}

float Vuong::chuvi()
{
	int kq;
	kq = ((x2 - x1)+(y2-y1))*2;
	return kq;
}

void Vuong::dichuyenlen()
{
	y1 -= 10; y2 -= 10;
}

void Vuong::dichuyenxuong()
{
	y1 += 10; y2 += 10;
}

void Vuong::dichuyentrai()
{
	x1 -= 10; x2 -= 10;
}

void Vuong::dichuyenphai()
{
	x1 += 10; x2 += 10;
}

void Vuong::phongto()
{
	x1-=5;y1-=5;
	x2+=5;y2+=5;
}

void Vuong::thunho()
{
	x1+=5;y1+=5;
	x2-=5;y2-=5;
}

void Vuong::butden(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}

void Vuong::buttrang(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}

Vuong::Vuong(void)
{
}


Vuong::~Vuong(void)
{
}
