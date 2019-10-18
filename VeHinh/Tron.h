#pragma once
#include "hinh.h"
class Tron :
	public Hinh
{
private:
	float x1, y1, x2, y2;
public:
	Tron(CPoint p1, CPoint p2);
	Tron(int x1, int y1, int x2, int y2);
	void thietlap(int x1, int y1, int x2, int y2);
	CPoint getA();
	CPoint getC();
	void ve(CClientDC *pdc);
	int tronghinh(CPoint p1);	
	float dientich();
	float chuvi();
	void dichuyenlen();
	void dichuyenxuong();
	void dichuyentrai();
	void dichuyenphai();
	void phongto();
	void thunho();
	void butden(CClientDC *pDC);
	void buttrang(CClientDC *pDC);
	Tron(void);
	~Tron(void);
};

