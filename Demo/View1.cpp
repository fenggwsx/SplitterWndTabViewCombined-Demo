#include "pch.h"
#include "View1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CView1, CView)


CView1::CView1() noexcept
{
}


void CView1::OnDraw(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(CString(GetThisClass()->m_lpszClassName), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}
