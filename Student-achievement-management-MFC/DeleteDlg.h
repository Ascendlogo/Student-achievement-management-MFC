#pragma once



// CDeleteDlg 窗体视图

class CDeleteDlg : public CFormView
{
	DECLARE_DYNCREATE(CDeleteDlg)

protected:
	CDeleteDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CDeleteDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_Delete };
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
	CString m_num;
	CString m_name;
	int m_gradeChinese;
	int m_gradeMath;
	int m_gradeEnglish;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};


