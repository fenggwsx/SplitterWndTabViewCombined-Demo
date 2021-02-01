#pragma once
class CMyTabView :
    public CTabView
{
protected: // 仅从序列化创建
	CMyTabView() noexcept;
	DECLARE_DYNCREATE(CMyTabView)
public:
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

