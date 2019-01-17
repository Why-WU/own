
// DrawView.cpp : CDrawView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND_RANGE(ID_CURVE,ID_TRIANGLE,&CDrawView::OnChangeDrawType)
	ON_COMMAND(ID_COLOR_DLG, &CDrawView::OnColorDlg)
	ON_COMMAND(ID_FULL, &CDrawView::OnFull)
END_MESSAGE_MAP()

// CDrawView ����/����
enum {CURVE,LINE,RECTANGLE,ELLIPSE,TRIANGLE,FULL};

void CDrawView::OnFull()
{
	//  ���
	m_nDrawType = FULL;
}


void CDrawView::OnColorDlg()
{
	CColorDialog dlg;   //  ��ɫ�����
	if(dlg.DoModal() == IDOK)    //  ��ʾ ��ɫ��
	{
		//  ��ȡѡ�����ɫ
		color = dlg.GetColor();
	}
}


void CDrawView::OnChangeDrawType(UINT uID)
{
	// �޸Ļ���ͼ��
	m_nDrawType = uID-ID_CURVE;
}

CDrawView::CDrawView()
{
	m_nDrawType = CURVE;   //  Ĭ�ϻ�����
	m_bIsDrawFlag = false;    //  �Ƿ�Ҫ��ͼ
	color = RGB(255,0,0);     //  Ĭ�Ϻ�ɫ
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CDrawView ����

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// --------ջ����ͼƬ ��ʾ��������-----------------
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CClientDC dc(this);
	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	cdc.SelectObject(pFrame->sk.top());
	dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);
}
// CDrawView ��ӡ

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CDrawView ���

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView ��Ϣ�������


void CDrawView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_ESCAPE)   //  �Ƿ� ESC
	{
		//  �������ڷ���һ���رյ���Ϣ
		CMainFrame* pFram = (CMainFrame*)AfxGetMainWnd();
		pFram->PostMessage(WM_CLOSE);
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//  �Ƿ�Ҫ���
	if(m_nDrawType == FULL)
	{
		CClientDC dc(this);
		CBrush brush(color);   //  ����һ����ˢ
		dc.SelectObject(brush);
		COLORREF colorPoint = dc.GetPixel(point);   //  ��ȡ������ص����ɫ
		dc.ExtFloodFill(point.x,point.y,colorPoint,FLOODFILLSURFACE);   //  ���
	}


	// ----------------��ʼ��----------------
	m_bIsDrawFlag = true;
	pointDown = point;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// ----------------������----------------
	m_bIsDrawFlag = false;
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	//-----------------�Ѵ����ϵ�ͼƬ �������ŵ�ջ��------------------
	CClientDC dc(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	CBitmap* pBitmap = new CBitmap;
	pBitmap->CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
	cdc.SelectObject(pBitmap);

	cdc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&dc,0,0,SRCCOPY);

	//  �ŵ�ջ��
	pFrame->sk.push(pBitmap);

	CView::OnLButtonUp(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// ----------�Ƿ�ͼ-----------------------------
	if(m_bIsDrawFlag == true && m_nDrawType != FULL)
	{
		CClientDC dc(this);
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

		//------------����-----------------------
		if(m_nDrawType == CURVE)
		{
			CPen pen(PS_SOLID,5,color);  //  ��������
			dc.SelectObject(pen);

			dc.MoveTo(pointDown);
			dc.LineTo(point);
			pointDown = point;
			return;
		}
		//------------����-----------------------


		//======================================================================================================================================
		//-----�������������DC------------------
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);
		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
		memDC.SelectObject(bitmap);
		//-----�������������DC------------------

		// ---------------- ��ջ����Ԫ�� ---�����ƶ��ĺۼ�----------
		CDC cdc;
		cdc.CreateCompatibleDC(&dc);
		cdc.SelectObject(pFrame->sk.top());
		memDC.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);
		// ---------------- ��ջ����Ԫ�� ---�����ƶ��ĺۼ�----------
		//------------����ͼ��-----------------------
		switch (m_nDrawType)
		{
		case LINE:
			{
				CPen pen(PS_SOLID,5,color);  //  ��������
				memDC.SelectObject(pen);
				memDC.MoveTo(pointDown);
				memDC.LineTo(point);	
			}
			break;
		case RECTANGLE:
			{
				CPen pen(PS_SOLID,5,color);  //  ��������
				memDC.SelectObject(pen);
				memDC.SelectStockObject(NULL_BRUSH);   //  ѡ��һ���ջ�ˢ
				memDC.Rectangle(pointDown.x,pointDown.y,point.x,point.y);
			}
			break;
		case ELLIPSE:
			{
				CBrush brush(color);   //  ����һ����ˢ
				memDC.SelectObject(brush);
				memDC.SelectStockObject(NULL_PEN);   //  ѡ��һ���ջ���
				memDC.Ellipse(pointDown.x,pointDown.y,point.x,point.y);
			}
			break;
		case TRIANGLE:
			{
				CPen pen(PS_SOLID,5,color);  //  ��������
				memDC.SelectObject(pen);
				memDC.SelectStockObject(NULL_BRUSH);   //  ѡ��һ���ջ�ˢ
				POINT pointArr[] = {
					{(pointDown.x+point.x)/2,pointDown.y},
					{point.x,point.y},
					{pointDown.x,point.y}
				};
				memDC.Polygon(pointArr,3);   //  �������
			}
			break;
		}
		//------------����ͼ��-----------------------
		dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&memDC,0,0,SRCCOPY);
		//======================================================================================================================================
	}
	CView::OnMouseMove(nFlags, point);
}
