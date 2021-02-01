#pragma once
class CView1 :
    public CView
{
protected:
	CView1() noexcept;
	DECLARE_DYNCREATE(CView1)
	virtual void OnDraw(CDC* pDC);
};

