#pragma once
class Hinh
{
public:
	CPoint diem1, diem2;
	virtual void ve(CClientDC *pdc);
	virtual int tronghinh(CPoint p1);
	virtual float chuvi();
	virtual float dientich();
	virtual void dichuyenlen();
	virtual void dichuyenxuong();
	virtual void dichuyentrai();
	virtual void dichuyenphai();
	virtual void phongto();
	virtual void thunho();
	virtual void butden(CClientDC *pDC);
	virtual void buttrang(CClientDC *pDC);
	Hinh(void);
	~Hinh(void);
};

