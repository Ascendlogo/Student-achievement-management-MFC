
// Student-achievement-management-MFCView.cpp : CStudentachievementmanagementMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Student-achievement-management-MFC.h"
#endif

#include "Student-achievement-management-MFCDoc.h"
#include "Student-achievement-management-MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentachievementmanagementMFCView

IMPLEMENT_DYNCREATE(CStudentachievementmanagementMFCView, CView)

BEGIN_MESSAGE_MAP(CStudentachievementmanagementMFCView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudentachievementmanagementMFCView ����/����

CStudentachievementmanagementMFCView::CStudentachievementmanagementMFCView()
{
	// TODO: �ڴ˴���ӹ������

}

CStudentachievementmanagementMFCView::~CStudentachievementmanagementMFCView()
{
}

BOOL CStudentachievementmanagementMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CStudentachievementmanagementMFCView ����

void CStudentachievementmanagementMFCView::OnDraw(CDC* /*pDC*/)
{
	CStudentachievementmanagementMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CStudentachievementmanagementMFCView ��ӡ

BOOL CStudentachievementmanagementMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CStudentachievementmanagementMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CStudentachievementmanagementMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CStudentachievementmanagementMFCView ���

#ifdef _DEBUG
void CStudentachievementmanagementMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentachievementmanagementMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentachievementmanagementMFCDoc* CStudentachievementmanagementMFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentachievementmanagementMFCDoc)));
	return (CStudentachievementmanagementMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentachievementmanagementMFCView ��Ϣ�������
