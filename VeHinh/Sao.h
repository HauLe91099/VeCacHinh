#pragma once
#include "hinh.h"
class Sao :
	public Hinh
{
public:
	Sao(CPoint p1, CPoint p2);
	Sao(int x1, int y1, int x2, int y2);
	int x1, y1, x2, y2;
	int x3, y3, x4, y4;
	int x5, y5;
	int x6, y6;
	int x7, y7;
	void thietlap(int mx1, int my1, int mx2, int my2);
	void ve(CClientDC* pDC);
	CPoint getA();
	CPoint getC();
	float dientich();
	float chuvi();
	int tronghinh(CPoint p1);
	void dichuyenlen();
	void dichuyenxuong();
	void dichuyentrai();
	void dichuyenphai();
	void phongto();
	void thunho();
	void butden(CClientDC *pDC);
	void buttrang(CClientDC *pDC);
	Sao(void);
	~Sao(void);
};

