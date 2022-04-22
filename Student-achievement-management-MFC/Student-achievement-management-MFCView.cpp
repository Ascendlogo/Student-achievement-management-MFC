
// Student-achievement-management-MFCView.cpp : CStudentachievementmanagementMFCView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStudentachievementmanagementMFCView 构造/析构

CStudentachievementmanagementMFCView::CStudentachievementmanagementMFCView()
{
	// TODO: 在此处添加构造代码

}

CStudentachievementmanagementMFCView::~CStudentachievementmanagementMFCView()
{
}

BOOL CStudentachievementmanagementMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CStudentachievementmanagementMFCView 绘制

void CStudentachievementmanagementMFCView::OnDraw(CDC* /*pDC*/)
{
	CStudentachievementmanagementMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CStudentachievementmanagementMFCView 打印

BOOL CStudentachievementmanagementMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CStudentachievementmanagementMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CStudentachievementmanagementMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CStudentachievementmanagementMFCView 诊断

#ifdef _DEBUG
void CStudentachievementmanagementMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CStudentachievementmanagementMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStudentachievementmanagementMFCDoc* CStudentachievementmanagementMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentachievementmanagementMFCDoc)));
	return (CStudentachievementmanagementMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentachievementmanagementMFCView 消息处理程序
