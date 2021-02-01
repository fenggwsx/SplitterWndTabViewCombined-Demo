
// MainFrm.h: CMainFrame 类的接口
//

#pragma once

class CView1;
class CMyTabView;
class CMainFrame : public CFrameWnd
{

protected: // 仅从序列化创建
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

	// 特性
public:

	// 操作
public:
	void Switch(int nIndex);

	// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar m_wndToolBar;
	CStatusBar m_wndStatusBar;
	CSplitterWnd m_wndSplitterWnd;
	CView1* m_pView1;
	CMyTabView* m_pMyTabView;

	// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


