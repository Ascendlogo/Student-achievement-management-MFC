// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "UserDlg.h"
#include "InfoFile.h"

// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(IDD_USER)
	, m_user(_T(""))
	, m_name(_T(""))
	, m_newPWD(_T(""))
	, m_surePWD(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_newPWD);
	DDX_Text(pDX, IDC_EDIT2, m_surePWD);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &CUserDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CUserDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUserDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUserDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CUserDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//修改密码功能
	UpdateData(TRUE);//拿到最新值
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (m_newPWD.IsEmpty())
	{
		MessageBox(TEXT("新密码输入不能为空！"));
	}
	else if(pwd==m_newPWD)
	{
		MessageBox(TEXT("新密码不能与旧密码一致！"));
	}
	else if (m_surePWD.IsEmpty())
	{
		MessageBox(TEXT("请再次输入密码！"));
	}
	
	else if (m_newPWD != m_surePWD)//新密码和确定密码要一致
	{
		MessageBox(TEXT("新密码和确定密码不一致！"));
	}
	else 
	{
		//CString 转 char*
		CStringA tmp;
		CStringA tmp2;
		tmp = name;
		tmp2 = m_newPWD;
		file.WritePwd(tmp.GetBuffer(), tmp2.GetBuffer());
		MessageBox(TEXT("密码修改成功"));
		//清空内容
		m_newPWD.Empty();
		m_surePWD.Empty();
		UpdateData(FALSE);
	}
}


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//初始化
	CInfoFile file;
	m_user = TEXT("教师");
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_name = name;
	UpdateData(FALSE);
	// TODO: 在此添加专用代码和/或调用基类
}


void CUserDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//取消按钮
	//清空内容
	m_newPWD.Empty();
	m_surePWD.Empty();
	UpdateData(FALSE);
}
