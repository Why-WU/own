
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "Draw.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_TOOL_QUIT,&CMainFrame::OnToolbarQuit)
	ON_COMMAND(ID_ACCELERATOR32778, &CMainFrame::OnAccelerator32778)
	ON_COMMAND(ID_SAVE, &CMainFrame::OnSave)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


void CMainFrame::OnSave()
{
	static TCHAR BASED_CODE szFilter[] = _T("jpg|*.jpg|")
   _T("bmp|*.bmp|")
   _T("png|*.png|");


	CFileDialog dlg(FALSE,L"jpg",L"未命名",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
	if(dlg.DoModal() == IDOK)
	{
		//  获取选择的路径
		CString strPath = dlg.GetPathName();
		//  保存
		CImage image;
		image.Attach((HBITMAP)(sk.top()->m_hObject));          //  关联图片
		if(image.Save(strPath) == S_OK)                              // 保存
			MessageBox(L"保存成功");
		else 
			MessageBox(L"保存失败");
		//  分离图片
		image.Detach(); 
	}
}


void CMainFrame::OnToolbarQuit()
{
	this->PostMessageW(WM_CLOSE);
}


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	//-----------------获取屏幕的大小------------------
	m_nScreenCX = ::GetSystemMetrics(SM_CXSCREEN);
	m_nScreenCY = ::GetSystemMetrics(SM_CYSCREEN);
	//-----------------获取屏幕的大小------------------


	// ----------------- 获取 桌面的位图 -----------------
	CWindowDC dcDesktop(GetDesktopWindow());
	CDC cdc;
	cdc.CreateCompatibleDC(&dcDesktop);
	CBitmap* pBitmap = new CBitmap;
	pBitmap->CreateCompatibleBitmap(&dcDesktop,m_nScreenCX,m_nScreenCY);
	cdc.SelectObject(pBitmap);
	cdc.BitBlt(0,0,m_nScreenCX,m_nScreenCY,&dcDesktop,0,0,SRCCOPY);
	// ----------------- 获取 桌面的位图 -----------------

	// ---------------------- 保存到栈中----------------------
	sk.push(pBitmap);
	// ---------------------- 保存到栈中----------------------
}

CMainFrame::~CMainFrame()
{
	//  删除栈中的图片
	while(sk.empty() == false)
	{
		delete sk.top();
		sk.pop();
	}
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_BOTTOM | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}
	
	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//  设置一个NULL菜单
	this->SetMenu(0);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style = WS_POPUP;   //  去掉边框

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序



void CMainFrame::OnAccelerator32778()
{
	if(sk.size() > 1)
	{
		//  删除 栈顶
		delete sk.top();
		sk.pop();
		//  通知视图重绘
		GetActiveView()->SendMessage(WM_PAINT);
	}
}
