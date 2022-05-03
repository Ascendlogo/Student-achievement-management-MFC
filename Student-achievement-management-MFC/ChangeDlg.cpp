// ChangeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "ChangeDlg.h"
#include "InfoFile.h"


// CChangeDlg

IMPLEMENT_DYNCREATE(CChangeDlg, CFormView)

CChangeDlg::CChangeDlg()
	: CFormView(DIALOG_CHANGE)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_gradeChinese(0)
	, m_gradeMath(0)
	, m_gradeEnglish(0)
	, m_newnum(_T(""))
	, m_newname(_T(""))
	, m_newgradeChinese(0)
	, m_newgradeMath(0)
	, m_newgradeEnglish(0)
{

}

CChangeDlg::~CChangeDlg()
{
}

void CChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_gradeChinese);
	DDX_Text(pDX, IDC_EDIT4, m_gradeMath);
	DDX_Text(pDX, IDC_EDIT5, m_gradeEnglish);
	DDX_Text(pDX, IDC_EDIT6, m_newnum);
	DDX_Text(pDX, IDC_EDIT7, m_newname);
	DDX_Text(pDX, IDC_EDIT8, m_newgradeChinese);
	DDX_Text(pDX, IDC_EDIT9, m_newgradeMath);
	DDX_Text(pDX, IDC_EDIT10, m_newgradeEnglish);
}

BEGIN_MESSAGE_MAP(CChangeDlg, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CChangeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CChangeDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChangeDlg ���

#ifdef _DEBUG
void CChangeDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CChangeDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CChangeDlg ��Ϣ�������


void CChangeDlg::OnBnClickedButton1()
{
	CInfoFile file;
	file.ReadDocline(); //��ȡѧ����Ϣ
	CString str;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_num.IsEmpty())
	{
		MessageBox(TEXT("������ѧ��"));
	}
	else
	{
		list<CInfoFile::msg>::iterator it = file.ls.begin();
		for (; it != file.ls.end(); it++)
		{
			if ((CString)it->studentNumber.c_str() == m_num)
			{
				m_name = (CString)it->studentName.c_str();
				m_gradeChinese = it->gradeChinese;
				m_gradeMath = it->gradeMath;
				m_gradeEnglish = it->gradeEnglish;
				UpdateData(FALSE);
				break;
			}
		}
	if (it == file.ls.end())
		{
			MessageBox(TEXT("��ѧ��������"));
		}
	}
}


void CChangeDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInfoFile file;
	file.ReadDocline(); //��ȡѧ����Ϣ
	CString str;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_newname.IsEmpty() || m_newname.IsEmpty() || m_newgradeChinese>100 || m_newgradeChinese<0 || m_newgradeMath>100 || m_newgradeMath<0 || m_newgradeEnglish>100 || m_newgradeEnglish<0)
	{
		MessageBox(TEXT("����ȷ����ѧ����Ϣ"));
	}
	else if (m_num.IsEmpty())
	{
		MessageBox(TEXT("������ѧ��"));
	}
	else
	{
		list<CInfoFile::msg>::iterator it = file.ls.begin();
		CStringA str1,str2;
		for (; it != file.ls.end(); it++)
		{
			if ((CString)it->studentNumber.c_str() == m_num)
			{
				str1 = m_newname;
				it->studentName = str1.GetBuffer();
				str2 = m_newnum;
				it->studentNumber = str2.GetBuffer();
				it->gradeChinese = m_newgradeChinese;
				it->gradeMath = m_newgradeMath;
				it->gradeEnglish = m_newgradeEnglish;
				MessageBox(TEXT("�޸ĳɹ�"));
				file.WriteDocline();
				break;
			}
		}
		m_num.Empty();
		m_name.Empty();
		m_newnum.Empty();
		m_newname.Empty();
		m_gradeChinese = 0;
		m_gradeMath = 0;
		m_gradeEnglish = 0;
		m_newgradeChinese = 0;
		m_newgradeMath = 0;
		m_newgradeEnglish = 0;
		UpdateData(FALSE);
	}
}
