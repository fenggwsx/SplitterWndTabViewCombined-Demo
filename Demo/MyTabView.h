#pragma once
class CMyTabView :
    public CTabView
{
protected: // �������л�����
	CMyTabView() noexcept;
	DECLARE_DYNCREATE(CMyTabView)
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

