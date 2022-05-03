// DeleteDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "DeleteDlg.h"
#include "InfoFile.h"


// CDeleteDlg

IMPLEMENT_DYNCREATE(CDeleteDlg, CFormView)

CDeleteDlg::CDeleteDlg()
	: CFormView(DIALOG_Delete)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_gradeChinese(0)
	, m_gradeMath(0)
	, m_gradeEnglish(0)
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_num);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_gradeChinese);
	DDX_Text(pDX, IDC_EDIT4, m_gradeMath);
	DDX_Text(pDX, IDC_EDIT5, m_gradeEnglish);
}

BEGIN_MESSAGE_MAP(CDeleteDlg, CFormView)
	ON_BN_CLICKED(IDOK, &CDeleteDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteDlg 诊断

#ifdef _DEBUG
void CDeleteDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDeleteDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG



bool operator ==(const  CInfoFile::msg& msg1, const CInfoFile::msg& msg2)
{
	bool flag = false;
	if (msg1.studentNumber == msg2.studentNumber&&msg1.studentName==msg2.studentName&&msg1.gradeChinese==msg2.gradeChinese&&msg1.gradeEnglish==msg2.gradeEnglish&&msg1.gradeMath==msg2.gradeMath)flag = true;
	return flag;

}
// CDeleteDlg 消息处理程序
void CDeleteDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CInfoFile file;
	file.ReadDocline(); //读取学生信息
	CString str;
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_num.IsEmpty())
	{
		MessageBox(TEXT("请填入学号"));
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
			MessageBox(TEXT("该学生不存在"));
		}
	}
}


void CDeleteDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CInfoFile file;
	file.ReadDocline(); //读取学生信息
	CString str;
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_num.IsEmpty())
	{
		MessageBox(TEXT("请填入学号"));
	}
	else
	{
		list<CInfoFile::msg>::iterator it = file.ls.begin();
		CInfoFile::msg temp;
		CStringA str1, str2;
		for (; it != file.ls.end(); it++)
		{
			if ((CString)it->studentNumber.c_str() == m_num)
			{
				str1 = m_num;
				temp.studentNumber = str1.GetBuffer();
				str2 = m_name;
				temp.studentName = str2.GetBuffer();
				temp.gradeChinese = m_gradeChinese;
				temp.gradeEnglish = m_gradeEnglish;
				temp.gradeMath = m_gradeMath;
				file.ls.remove(temp);
				MessageBox(TEXT("成功删除"));
				m_num.Empty();
				m_name.Empty();
				m_gradeChinese = 0;
				m_gradeMath = 0;
				m_gradeEnglish = 0;
				UpdateData(FALSE);
				file.WriteDocline();
				break;
			}
		}
	}
}
