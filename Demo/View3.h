#pragma once
class CView3 :
    public CView
{
protected:
	CView3() noexcept;
	DECLARE_DYNCREATE(CView3)
	virtual void OnDraw(CDC* pDC);
protected:
	CSplitterWnd m_wndSplitterWnd;
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

