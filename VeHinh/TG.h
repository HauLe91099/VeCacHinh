#pragma once
#include "hinh.h"
class TG :
	public Hinh
{
public:
	int x1, y1, x2, y2;
	TG(CPoint p1, CPoint p2);
	TG(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void ve(CClientDC *pdc);
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
	TG(void);
	~TG(void);
};

