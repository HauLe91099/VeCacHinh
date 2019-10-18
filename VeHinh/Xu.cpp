#include "StdAfx.h"
#include "Xu.h"
#include "math.h"

Xu::Xu(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

Xu::Xu(CPoint p1, CPoint p2)
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
void Xu::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	x2 = mx2;
	y1 = my1;
	y2 = my2;
}

void Xu::ve(CClientDC *pDC)
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
			pDC->Ellipse(x1 + 40, y1 + 40, x1 + b - 40, y2 - 40);
		}
		else
		{
			pDC->Ellipse(x1, y1, x2, y1 + a);
			pDC->Ellipse(x1 + 40, y1 + 40, x2 - 40, y1 + a - 40);
		}
	}
	else
	{
		if (y1 < y2 && x1 > x2)
		{
			if (c > b)
			{
				pDC->Ellipse(x1, y1, x1 - b, y2);
				pDC->Ellipse(x1 + 40, y1 + 40, x1 - b - 40, y2 - 40);
			}
			else
			{
				pDC->Ellipse(x1, y1, x2, y1 + c);
				pDC->Ellipse(x1 + 40, y1 + 40, x2 - 40, y1 + c - 40);
			}
		}
		else
		{
			if (y1 > y2 && x1 > x2)
			{
				if (c > d)
				{
					pDC->Ellipse(x2, y2, x2 + d, y1);
					pDC->Ellipse(x2 + 40, y2 + 40, x2 + d - 40, y1 - 40);
				}
				else
				{
					pDC->Ellipse(x2, y2, x1, y2 + c);
					pDC->Ellipse(x2 + 40, y2 + 40, x1 - 40, y2 + c - 40);
				}
			}
			else
			{
				if (a > d)
				{
					pDC->Ellipse(x2, y2, x2 - d, y1);
					pDC->Ellipse(x2 + 40, y2 + 40, x2 - d - 40, y1 - 40);
				}
				else
				{
					pDC->Ellipse(x2, y2, x1, y2 + a);
					pDC->Ellipse(x2 + 40, y2 + 40, x1 - 40, y2 + a - 40);
				}
			}
		}
	}
	CString S,P;
	S.Format(_T("  Dien tich dong xu la : %f     "), dientich());
	P.Format(_T("  Chu vi dong xu la : %f     "), chuvi());
	pDC->TextOutW(610, 20, S);
	pDC->TextOutW(880, 20, P);
}

int Xu::tronghinh(CPoint p)
{
	int kq = 0;
	if (p.x >= x1 && p.x <= x2 && p.y >= y1 && p.y <= y2)
		kq = 1;
	return kq;
}
CPoint Xu::getA()
{
	return CPoint(x1, y1);
}

CPoint Xu::getC()
{
	return CPoint(x2, y2);
}

float Xu::dientich()
{
	float kq , r;
	r = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) / 2;
	kq = 3.14 * r* r;
	return kq;
}

float Xu::chuvi()
{
	float kq = 0, r;
	r = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) / 2);
	kq = 3.14 * r * 2;
	return kq;
}

void Xu::dichuyenlen()
{
	y1 -= 10; y2 -= 10;
}

void Xu::dichuyenxuong()
{
	y1 += 10; y2 += 10;
}

void Xu::dichuyentrai()
{
	x1 -= 10; x2 -= 10;
}

void Xu::dichuyenphai()
{
	x1 += 10; x2 += 10;
}

void Xu::phongto()
{
	x1-=5;y1-=5;
	x2+=5;y2+=5;
}

void Xu::thunho()
{
	x1+=5;y1+=5;
	x2-=5;y2-=5;
}

void Xu::butden(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
	ve(pDC);
}

void Xu::buttrang(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
	ve(pDC);
}

Xu::Xu(void)
{
}


Xu::~Xu(void)
{
}
