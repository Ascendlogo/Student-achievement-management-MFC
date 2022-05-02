#pragma once



// CUserDlg 窗体视图

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CUserDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_user;
	afx_msg void OnEnChangeEdit1();
	CString m_name;
private:
	CString m_newPWD;
	CString m_surePWD;
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedButton2();
};


