
// VeHinhView.h : interface of the CVeHinhView class
//

#pragma once
#include"HCN.h"
#include"Hinh.h"
#include"Tron.h"
#include"NutBam.h"
#include "TG.h"
#include "Vuong.h"
#include "Sao.h"
#include "Xu.h"

class CVeHinhView : public CView
{
protected: // create from serialization only
	CVeHinhView();
	DECLARE_DYNCREATE(CVeHinhView)

// Attributes
public:
	CVeHinhDoc* GetDocument() const;

// Operations
public:
	NutBam vehcn, vetron, vetg, vevuong, vexu, vesao, xoa, len, xuong, trai, phai, to, nho, khung1;
	CClientDC *pdc;
	CPoint p1, p2;
	int n;
	int chon;
	int mau;
	Hinh *hinh[30];
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVeHinhView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in VeHinhView.cpp
inline CVeHinhDoc* CVeHinhView::GetDocument() const
   { return reinterpret_cast<CVeHinhDoc*>(m_pDocument); }
#endif

