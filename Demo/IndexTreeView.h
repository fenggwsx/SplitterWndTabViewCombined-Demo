#pragma once
class CIndexTreeView :
    public CTreeView
{
protected:
	CIndexTreeView() noexcept;
	DECLARE_DYNCREATE(CIndexTreeView)
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTvnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};

