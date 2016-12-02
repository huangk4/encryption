
// 紫英编码解密器Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "紫英编码解密器.h"
#include "紫英编码解密器Dlg.h"
#include "afxdialogex.h"
#include"base64.h"
#include"md5.h"
#include"凯撒.h"
#include"栅栏密码.h"
#include"摩斯解密.h"
#include"ASCbiao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	
END_MESSAGE_MAP()


// C紫英编码解密器Dlg 对话框



C紫英编码解密器Dlg::C紫英编码解密器Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C紫英编码解密器Dlg::IDD, pParent)
	, primary(_T(""))
	, ASC(_T(""))
	, Hex(_T(""))
	, URL(_T(""))
	, md5_16(_T(""))
	, md5_32(_T(""))
	, zhacode(_T(""))
	, num_lan(0)
	, kscode(_T(""))
	, mosi(_T(""))
	, SQL(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C紫英编码解密器Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, primary);
	DDX_Text(pDX, IDC_EDIT2, ASC);
	DDX_Text(pDX, IDC_EDIT3, Hex);
	DDX_Text(pDX, IDC_EDIT4, URL);
	DDX_Text(pDX, IDC_EDIT6, md5_16);
	DDX_Text(pDX, IDC_EDIT7, md5_32);
	DDX_Text(pDX, IDC_EDIT8, zhacode);
	DDX_Text(pDX, IDC_EDIT9, num_lan);
	DDX_Text(pDX, IDC_EDIT10, kscode);
	DDX_Text(pDX, IDC_EDIT11, mosi);
	DDX_Text(pDX, IDC_EDIT12, SQL);
}

BEGIN_MESSAGE_MAP(C紫英编码解密器Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C紫英编码解密器Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C紫英编码解密器Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C紫英编码解密器Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C紫英编码解密器Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &C紫英编码解密器Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C紫英编码解密器Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C紫英编码解密器Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &C紫英编码解密器Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &C紫英编码解密器Dlg::OnBnClickedButton9)
	ON_COMMAND(ID_32775, &C紫英编码解密器Dlg::On32775)
	ON_COMMAND(ID_32776, &C紫英编码解密器Dlg::OnExit)
	ON_COMMAND(ID_32777, &C紫英编码解密器Dlg::On32777)
	ON_COMMAND(ID_32774, &C紫英编码解密器Dlg::On32774)
	ON_COMMAND(ID_32771, &C紫英编码解密器Dlg::凯撒)
	ON_COMMAND(ID_32772, &C紫英编码解密器Dlg::栅栏)
	ON_COMMAND(ID_32773, &C紫英编码解密器Dlg::摩斯)
	ON_COMMAND(ID_32778, &C紫英编码解密器Dlg::ON计算器)
	ON_COMMAND(ID_32779, &C紫英编码解密器Dlg::OnASC)
END_MESSAGE_MAP()


// C紫英编码解密器Dlg 消息处理程序

BOOL C紫英编码解密器Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);//选上
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//不选上

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C紫英编码解密器Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C紫英编码解密器Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C紫英编码解密器Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C紫英编码解密器Dlg::OnBnClickedButton1()			//编码
{
	// TODO:  在此添加控件通知处理程序代码
	CString data,temp,asc,hex,url,md5_16,md5_32,base64_en,base64_de,sql;
	int a;												//data转换成十进制asc码值
	GetDlgItemText(IDC_EDIT1, data);
	int nSize = data.GetLength() * 2;
	hex += "0x"; sql += "0x";
	for (int i = 0; i < data.GetLength(); i++)
	{
		a = (int)data[i];		
		temp.Format(_T("%d"), a);					//asc码十进制值赋给temp
		asc += temp+' ';
		temp.Format(_T("%x"), a);					//asc码十六进制值赋给temp
		hex += temp;								
		url += '%'+temp;
		sql = sql + temp + _T("00");
	}
	SetDlgItemText(IDC_EDIT2, asc);
	SetDlgItemText(IDC_EDIT3, hex);
	SetDlgItemText(IDC_EDIT4, url);
	SetDlgItemText(IDC_EDIT12, sql);
	//////////////	MD5加密
	if (data.GetLength() > 64)
		md5_16 = md5_32 = _T("输入内容太大");
	else
	{
		char tmp[128];
		unsigned char digest[16];
		MD5_CTX context;
		memcpy(tmp, data, nSize);
		MD5Init(&context);
		MD5Update(&context, (unsigned char*)tmp, strlen(tmp));
		MD5Final(digest, &context);
		for (int i = 0; i < 16; ++i)
		{
			temp.Format(_T("%02X"), digest[i]);
			if (i<12 && i>3)
				md5_16 += temp;
			md5_32 += temp;
		}
	}
	SetDlgItemText(IDC_EDIT6, md5_16);
	SetDlgItemText(IDC_EDIT7, md5_32);

	//base64加解密
	int len = WideCharToMultiByte(CP_ACP, 0, data, nSize/2, NULL, 0, NULL, NULL);
	char *t=new char[len+1];
	WideCharToMultiByte(CP_ACP, 0, data, nSize / 2, t, len, NULL, NULL);
	t[len] = '\0';
	int i = 0;
	int j = strlen(t);
	char *enc = base64_encode(t, j);
	USES_CONVERSION;
	base64_en.Format(_T("%s"), A2W(enc));
	SetDlgItemText(IDC_EDIT5, base64_en);
	free(enc);
	//int lens = strlen(enc);
	//char *dec = base64_decode(enc, lens);
	//base64_en.Format(_T("%s"), dec);
	//SetDlgItemText(IDC_EDIT7, md5_32);
	//free(dec);
}


void C紫英编码解密器Dlg::OnBnClickedButton2()			//BASE64解码
{
	// TODO:  在此添加控件通知处理程序代码
	CString data,base64_de;
	GetDlgItemText(IDC_EDIT5, data);
	int nSize = data.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, data, nSize, NULL, 0, NULL, NULL);
	char *enc = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, data, nSize, enc, len, NULL, NULL);
	enc[len] = '\0';
	int lens = strlen(enc);
	char *dec = base64_decode(enc, lens);
	USES_CONVERSION;
	base64_de.Format(_T("%s"), A2W(dec));
	SetDlgItemText(IDC_EDIT1, base64_de);
	free(dec);
}


void C紫英编码解密器Dlg::OnBnClickedButton3()			//ASC值解码
{
	// TODO:  在此添加控件通知处理程序代码
	CString data, asc,temp;
	int num_asc;
	GetDlgItemText(IDC_EDIT2, data);
	data += ' ';										//首部补空格
	for (int i = 0;  i<data.GetLength(); i++)
	{
		if (data[i] != ' ')								//以空格作为分隔符
			temp += data[i];
		else
		{
			num_asc = _ttoi(temp);
			asc += char(num_asc);
			temp = _T('');
		}	
	}
	SetDlgItemText(IDC_EDIT1, asc);
}


void C紫英编码解密器Dlg::OnBnClickedButton4()			//栅栏密码解密
{
	// TODO:  在此添加控件通知处理程序代码
	CString code,clearcode;
	int lan;
	GetDlgItemText(IDC_EDIT8, code);
	lan=GetDlgItemInt(IDC_EDIT9);
	if (lan > code.GetLength() || lan <= 0)
	{
		MessageBox(_T("栏数不应大于密文长度或小于零"), 0, 0);
		return;
	}
	clearcode=zhalan(code, lan);
	SetDlgItemText(IDC_EDIT1, clearcode);

}


void C紫英编码解密器Dlg::OnBnClickedButton5()			//16进制解码
{
	// TODO:  在此添加控件通知处理程序代码
	CString data, hex, temp;
	int n_hex=0;
	wchar_t tranf;
	GetDlgItemText(IDC_EDIT3, data);
	data= data.Right(data.GetLength() - 2);
	if (data.GetLength() % 2 == 1)
		data = '0' + data;
	data.MakeUpper();
	for (int i = 0; i < data.GetLength(); i+=2)
	{
		if (data[i]>'9')
		{
			tranf = data[i];
			n_hex = (int(tranf) - 55) * 16;
		}
		else
		{
			temp = temp + data[i];
			n_hex = _ttoi(temp)*16;
			temp = _T('');
		}
		if (data[i+1]>'9')
		{
			tranf = data[i+1];
			n_hex += int(tranf) - 55;
		}
		else
		{
			temp = temp + data[i+1];
			n_hex += _ttoi(temp);
			temp = _T('');
		}
		hex += char(n_hex);
		
	}
	SetDlgItemText(IDC_EDIT1, hex);
}


void C紫英编码解密器Dlg::OnBnClickedButton6()				//URL解码
{
	// TODO:  在此添加控件通知处理程序代码
	CString data, url, temp;
	int num_url;
	wchar_t tranf;
	GetDlgItemText(IDC_EDIT4, data);
	for (int i = 0; i<data.GetLength(); i++)
	{
		if (data[i] == '%')
			continue;
		else
		{
			if (data[i]>'9')								//判断是否为A-F
			{
				tranf = data[i];
				num_url = (int(tranf) - 55) * 16;
			}
			else
			{
				temp = temp + data[i];
				num_url = _ttoi(temp) * 16;					//转换为10进制
				temp = _T('');
			}
			if (data[i + 1]>'9')
			{
				tranf = data[i + 1];
				num_url += int(tranf) - 55;
			}
			else
			{
				temp = temp + data[i + 1];
				num_url += _ttoi(temp);
				temp = _T('');
			}
			url += char(num_url);
			i++;
		}
	}
	SetDlgItemText(IDC_EDIT1, url);
}



int g_file_num = 0;
void C紫英编码解密器Dlg::OnBnClickedButton7()			//凯撒解密
{
	// TODO:  在此添加控件通知处理程序代码
	CString temp;
	temp.Format(_T("%d"), g_file_num++);
	BOOL isOpen = FALSE;        //是否打开(否则为保存)  
	CString defaultDir = L"D:\\";   //默认打开的文件路径  
	CString fileName = _T("code")+temp+_T(".txt");         //默认打开的文件名  
	CString filter = L"文件 (*.txt)|*.txt||";   //文件过虑的类型  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L"D:\\code.txt";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + "\\" + fileName;
	if (result == IDOK) {
		filePath = openFileDlg.GetPathName();
	}
	CString code;
	GetDlgItemText(IDC_EDIT10, code);
	if (((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
		kais(code, filePath);
	else kais3(code, filePath);
}


void C紫英编码解密器Dlg::OnBnClickedButton8()			//摩斯解密
{
	// TODO:  在此添加控件通知处理程序代码
	CString code,temp,clear;
	GetDlgItemText(IDC_EDIT11, code);										//首部补空格
	code += _T(' ');
	for (int i = 0; i<code.GetLength(); i++)
	{
		if (code[i] != ' ')								//以空格作为分隔符
		if (code[i] != '.'&&code[i] != '-')
		{
			MessageBoxW(_T("摩斯密文格式有误，请参看帮助"));
			return;
		}
		else temp += (char)code[i];
		else if (code[i + 1] != ' ')
		{
			clear+=Mosi(temp);
			temp = _T('');
		}
	}
	SetDlgItemText(IDC_EDIT1, clear);
}


void C紫英编码解密器Dlg::OnBnClickedButton9()		//SQL解码
{
	// TODO:  在此添加控件通知处理程序代码
	CString data, sql, temp;
	int n_sql = 0;
	wchar_t tranf;
	GetDlgItemText(IDC_EDIT12, data);
	data = data.Right(data.GetLength() - 2);
	if (data.GetLength() % 2 == 1)
		data = '0' + data;
	data.MakeUpper();
	for (int i = 0; i < data.GetLength(); i += 4)
	{
		if (data[i]>'9')
		{
			tranf = data[i];
			n_sql = (int(tranf) - 55) * 16;
		}
		else
		{
			temp = temp + data[i];
			n_sql = _ttoi(temp) * 16;
			temp = _T('');
		}
		if (data[i + 1]>'9')
		{
			tranf = data[i + 1];
			n_sql += int(tranf) - 55;
		}
		else
		{
			temp = temp + data[i + 1];
			n_sql += _ttoi(temp);
			temp = _T('');
		}
		sql += char(n_sql);

	}
	SetDlgItemText(IDC_EDIT1, sql);
}



void C紫英编码解密器Dlg::On32775()
{
	// TODO:  在此添加命令处理程序代码
	CString clear=_T('');
	SetDlgItemText(IDC_EDIT1, clear);
	SetDlgItemText(IDC_EDIT2, clear);
	SetDlgItemText(IDC_EDIT3, clear);
	SetDlgItemText(IDC_EDIT4, clear);
	SetDlgItemText(IDC_EDIT5, clear);
	SetDlgItemText(IDC_EDIT6, clear);
	SetDlgItemText(IDC_EDIT7, clear);
	SetDlgItemText(IDC_EDIT8, clear);
	SetDlgItemText(IDC_EDIT9, clear);
	SetDlgItemText(IDC_EDIT10, clear);
	SetDlgItemText(IDC_EDIT11, clear);
	SetDlgItemText(IDC_EDIT12, clear);
}


void C紫英编码解密器Dlg::OnExit()
{
	// TODO:  在此添加命令处理程序代码
	DestroyWindow();
}


void C紫英编码解密器Dlg::On32777()
{
	// TODO:  在此添加命令处理程序代码
	MessageBoxW(_T("作者庆哥，未经授权不得做商业用途"));
}


void C紫英编码解密器Dlg::On32774()
{
	// TODO:  在此添加命令处理程序代码
	MessageBoxW(_T("解码时请以空格分开"));
}


void C紫英编码解密器Dlg::凯撒()
{
	// TODO:  在此添加命令处理程序代码
	MessageBoxW(_T("将密文输入后选择解密后文件保存位置，然后打开查看即可"));
}


void C紫英编码解密器Dlg::栅栏()
{
	// TODO:  在此添加命令处理程序代码
	MessageBoxW(_T("解密前请输入栏数分栏"));
}


void C紫英编码解密器Dlg::摩斯()
{
	// TODO:  在此添加命令处理程序代码
	MessageBoxW(_T("密文格式为“.”和“-”的形式，并以空格作为每串密码的分隔"));
}


void C紫英编码解密器Dlg::ON计算器()
{
	// TODO:  在此添加命令处理程序代码
	WinExec("calc.exe", SW_SHOW);
}


void C紫英编码解密器Dlg::OnASC()
{
	// TODO:  在此添加命令处理程序代码
	ASCbiao one;
	one.DoModal();
}
