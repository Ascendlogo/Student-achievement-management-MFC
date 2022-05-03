// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "AddDlg.h"
#include "InfoFile.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(DIALOG_ADD)
	, m_stuNUM(_T(""))
	, m_stuNAME(_T(""))
	, m_gradeChinese(0)
	, m_gradeMath(0)
	, m_gradeEnglish(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_stuNUM);
	DDX_Text(pDX, IDC_EDIT1, m_stuNAME);
	DDX_Text(pDX, IDC_EDIT2, m_gradeChinese);
	DDX_Text(pDX, IDC_EDIT3, m_gradeMath);
	DDX_Text(pDX, IDC_EDIT5, m_gradeEnglish);
}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_EN_CHANGE(IDC_EDIT4, &CAddDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDOK, &CAddDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CAddDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CAddDlg 诊断

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg 消息处理程序


void CAddDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE); //获取控件内容
	CInfoFile file;
	if (m_stuNAME.IsEmpty() || m_stuNAME.IsEmpty() || m_gradeChinese>100 || m_gradeChinese<0 || m_gradeMath>100||m_gradeMath<0||m_gradeEnglish>100||m_gradeEnglish<0)
	{
		MessageBox(TEXT("请正确输入学生信息"));
	}
	else
	{
		file.ReadDocline(); //读取学生成绩
		file.Addline(m_stuNUM,m_stuNAME,m_gradeChinese,m_gradeMath,m_gradeEnglish); //添加学生成绩
		file.WriteDocline(); //写文件
		file.ls.clear(); //清空list的内容
		MessageBox(_T("添加成功"));
	}
	
}


void CAddDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
