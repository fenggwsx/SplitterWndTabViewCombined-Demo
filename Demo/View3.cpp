#include "pch.h"
#include "View3.h"
#include "View1.h"
#include "View2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CView3, CView)

BEGIN_MESSAGE_MAP(CView3, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


CView3::CView3() noexcept
{
}


void CView3::OnDraw(CDC* pDC)
{
}


int CView3::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CCreateContext context;
	context.m_pCurrentDoc = GetDocument();
	context.m_pCurrentFrame = NULL;
	context.m_pLastView = NULL;
	context.m_pNewDocTemplate = NULL;
	context.m_pNewViewClass = NULL;

	m_wndSplitterWnd.CreateStatic(this, 2, 1);
	m_wndSplitterWnd.CreateView(0, 0, RUNTIME_CLASS(CView1), CSize(0, 0), &context);
	m_wndSplitterWnd.CreateView(1, 0, RUNTIME_CLASS(CView2), CSize(0, 0), &context);

	return 0;
}


void CView3::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	CRect rect;
	GetClientRect(&rect);

	if (m_wndSplitterWnd.GetSafeHwnd() != NULL)
	{
		m_wndSplitterWnd.MoveWindow(&rect);
		m_wndSplitterWnd.SetRowInfo(0, cy / 2, 0);
		m_wndSplitterWnd.RecalcLayout();
	}
}
