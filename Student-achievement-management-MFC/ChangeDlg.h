#pragma once



// CChangeDlg ������ͼ

class CChangeDlg : public CFormView
{
	DECLARE_DYNCREATE(CChangeDlg)

protected:
	CChangeDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CChangeDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_CHANGE };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_num;
	CString m_name;
	int m_gradeChinese;
	int m_gradeMath;
	int m_gradeEnglish;
	CString m_newnum;
	CString m_newname;
	int m_newgradeChinese;
	int m_newgradeMath;
	int m_newgradeEnglish;
	afx_msg void OnBnClickedOk();
};


