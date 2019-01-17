
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include <stack>
using namespace std;


class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
public:
	int m_nScreenCX;
	int m_nScreenCY;
	stack<CBitmap*> sk;   //  装图片
public:
	afx_msg void OnToolbarQuit();
	afx_msg void OnAccelerator32778();
	afx_msg void OnSave();
};


