
// ��Ӣ���������Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C��Ӣ���������Dlg �Ի���
class C��Ӣ���������Dlg : public CDialogEx
{
// ����
public:
	C��Ӣ���������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString primary;
	CString ASC;
	CString Hex;
	afx_msg void OnBnClickedButton1();
	CString URL;
	CString md5_16;
	CString md5_32;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CString zhacode;
	int num_lan;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CString kscode;
	afx_msg void OnBnClickedButton7();
	CString mosi;
	afx_msg void OnBnClickedButton8();
	CString SQL;
	afx_msg void OnBnClickedButton9();
	afx_msg void On32775();
	afx_msg void OnExit();
	afx_msg void On32777();
	afx_msg void On32774();
	afx_msg void ����();
	afx_msg void դ��();
	afx_msg void Ħ˹();
	afx_msg void ON������();
	afx_msg void OnASC();
};
