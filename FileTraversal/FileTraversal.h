
// FileTraversal.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFileTraversalApp:
// �йش����ʵ�֣������ FileTraversal.cpp
//

class CFileTraversalApp : public CWinApp
{
public:
	CFileTraversalApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFileTraversalApp theApp;