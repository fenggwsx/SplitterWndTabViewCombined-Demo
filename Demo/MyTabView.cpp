#include "pch.h"
#include "MyTabView.h"
#include "View2.h"
#include "View3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMyTabView, CTabView)


CMyTabView::CMyTabView() noexcept
{
}
BEGIN_MESSAGE_MAP(CMyTabView, CTabView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


int CMyTabView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTabView::OnCreate(lpCreateStruct) == -1)
		return -1;

	GetTabControl().SetLocation(CMFCTabCtrl::LOCATION_TOP);
	GetTabControl().ModifyTabStyle(CMFCTabCtrl::STYLE_FLAT);

	CCreateContext context;
	context.m_pCurrentDoc = GetDocument();
	context.m_pCurrentFrame = NULL;
	context.m_pLastView = NULL;
	context.m_pNewDocTemplate = NULL;
	context.m_pNewViewClass = NULL;

	AddView(RUNTIME_CLASS(CView2), CString(RUNTIME_CLASS(CView2)->m_lpszClassName), -1, &context);
	AddView(RUNTIME_CLASS(CView3), CString(RUNTIME_CLASS(CView3)->m_lpszClassName), -1, &context);

	return 0;
}
