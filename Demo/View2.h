#pragma once
class CView2 :
    public CView
{
protected:
	CView2() noexcept;
	DECLARE_DYNCREATE(CView2)
	virtual void OnDraw(CDC* pDC);
};

