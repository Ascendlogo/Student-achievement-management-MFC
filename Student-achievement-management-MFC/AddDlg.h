#pragma once



// CAddDlg ������ͼ

class CAddDlg : public CFormView
{
	DECLARE_DYNCREATE(CAddDlg)

protected:
	CAddDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CAddDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_ADD};
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
	CString m_stuNUM;
	CString m_stuNAME;
	int m_gradeChinese;
	afx_msg void OnEnChangeEdit4();
	int m_gradeMath;
	int m_gradeEnglish;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};


