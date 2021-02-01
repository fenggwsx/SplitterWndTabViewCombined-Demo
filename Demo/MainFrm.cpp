
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "Demo.h"

#include "MainFrm.h"

#include "IndexTreeView.h"
#include "View1.h"
#include "MyTabView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
	: m_pView1(NULL)
	, m_pMyTabView(NULL)
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators) / sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

void CMainFrame::Switch(int nIndex)
{
	switch (nIndex)
	{
	case 0:
		::SetWindowLong(m_pView1->m_hWnd, GWL_ID, m_wndSplitterWnd.IdFromRowCol(0,1));
		m_pView1->ShowWindow(SW_SHOW);
		::SetWindowLong(m_pMyTabView->m_hWnd, GWL_ID, 0xFFFF);
		m_pMyTabView->ShowWindow(SW_HIDE);
		break;
	case 1:
		::SetWindowLong(m_pView1->m_hWnd, GWL_ID, 0xFFFF);
		m_pView1->ShowWindow(SW_HIDE);
		::SetWindowLong(m_pMyTabView->m_hWnd, GWL_ID, m_wndSplitterWnd.IdFromRowCol(0, 1));
		m_pMyTabView->ShowWindow(SW_SHOW);
		break;
	}
	m_wndSplitterWnd.RecalcLayout();
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CFrameWnd::PreCreateWindow(cs))
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

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



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	m_wndSplitterWnd.CreateStatic(this, 1, 2);
	m_wndSplitterWnd.CreateView(0, 0, RUNTIME_CLASS(CIndexTreeView), CSize(200, 0), pContext);

	m_pView1 = DYNAMIC_DOWNCAST(CView1, RUNTIME_CLASS(CView1)->CreateObject());
	m_pMyTabView = DYNAMIC_DOWNCAST(CMyTabView, RUNTIME_CLASS(CMyTabView)->CreateObject());

	m_pView1->Create(NULL, NULL, WS_CHILD,
		CRect(0, 0, 0, 0), &m_wndSplitterWnd, 0xFFFF, pContext);
	m_pMyTabView->Create(NULL, NULL, WS_CHILD,
		CRect(0, 0, 0, 0), &m_wndSplitterWnd, 0xFFFF, pContext);

	Switch(0);

	return TRUE;
}
