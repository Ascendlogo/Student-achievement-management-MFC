// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T("李四"))
	, m_pwd(_T("123456"))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_user_EDIT, m_user);
	DDX_Text(pDX, IDC_PWD_EDIT, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_PWD_EDIT, &CLoginDlg::OnEnChangePwdEdit)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_user = TEXT("秦亚东");//用户名
	m_pwd = TEXT("123456");//密码
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}




void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);//更新控件数据到对应的变量
	if (m_user.IsEmpty())
	{
		MessageBox(TEXT("用户名输入不能为空"));
	}
	else if(m_pwd.IsEmpty())
	{
		MessageBox(TEXT("密码输入不能为空"));
	}
	else
	{
		CInfoFile file;
		CString user,pwd;
		file.ReadLogin(user, pwd);
		if (m_user == user)
		{
			if (m_pwd != pwd)
			{
				MessageBox(TEXT("密码错误"));
				m_user.Empty();//清空
				m_pwd.Empty();
			}
			else
			{
				CDialogEx::OnCancel();
			}
		}
		else
		{
			MessageBox(TEXT("请输入正确的用户名"));
			m_user.Empty();//清空
			m_pwd.Empty();
		}
	}
	
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}


void CLoginDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
	CLoginDlg::OnBnClickedButton1();
}


void CLoginDlg::OnEnChangePwdEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
