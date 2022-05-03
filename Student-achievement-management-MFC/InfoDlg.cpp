// InfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "InfoDlg.h"
#include "InfoFile.h"


// CInfoDlg

IMPLEMENT_DYNCREATE(CInfoDlg, CFormView)

CInfoDlg::CInfoDlg()
	: CFormView(DIALOG_INFO)
{

}

CInfoDlg::~CInfoDlg()
{
}

void CInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CInfoDlg, CFormView)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CInfoDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CInfoDlg ���

#ifdef _DEBUG
void CInfoDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInfoDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInfoDlg ��Ϣ�������


void CInfoDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	// ������չ���
	//LVS_EX_FULLROWSELECTѡ�����У�LVS_EX_GRIDLINES����
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// ��ʼ����ͷ
	CString field[] = { _T("ѧ��"), _T("����"), _T("���ĳɼ�"), _T("��ѧ�ɼ�"), _T("Ӣ��ɼ�") };
	for (int i = 0; i < sizeof(field) / sizeof(field[0]); ++i)
	{
		m_list.InsertColumn(i, field[i], LVCFMT_CENTER, 90);
	}

	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ

	//�������
	int i = 0;
	CString str;
	for (list<CInfoFile::msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		int column = 0;
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, column++, (CString)it->studentNumber.c_str());
		m_list.SetItemText(i, column++, (CString)it->studentName.c_str());
		str.Format(_T("%d"), it->gradeChinese);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%d"), it->gradeMath);
		m_list.SetItemText(i, column++, str);
		str.Format(_T("%d"), it->gradeEnglish);
		m_list.SetItemText(i, column++, str);
		i++;
	}


	// TODO: �ڴ����ר�ô����/����û���
}


void CInfoDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
