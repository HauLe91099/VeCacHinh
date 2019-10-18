
// VeHinhView.cpp : implementation of the CVeHinhView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "VeHinh.h"
#endif

#include "VeHinhDoc.h"
#include "VeHinhView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVeHinhView

IMPLEMENT_DYNCREATE(CVeHinhView, CView)

BEGIN_MESSAGE_MAP(CVeHinhView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CVeHinhView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CVeHinhView construction/destruction

CVeHinhView::CVeHinhView()
{
	// TODO: add construction code here
	vehcn.thietlap(0, 0, 60, 50);
	vehcn.chu = CString("HCN");

	vetron.thietlap(60, 0, 120, 50);
	vetron.chu = CString("Tron");

	vetg.thietlap(120, 0, 170, 50);
	vetg.chu = CString("TG");

	vevuong.thietlap(170, 0, 230, 50);
	vevuong.chu = CString("Vuong");

	vexu.thietlap(230, 0, 280, 50);
	vexu.chu = CString("Xu");

	vesao.thietlap(280, 0, 330, 50);
	vesao.chu = CString("Sao");

	xoa.thietlap(330, 0, 380, 50);
	xoa.chu = CString("Xoa");

	len.thietlap(380, 0, 410, 50);
	len.chu = CString("^");

	xuong.thietlap(410, 0 , 440, 50);
	xuong.chu = CString("v");

	trai.thietlap(440, 0, 470, 50);
	trai.chu = CString("<");

	phai.thietlap(470, 0, 500, 50);
	phai.chu = CString(">");

	to.thietlap(500, 0, 530, 50);
	to.chu = CString("+");

	nho.thietlap(530, 0, 560, 50);
	nho.chu = CString("-");

	khung1.thietlap(0, 0, 2000, 50);
	n = 0;
}

CVeHinhView::~CVeHinhView()
{
}

BOOL CVeHinhView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVeHinhView drawing

void CVeHinhView::OnDraw(CDC* /*pDC*/)
{
	CVeHinhDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pdc = new CClientDC(this);
	
	khung1.ve(pdc);
	vehcn.ve(pdc);
	vetron.ve(pdc);
	vetg.ve(pdc);
	vevuong.ve(pdc);
	vexu.ve(pdc);
	vesao.ve(pdc);
	xoa.ve(pdc);
	len.ve(pdc);
	xuong.ve(pdc);
	trai.ve(pdc);
	phai.ve(pdc);
	to.ve(pdc);
	nho.ve(pdc);
	// TODO: add draw code for native data here
}


// CVeHinhView printing


void CVeHinhView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CVeHinhView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVeHinhView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVeHinhView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CVeHinhView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CVeHinhView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CVeHinhView diagnostics

#ifdef _DEBUG
void CVeHinhView::AssertValid() const
{
	CView::AssertValid();
}

void CVeHinhView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVeHinhDoc* CVeHinhView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVeHinhDoc)));
	return (CVeHinhDoc*)m_pDocument;
}
#endif //_DEBUG


// CVeHinhView message handlers


void CVeHinhView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.x<2000 && point.x>100 && point.y<1000 && point.y>100)
	{
		p1.x = point.x;
		p1.y = point.y;
	}
	CView::OnLButtonDown(nFlags, point);
}


void CVeHinhView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (point.y > 100 && point.x > 100)
	{
		p2.x = point.x;
		p2.y = point.y;
	}

	CPen *pen;
	CPen *pen1;
	pen1 = new CPen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *pen2;
	pen2 = new CPen(PS_SOLID, 1, RGB(255, 0, 0));

	if (vehcn.tronghinh(point) == 1)
	{
		chon = 1;
		pen = pdc->SelectObject(pen2);
		vehcn.ve(pdc);
	
		pen = pdc->SelectObject(pen1);
		vetron.ve(pdc);
		vetg.ve(pdc);
		vevuong.ve(pdc);
		vexu.ve(pdc);
		vesao.ve(pdc);
		xoa.ve(pdc);
		len.ve(pdc);
		xuong.ve(pdc);
		trai.ve(pdc);
		phai.ve(pdc);
		to.ve(pdc);
		nho.ve(pdc);
	}
	else
		if (vetron.tronghinh(point) == 1)
		{
			chon = 2;
			pen = pdc->SelectObject(pen2);
			vetron.ve(pdc);
	
			pen = pdc->SelectObject(pen1);
			vehcn.ve(pdc);
			vetg.ve(pdc);
			vevuong.ve(pdc);
			vexu.ve(pdc);
			vesao.ve(pdc);
			xoa.ve(pdc);
			len.ve(pdc);
			xuong.ve(pdc);
			trai.ve(pdc);
			phai.ve(pdc);
			to.ve(pdc);
			nho.ve(pdc);
		}
		else
			if (vetg.tronghinh(point) == 1)
			{
				chon = 3;
				pen = pdc->SelectObject(pen2);
				vetg.ve(pdc);
	
				pen = pdc->SelectObject(pen1);
				vehcn.ve(pdc);
				vetron.ve(pdc);
				vevuong.ve(pdc);
				vexu.ve(pdc);
				vesao.ve(pdc);
				xoa.ve(pdc);
				len.ve(pdc);
				xuong.ve(pdc);
				trai.ve(pdc);
				phai.ve(pdc);
				to.ve(pdc);
				nho.ve(pdc);
			}
			else
				if (vevuong.tronghinh(point) == 1)
				{
					chon = 4;
					pen = pdc->SelectObject(pen2);
					vevuong.ve(pdc);
	
					pen = pdc->SelectObject(pen1);
					vehcn.ve(pdc);
					vetg.ve(pdc);
					vetron.ve(pdc);
					vexu.ve(pdc);
					vesao.ve(pdc);
					xoa.ve(pdc);
					len.ve(pdc);
					xuong.ve(pdc);
					trai.ve(pdc);
					phai.ve(pdc);
					to.ve(pdc);
					nho.ve(pdc);
				}
				else
					if (vexu.tronghinh(point) == 1)
					{
						chon = 5;
						pen = pdc->SelectObject(pen2);
						vexu.ve(pdc);
	
						pen = pdc->SelectObject(pen1);
						vehcn.ve(pdc);
						vetg.ve(pdc);
						vetron.ve(pdc);
						vevuong.ve(pdc);
						vesao.ve(pdc);
						xoa.ve(pdc);
						len.ve(pdc);
						xuong.ve(pdc);
						trai.ve(pdc);
						phai.ve(pdc);
						to.ve(pdc);
						nho.ve(pdc);
					}
					else
						if (vesao.tronghinh(point) == 1)
						{
							chon = 6;
							pen = pdc->SelectObject(pen2);
							vesao.ve(pdc);
	
							pen = pdc->SelectObject(pen1);
							vehcn.ve(pdc);
							vetg.ve(pdc);
							vetron.ve(pdc);
							vexu.ve(pdc);
							vevuong.ve(pdc);
							xoa.ve(pdc);
							len.ve(pdc);
							xuong.ve(pdc);
							trai.ve(pdc);
							phai.ve(pdc);
							to.ve(pdc);
							nho.ve(pdc);
						}
						else
							if (xoa.tronghinh(point) == 1)
							{
								chon = 7;
								pen = pdc->SelectObject(pen2);
								xoa.ve(pdc);
	
								pen = pdc->SelectObject(pen1);
								vehcn.ve(pdc);
								vetg.ve(pdc);
								vetron.ve(pdc);
								vexu.ve(pdc);
								vesao.ve(pdc);
								vevuong.ve(pdc);
								len.ve(pdc);
								xuong.ve(pdc);
								trai.ve(pdc);
								phai.ve(pdc);
								to.ve(pdc);
								nho.ve(pdc);
							}
							else
								if (len.tronghinh(point) == 1)
								{
									chon = 8;
									pen = pdc->SelectObject(pen2);
									len.ve(pdc);
	
									pen = pdc->SelectObject(pen1);
									vetron.ve(pdc);
									vetg.ve(pdc);
									vevuong.ve(pdc);
									vexu.ve(pdc);
									vesao.ve(pdc);
									xoa.ve(pdc);
									vehcn.ve(pdc);
									xuong.ve(pdc);
									trai.ve(pdc);
									phai.ve(pdc);
									to.ve(pdc);
									nho.ve(pdc);
								}
								else
									if (xuong.tronghinh(point) == 1)
									{
										chon = 9;
										pen = pdc->SelectObject(pen2);
										xuong.ve(pdc);
	
										pen = pdc->SelectObject(pen1);
										vehcn.ve(pdc);
										vetg.ve(pdc);
										vevuong.ve(pdc);
										vexu.ve(pdc);
										vesao.ve(pdc);
										xoa.ve(pdc);
										len.ve(pdc);
										vetron.ve(pdc);
										trai.ve(pdc);
										phai.ve(pdc);
										to.ve(pdc);
										nho.ve(pdc);
									}
									else
										if (trai.tronghinh(point) == 1)
										{
											chon = 10;
											pen = pdc->SelectObject(pen2);
											trai.ve(pdc);
	
											pen = pdc->SelectObject(pen1);
											vehcn.ve(pdc);
											vetg.ve(pdc);
											vevuong.ve(pdc);
											vexu.ve(pdc);
											vesao.ve(pdc);
											xoa.ve(pdc);
											len.ve(pdc);
											xuong.ve(pdc);
											vetron.ve(pdc);
											phai.ve(pdc);
											to.ve(pdc);
											nho.ve(pdc);
										}
										else
											if (phai.tronghinh(point) == 1)
											{
												chon = 11;
												pen = pdc->SelectObject(pen2);
												phai.ve(pdc);
	
												pen = pdc->SelectObject(pen1);
												vehcn.ve(pdc);
												vetron.ve(pdc);
												vevuong.ve(pdc);
												vexu.ve(pdc);
												vesao.ve(pdc);
												xoa.ve(pdc);
												len.ve(pdc);
												xuong.ve(pdc);
												trai.ve(pdc);
												vetg.ve(pdc);
												to.ve(pdc);
												nho.ve(pdc);
											}
											else
												if (to.tronghinh(point) == 1)
												{
													chon = 12;
													pen = pdc->SelectObject(pen2);
													to.ve(pdc);
	
													pen = pdc->SelectObject(pen1);
													vehcn.ve(pdc);
													vetg.ve(pdc);
													vetron.ve(pdc);
													vexu.ve(pdc);
													vesao.ve(pdc);
													xoa.ve(pdc);
													len.ve(pdc);
													xuong.ve(pdc);
													trai.ve(pdc);
													phai.ve(pdc);
													vevuong.ve(pdc);
													nho.ve(pdc);
												}
												else
													if (nho.tronghinh(point) == 1)
													{
														chon = 13;
														pen = pdc->SelectObject(pen2);
														nho.ve(pdc);
	
														pen = pdc->SelectObject(pen1);
														vehcn.ve(pdc);
														vetg.ve(pdc);
														vetron.ve(pdc);
														vevuong.ve(pdc);
														vesao.ve(pdc);
														xoa.ve(pdc);
														len.ve(pdc);
														xuong.ve(pdc);
														trai.ve(pdc);
														phai.ve(pdc);
														to.ve(pdc);
														vexu.ve(pdc);
													}
													
													else
														if (chon == 1)
														{
															hinh[n] = new HCN(p1, p2);
															hinh[n]->ve(pdc);
															n++;
														}
														else
															if (chon == 2)
															{
																hinh[n] = new Tron(p1, p2);
																hinh[n]->ve(pdc);
																n++;
															}
															else
																if (chon == 3)
																{
																	hinh[n] = new TG(p1, p2);
																	hinh[n]->ve(pdc);
																	n++;
																}
																else
																	if (chon == 4)
																	{
																		hinh[n] = new Vuong(p1, p2);
																		hinh[n]->ve(pdc);
																		n++;
																	}
																	else
																		if (chon == 5)
																		{
																			hinh[n] = new Xu(p1, p2);
																			hinh[n]->ve(pdc);
																			n++;
																		}
																		else
																			if (chon == 6)
																			{
																				hinh[n] = new Sao(p1, p2);
																				hinh[n]->ve(pdc);
																				n++;
																			}
																			else
																				if(chon == 7)
																				{
																					int i;
																					CPen *pen;
																					CBrush *nen;
																					CPen *pen1;
																					pen1 = new CPen(PS_SOLID, 2, RGB(255, 255, 255));
																					for (i = 0; i < n; i++)
																					{
																						if (hinh[i]->tronghinh(point) == 1)
																						{
																							pen = pdc->SelectObject(pen1);
																							hinh[i]->ve(pdc);
																							break;
																						}
																					}
																				}
																				else
																					if(chon==8)
																					{
																						for(int i=0;i<n;i++)
																						{
																							if(hinh[i]->tronghinh(point)==1)
																							{
																								hinh[i]->buttrang(pdc);
																								hinh[i]->dichuyenlen();	
																								hinh[i]->butden(pdc);
																							}
																							}
																					}
																					else
																						if(chon==9)
																						{
																							for(int i=0;i<n;i++)
																							{
																								if(hinh[i]->tronghinh(point)==1)
																								{
																									hinh[i]->buttrang(pdc);
																									hinh[i]->dichuyenxuong();
																									hinh[i]->butden(pdc);
																								}
																							}
																						}
																						else
																							if(chon==10)
																							{
																								for(int i=0;i<n;i++)
																								{
																									if(hinh[i]->tronghinh(point)==1)
																									{
																										hinh[i]->buttrang(pdc);
																										hinh[i]->dichuyentrai();
																										hinh[i]->butden(pdc);
																									}
																								}
																							}
																							else
																								if(chon==11)
																								{
																									for(int i=0;i<n;i++)
																									{
																										if(hinh[i]->tronghinh(point)==1)
																										{
																											hinh[i]->buttrang(pdc);
																											hinh[i]->dichuyenphai();
																											hinh[i]->butden(pdc);
																										}
																									}
																								}
																								else
																									if(chon==12)
																									{
																										for(int i=0;i<n;i++)
																										{
																											if(hinh[i]->tronghinh(point)==1)
																											{
																												hinh[i]->buttrang(pdc);
																												hinh[i]->ve(pdc);
																												hinh[i]->phongto();
																												hinh[i]->butden(pdc);
																												hinh[i]->ve(pdc);
																											}
																										}
																									}
																									else
																										if(chon==13)
																										{
																											for(int i=0;i<n;i++)
																											{
																												if(hinh[i]->tronghinh(point)==1)
																												{
																													hinh[i]->buttrang(pdc);
																													hinh[i]->ve(pdc);
																													hinh[i]->thunho();
																													hinh[i]->butden(pdc);
																													hinh[i]->ve(pdc);
																												}
																											}
																										}
																								
	CView::OnLButtonUp(nFlags, point);
}