#pragma once



// CDeleteDlg ������ͼ

class CDeleteDlg : public CFormView
{
	DECLARE_DYNCREATE(CDeleteDlg)

protected:
	CDeleteDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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


