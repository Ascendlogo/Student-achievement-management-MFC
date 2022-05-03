
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "Student-achievement-management-MFC.h"
#include "SelectView.h"
#include "DisplayView.h"
#include "MainFrm.h"
#include "UserDlg.h"
#include "AddDlg.h"
#include "InfoDlg.h"
#include "ChangeDlg.h"
#include "DeleteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	//ON_MESSAGE��Ӧ�����Զ�����Ϣ
	//����NM_X��Ϣ���Զ�����OnMyChange����
	ON_MESSAGE(NM_A, OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)

END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	//����ͼ�꣬IDI_ICON_WINΪͼ����ԴID����ΪWINAPI����
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//���ô��ڵ�λ�úʹ�С:CWnd::MOveWindow
	MoveWindow(0, 0, 800, 600);
	CenterWindow();
	return 0;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
	m_spliter.CreateStatic(this, 1, 2);//��ֳ�1��2��
	//�����Ҳ������ʾ����
	m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500),pContext);
	m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDisplayView), CSize(450, 500), pContext);
	return true;//�Լ����
}

LRESULT CMainFrame::OnMyChange(WPARAM wParam, LPARAM lParam)
{
	CCreateContext   Context;
	if (wParam == NM_A)
	{
		//MessageBox(TEXT("������Ϣ�������"));
		//�������
		Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600, 500), &Context);
		CUserDlg *pNewView = (CUserDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);

	}
	else if (wParam == NM_B)
	{
		//MessageBox(TEXT("��ӳɼ��������"));
		Context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(600, 500), &Context);
		CAddDlg *pNewView = (CAddDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_E)
	{
		//��ʾȫ���ɼ��������
		Context.m_pNewViewClass = RUNTIME_CLASS(CInfoDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CInfoDlg), CSize(600, 0), &Context);
		CInfoDlg *pNewView = (CInfoDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_C)
	{
		//�޸�ѧ���������
		Context.m_pNewViewClass = RUNTIME_CLASS(CChangeDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CChangeDlg), CSize(600, 0), &Context);
		CChangeDlg *pNewView = (CChangeDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	else if (wParam == NM_D)
	{
		//ɾ��ѧ���������
		Context.m_pNewViewClass = RUNTIME_CLASS(CDeleteDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDeleteDlg), CSize(600, 0), &Context);
		CDeleteDlg *pNewView = (CDeleteDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
	return 0;
}
