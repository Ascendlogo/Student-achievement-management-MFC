
// Student-achievement-management-MFCView.h : CStudentachievementmanagementMFCView ��Ľӿ�
//

#pragma once


class CStudentachievementmanagementMFCView : public CView
{
protected: // �������л�����
	CStudentachievementmanagementMFCView();
	DECLARE_DYNCREATE(CStudentachievementmanagementMFCView)

// ����
public:
	CStudentachievementmanagementMFCDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CStudentachievementmanagementMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Student-achievement-management-MFCView.cpp �еĵ��԰汾
inline CStudentachievementmanagementMFCDoc* CStudentachievementmanagementMFCView::GetDocument() const
   { return reinterpret_cast<CStudentachievementmanagementMFCDoc*>(m_pDocument); }
#endif

