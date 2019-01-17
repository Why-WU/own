
// DrawView.cpp : CDrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
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

// CDrawView 构造/析构
enum {CURVE,LINE,RECTANGLE,ELLIPSE,TRIANGLE,FULL};

void CDrawView::OnFull()
{
	//  填充
	m_nDrawType = FULL;
}


void CDrawView::OnColorDlg()
{
	CColorDialog dlg;   //  调色板对象
	if(dlg.DoModal() == IDOK)    //  显示 调色板
	{
		//  获取选择的颜色
		color = dlg.GetColor();
	}
}


void CDrawView::OnChangeDrawType(UINT uID)
{
	// 修改画的图形
	m_nDrawType = uID-ID_CURVE;
}

CDrawView::CDrawView()
{
	m_nDrawType = CURVE;   //  默认画曲线
	m_bIsDrawFlag = false;    //  是否要画图
	color = RGB(255,0,0);     //  默认红色
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawView 绘制

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// --------栈顶的图片 显示到窗口上-----------------
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CClientDC dc(this);
	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	cdc.SelectObject(pFrame->sk.top());
	dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);
}
// CDrawView 打印

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawView 诊断

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView 消息处理程序


void CDrawView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_ESCAPE)   //  是否按 ESC
	{
		//  给主窗口发送一个关闭的消息
		CMainFrame* pFram = (CMainFrame*)AfxGetMainWnd();
		pFram->PostMessage(WM_CLOSE);
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//  是否要填充
	if(m_nDrawType == FULL)
	{
		CClientDC dc(this);
		CBrush brush(color);   //  创建一个画刷
		dc.SelectObject(brush);
		COLORREF colorPoint = dc.GetPixel(point);   //  获取光标像素点的颜色
		dc.ExtFloodFill(point.x,point.y,colorPoint,FLOODFILLSURFACE);   //  填充
	}


	// ----------------开始画----------------
	m_bIsDrawFlag = true;
	pointDown = point;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// ----------------结束画----------------
	m_bIsDrawFlag = false;
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	//-----------------把窗口上的图片 拿下来放到栈里------------------
	CClientDC dc(this);

	CDC cdc;
	cdc.CreateCompatibleDC(&dc);
	CBitmap* pBitmap = new CBitmap;
	pBitmap->CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
	cdc.SelectObject(pBitmap);

	cdc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&dc,0,0,SRCCOPY);

	//  放到栈里
	pFrame->sk.push(pBitmap);

	CView::OnLButtonUp(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// ----------是否画图-----------------------------
	if(m_bIsDrawFlag == true && m_nDrawType != FULL)
	{
		CClientDC dc(this);
		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

		//------------曲线-----------------------
		if(m_nDrawType == CURVE)
		{
			CPen pen(PS_SOLID,5,color);  //  创建画笔
			dc.SelectObject(pen);

			dc.MoveTo(pointDown);
			dc.LineTo(point);
			pointDown = point;
			return;
		}
		//------------曲线-----------------------


		//======================================================================================================================================
		//-----用来解决闪屏的DC------------------
		CDC memDC;
		memDC.CreateCompatibleDC(&dc);
		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc,pFrame->m_nScreenCX,pFrame->m_nScreenCY);
		memDC.SelectObject(bitmap);
		//-----用来解决闪屏的DC------------------

		// ---------------- 用栈顶的元素 ---擦除移动的痕迹----------
		CDC cdc;
		cdc.CreateCompatibleDC(&dc);
		cdc.SelectObject(pFrame->sk.top());
		memDC.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&cdc,0,0,SRCCOPY);
		// ---------------- 用栈顶的元素 ---擦除移动的痕迹----------
		//------------其他图形-----------------------
		switch (m_nDrawType)
		{
		case LINE:
			{
				CPen pen(PS_SOLID,5,color);  //  创建画笔
				memDC.SelectObject(pen);
				memDC.MoveTo(pointDown);
				memDC.LineTo(point);	
			}
			break;
		case RECTANGLE:
			{
				CPen pen(PS_SOLID,5,color);  //  创建画笔
				memDC.SelectObject(pen);
				memDC.SelectStockObject(NULL_BRUSH);   //  选入一个空画刷
				memDC.Rectangle(pointDown.x,pointDown.y,point.x,point.y);
			}
			break;
		case ELLIPSE:
			{
				CBrush brush(color);   //  创建一个画刷
				memDC.SelectObject(brush);
				memDC.SelectStockObject(NULL_PEN);   //  选入一个空画笔
				memDC.Ellipse(pointDown.x,pointDown.y,point.x,point.y);
			}
			break;
		case TRIANGLE:
			{
				CPen pen(PS_SOLID,5,color);  //  创建画笔
				memDC.SelectObject(pen);
				memDC.SelectStockObject(NULL_BRUSH);   //  选入一个空画刷
				POINT pointArr[] = {
					{(pointDown.x+point.x)/2,pointDown.y},
					{point.x,point.y},
					{pointDown.x,point.y}
				};
				memDC.Polygon(pointArr,3);   //  画多边形
			}
			break;
		}
		//------------其他图形-----------------------
		dc.BitBlt(0,0,pFrame->m_nScreenCX,pFrame->m_nScreenCY,&memDC,0,0,SRCCOPY);
		//======================================================================================================================================
	}
	CView::OnMouseMove(nFlags, point);
}
