
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


void CMainFrame::OnSave()
{
	static TCHAR BASED_CODE szFilter[] = _T("jpg|*.jpg|")
   _T("bmp|*.bmp|")
   _T("png|*.png|");


	CFileDialog dlg(FALSE,L"jpg",L"δ����",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter);
	if(dlg.DoModal() == IDOK)
	{
		//  ��ȡѡ���·��
		CString strPath = dlg.GetPathName();
		//  ����
		CImage image;
		image.Attach((HBITMAP)(sk.top()->m_hObject));          //  ����ͼƬ
		if(image.Save(strPath) == S_OK)                              // ����
			MessageBox(L"����ɹ�");
		else 
			MessageBox(L"����ʧ��");
		//  ����ͼƬ
		image.Detach(); 
	}
}


void CMainFrame::OnToolbarQuit()
{
	this->PostMessageW(WM_CLOSE);
}


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	//-----------------��ȡ��Ļ�Ĵ�С------------------
	m_nScreenCX = ::GetSystemMetrics(SM_CXSCREEN);
	m_nScreenCY = ::GetSystemMetrics(SM_CYSCREEN);
	//-----------------��ȡ��Ļ�Ĵ�С------------------


	// ----------------- ��ȡ �����λͼ -----------------
	CWindowDC dcDesktop(GetDesktopWindow());
	CDC cdc;
	cdc.CreateCompatibleDC(&dcDesktop);
	CBitmap* pBitmap = new CBitmap;
	pBitmap->CreateCompatibleBitmap(&dcDesktop,m_nScreenCX,m_nScreenCY);
	cdc.SelectObject(pBitmap);
	cdc.BitBlt(0,0,m_nScreenCX,m_nScreenCY,&dcDesktop,0,0,SRCCOPY);
	// ----------------- ��ȡ �����λͼ -----------------

	// ---------------------- ���浽ջ��----------------------
	sk.push(pBitmap);
	// ---------------------- ���浽ջ��----------------------
}

CMainFrame::~CMainFrame()
{
	//  ɾ��ջ�е�ͼƬ
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
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}
	
	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//  ����һ��NULL�˵�
	this->SetMenu(0);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style = WS_POPUP;   //  ȥ���߿�

	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������



void CMainFrame::OnAccelerator32778()
{
	if(sk.size() > 1)
	{
		//  ɾ�� ջ��
		delete sk.top();
		sk.pop();
		//  ֪ͨ��ͼ�ػ�
		GetActiveView()->SendMessage(WM_PAINT);
	}
}
