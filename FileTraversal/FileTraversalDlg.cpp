
// FileTraversalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileTraversal.h"
#include "FileTraversalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileTraversalDlg �Ի���




CFileTraversalDlg::CFileTraversalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileTraversalDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileTraversalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileTraversalDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CFileTraversalDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CFileTraversalDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BFILETEST, &CFileTraversalDlg::OnBnClickedBfiletest)
END_MESSAGE_MAP()


// CFileTraversalDlg ��Ϣ�������

BOOL CFileTraversalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFileTraversalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFileTraversalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileTraversalDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	exit(0);
}


void CFileTraversalDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
	exit(0);
}


void CFileTraversalDlg::OnBnClickedBfiletest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strDirPath=_T("d:\\filetest");
	if(PathFileExists(strDirPath))//�ж��ļ�·���Ƿ����
	{
		SetCurrentDirectory(strDirPath);//���õ�ǰĿ¼
		FindFile(strDirPath);
	}
}

void CFileTraversalDlg::FindFile(CString Curdir)
{
	CFileFind  finder;
    BOOL bWorking = finder.FindFile(_T("*.*"));
    while(bWorking)
    {
		bWorking = finder.FindNextFile();
        if(finder.IsDirectory()&&!finder.IsDots())//�ļ���
		{
			CString oldDir;//����ԭʼ�ĵ�ǰ·��
            GetCurrentDirectory(50,(LPTSTR)(LPCTSTR)oldDir);//��ȡ��ǰ·��
			SetCurrentDirectory(finder.GetFilePath());
			FindFile(finder.GetFilePath());//�����������ļ���
			SetCurrentDirectory((LPCTSTR)oldDir);//�ָ���ǰĿ¼
		}
        else if(!finder.IsDirectory())//�ļ�
		{
			CString FileName=finder.GetFileName();
			int Where=FileName.ReverseFind('//');
            if(Where==-1)
            {
                Where=FileName.ReverseFind('/');
            }
            CString FileTitle=FileName.Right(FileName.GetLength()-1-Where);
            int Which=FileTitle.ReverseFind('.');
            CString ExtendName=FileTitle.Right(FileTitle.GetLength()-Which-1);
			if(ExtendName=="txt")
			{
				AfxMessageBox(finder.GetFilePath(),MB_OK,NULL);//�˴�ΪҪ����Ĵ���
			}
		}
    }
	finder.Close();
}