
// Student-achievement-management-MFC.h : Student-achievement-management-MFC Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CStudentachievementmanagementMFCApp:
// �йش����ʵ�֣������ Student-achievement-management-MFC.cpp
//

class CStudentachievementmanagementMFCApp : public CWinApp
{
public:
	CStudentachievementmanagementMFCApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStudentachievementmanagementMFCApp theApp;
