#include "StdAfx.h"
#include "Tron.h"
#include "math.h"
Tron::Tron(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

Tron::Tron(CPoint p1, CPoint p2)
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

void Tron::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void Tron::ve(CClientDC *pDC)
{
	int a, b, c, d;
	a = x2 - x1;
	b = y2 - y1;

	c = x1 - x2;
	d = y1 - y2;
	if (y1 < y2 && x1 < x2)
	{
		if (a > b)
		{
			pDC->Ellipse(x1, y1, x1 + b, y2);
		}
		else
		{
			pDC->Ellipse(x1, y1, x2, y1 + a);
		}
	}
	else
	{
		if (y1 < y2 && x1 > x2)
		{
			if (c > b)
			{
				pDC->Ellipse(x1, y1, x1 - b, y2);
			}
			else
			{
				pDC->Ellipse(x1, y1, x2, y1 + c);
			}
		}
		else
		{
			if (y1 > y2 && x1 > x2)
			{
				if (c > d)
				{
					pDC->Ellipse(x2, y2, x2 + d, y1);
				}
				else
				{
					pDC->Ellipse(x2, y2, x1, y2 + c);
				}
			}
			else
			{
				if (a > d)
				{
					pDC->Ellipse(x2, y2, x2 - d, y1);
				}
				else
				{
					pDC->Ellipse(x2, y2, x1, y2 + a);
				}
			}
		}
	}
	CString S,P;
	S.Format(_T("  Dien tich tron la : %f"), dientich());
	P.Format(_T("  Chu vi tron la : %f"), chuvi());
	pDC->TextOutW(610, 20, S);
	pDC->TextOutW(880, 20, P);
}

CPoint Tron::getA()
{
	return CPoint(x1, y1);
}

CPoint Tron::getC()
{
	return CPoint(x2, y2);
}

int Tron::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}

float Tron::dientich()
{
	float kq;
	kq = (sqrt((x2 - x1)*(x2 - x1))+((y2 - y1)*(y2 - y1))/2) *(sqrt((x2 - x1)*(x2 - x1))+((y2 - y1)*(y2 - y1))/2) * 3.14;
	return kq;
}

float Tron::chuvi()
{
	int kq;
	kq = (sqrt((x2 - x1)*(x2 - x1))+((y2 - y1)*(y2 - y1))/2) * 2 * 3.14;
	return kq;
}

void Tron::dichuyenlen()
{
	y1 -= 10; y2 -= 10;
}

void Tron::dichuyenxuong()
{
	y1 += 10; y2 += 10;
}

void Tron::dichuyentrai()
{
	x1 -= 10; x2 -= 10;
}

void Tron::dichuyenphai()
{
	x1 += 10; x2 += 10;
}

void Tron::phongto()
{
	x1-=5;y1-=5;
	x2+=5;y2+=5;
}

void Tron::thunho()
{
	x1+=5;y1+=5;
	x2-=5;y2-=5;
}

void Tron::butden(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}

void Tron::buttrang(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}

Tron::Tron(void)
{
}


Tron::~Tron(void)
{
}
