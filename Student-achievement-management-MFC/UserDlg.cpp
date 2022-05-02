// UserDlg.cpp : ʵ���ļ�
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


// CUserDlg ���

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


// CUserDlg ��Ϣ�������


void CUserDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CUserDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CUserDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�޸����빦��
	UpdateData(TRUE);//�õ�����ֵ
	CInfoFile file;
	CString name, pwd;
	file.ReadLogin(name, pwd);
	if (m_newPWD.IsEmpty())
	{
		MessageBox(TEXT("���������벻��Ϊ�գ�"));
	}
	else if(pwd==m_newPWD)
	{
		MessageBox(TEXT("�����벻���������һ�£�"));
	}
	else if (m_surePWD.IsEmpty())
	{
		MessageBox(TEXT("���ٴ��������룡"));
	}
	
	else if (m_newPWD != m_surePWD)//�������ȷ������Ҫһ��
	{
		MessageBox(TEXT("�������ȷ�����벻һ�£�"));
	}
	else 
	{
		//CString ת char*
		CStringA tmp;
		CStringA tmp2;
		tmp = name;
		tmp2 = m_newPWD;
		file.WritePwd(tmp.GetBuffer(), tmp2.GetBuffer());
		MessageBox(TEXT("�����޸ĳɹ�"));
		//�������
		m_newPWD.Empty();
		m_surePWD.Empty();
		UpdateData(FALSE);
	}
}


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	//��ʼ��
	CInfoFile file;
	m_user = TEXT("��ʦ");
	CString name, pwd;
	file.ReadLogin(name, pwd);
	m_name = name;
	UpdateData(FALSE);
	// TODO: �ڴ����ר�ô����/����û���
}


void CUserDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ȡ����ť
	//�������
	m_newPWD.Empty();
	m_surePWD.Empty();
	UpdateData(FALSE);
}
