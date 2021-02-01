#include "pch.h"
#include "View2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CView2, CView)


CView2::CView2() noexcept
{
}


void CView2::OnDraw(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(CString(GetThisClass()->m_lpszClassName), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
