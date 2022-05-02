// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T("���Ƕ�"))
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


// CLoginDlg ��Ϣ�������


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_user = TEXT("���Ƕ�");//�û���
	m_pwd = TEXT("123456");//����
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}




void CLoginDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);//���¿ؼ����ݵ���Ӧ�ı���
	if (m_user.IsEmpty())
	{
		MessageBox(TEXT("�û������벻��Ϊ��"));
	}
	else if(m_pwd.IsEmpty())
	{
		MessageBox(TEXT("�������벻��Ϊ��"));
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
				MessageBox(TEXT("�������"));
				m_user.Empty();//���
				m_pwd.Empty();
			}
			else
			{
				CDialogEx::OnCancel();
			}
		}
		else
		{
			MessageBox(TEXT("��������ȷ���û���"));
			m_user.Empty();//���
			m_pwd.Empty();
		}
	}
	
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}


void CLoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(0);
	CDialogEx::OnClose();
}


void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
	CLoginDlg::OnBnClickedButton1();
}


void CLoginDlg::OnEnChangePwdEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
