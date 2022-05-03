// AddDlg.cpp : ʵ���ļ�
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


// CAddDlg ���

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


// CAddDlg ��Ϣ�������


void CAddDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE); //��ȡ�ؼ�����
	CInfoFile file;
	if (m_stuNAME.IsEmpty() || m_stuNAME.IsEmpty() || m_gradeChinese>100 || m_gradeChinese<0 || m_gradeMath>100||m_gradeMath<0||m_gradeEnglish>100||m_gradeEnglish<0)
	{
		MessageBox(TEXT("����ȷ����ѧ����Ϣ"));
	}
	else
	{
		file.ReadDocline(); //��ȡѧ���ɼ�
		file.Addline(m_stuNUM,m_stuNAME,m_gradeChinese,m_gradeMath,m_gradeEnglish); //���ѧ���ɼ�
		file.WriteDocline(); //д�ļ�
		file.ls.clear(); //���list������
		MessageBox(_T("��ӳɹ�"));
	}
	
}


void CAddDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
