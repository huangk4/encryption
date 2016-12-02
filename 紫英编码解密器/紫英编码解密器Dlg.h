
// 紫英编码解密器Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C紫英编码解密器Dlg 对话框
class C紫英编码解密器Dlg : public CDialogEx
{
// 构造
public:
	C紫英编码解密器Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	afx_msg void 凯撒();
	afx_msg void 栅栏();
	afx_msg void 摩斯();
	afx_msg void ON计算器();
	afx_msg void OnASC();
};
