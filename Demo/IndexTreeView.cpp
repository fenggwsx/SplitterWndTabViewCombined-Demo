#include "pch.h"
#include "IndexTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CIndexTreeView, CTreeView)

BEGIN_MESSAGE_MAP(CIndexTreeView, CTreeView)
ON_WM_CREATE()
ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CIndexTreeView::OnTvnSelchanged)
END_MESSAGE_MAP()


CIndexTreeView::CIndexTreeView() noexcept
{
}


int CIndexTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;

	TVINSERTSTRUCT tvInsert;
	HTREEITEM hRootItem;

	tvInsert.hInsertAfter = NULL;

	tvInsert.hParent = TVI_ROOT;
	tvInsert.item.mask = LVFIF_TEXT;
	tvInsert.item.pszText = _T("Root");
	hRootItem = GetTreeCtrl().InsertItem(&tvInsert);

	GetTreeCtrl().InsertItem(_T("Node1"), hRootItem);
	GetTreeCtrl().InsertItem(_T("Node2"), hRootItem);

	GetTreeCtrl().Expand(hRootItem, TVE_EXPAND);

	return 0;
}


void CIndexTreeView::OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	HTREEITEM hRootItem = GetTreeCtrl().GetRootItem();
	HTREEITEM hCurItem = pNMTreeView->itemNew.hItem;
	if (hCurItem != hRootItem)
	{
		int nIndex = 0;
		HTREEITEM hItem = GetTreeCtrl().GetChildItem(hRootItem);
		while (hItem)
		{
			if (hItem == hCurItem)
				break;
			hItem = GetTreeCtrl().GetNextSiblingItem(hItem);
			nIndex++;
		}
		CMainFrame* pFrame = DYNAMIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
		if (pFrame != NULL)
		{
			pFrame->Switch(nIndex);
			pFrame->SetActiveView(this);
		}
		
	}
	*pResult = 0;
}


BOOL CIndexTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= TVS_SHOWSELALWAYS | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS;
	return CTreeView::PreCreateWindow(cs);
}
