
// ��Ӣ���������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��Ӣ���������.h"
#include "��Ӣ���������Dlg.h"
#include "afxdialogex.h"
#include"base64.h"
#include"md5.h"
#include"����.h"
#include"դ������.h"
#include"Ħ˹����.h"
#include"ASCbiao.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C��Ӣ���������Dlg �Ի���



C��Ӣ���������Dlg::C��Ӣ���������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��Ӣ���������Dlg::IDD, pParent)
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

void C��Ӣ���������Dlg::DoDataExchange(CDataExchange* pDX)
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

BEGIN_MESSAGE_MAP(C��Ӣ���������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &C��Ӣ���������Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C��Ӣ���������Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C��Ӣ���������Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C��Ӣ���������Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &C��Ӣ���������Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C��Ӣ���������Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C��Ӣ���������Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &C��Ӣ���������Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &C��Ӣ���������Dlg::OnBnClickedButton9)
	ON_COMMAND(ID_32775, &C��Ӣ���������Dlg::On32775)
	ON_COMMAND(ID_32776, &C��Ӣ���������Dlg::OnExit)
	ON_COMMAND(ID_32777, &C��Ӣ���������Dlg::On32777)
	ON_COMMAND(ID_32774, &C��Ӣ���������Dlg::On32774)
	ON_COMMAND(ID_32771, &C��Ӣ���������Dlg::����)
	ON_COMMAND(ID_32772, &C��Ӣ���������Dlg::դ��)
	ON_COMMAND(ID_32773, &C��Ӣ���������Dlg::Ħ˹)
	ON_COMMAND(ID_32778, &C��Ӣ���������Dlg::ON������)
	ON_COMMAND(ID_32779, &C��Ӣ���������Dlg::OnASC)
END_MESSAGE_MAP()


// C��Ӣ���������Dlg ��Ϣ�������

BOOL C��Ӣ���������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);//ѡ��
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);//��ѡ��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��Ӣ���������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C��Ӣ���������Dlg::OnPaint()
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
HCURSOR C��Ӣ���������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��Ӣ���������Dlg::OnBnClickedButton1()			//����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString data,temp,asc,hex,url,md5_16,md5_32,base64_en,base64_de,sql;
	int a;												//dataת����ʮ����asc��ֵ
	GetDlgItemText(IDC_EDIT1, data);
	int nSize = data.GetLength() * 2;
	hex += "0x"; sql += "0x";
	for (int i = 0; i < data.GetLength(); i++)
	{
		a = (int)data[i];		
		temp.Format(_T("%d"), a);					//asc��ʮ����ֵ����temp
		asc += temp+' ';
		temp.Format(_T("%x"), a);					//asc��ʮ������ֵ����temp
		hex += temp;								
		url += '%'+temp;
		sql = sql + temp + _T("00");
	}
	SetDlgItemText(IDC_EDIT2, asc);
	SetDlgItemText(IDC_EDIT3, hex);
	SetDlgItemText(IDC_EDIT4, url);
	SetDlgItemText(IDC_EDIT12, sql);
	//////////////	MD5����
	if (data.GetLength() > 64)
		md5_16 = md5_32 = _T("��������̫��");
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

	//base64�ӽ���
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


void C��Ӣ���������Dlg::OnBnClickedButton2()			//BASE64����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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


void C��Ӣ���������Dlg::OnBnClickedButton3()			//ASCֵ����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString data, asc,temp;
	int num_asc;
	GetDlgItemText(IDC_EDIT2, data);
	data += ' ';										//�ײ����ո�
	for (int i = 0;  i<data.GetLength(); i++)
	{
		if (data[i] != ' ')								//�Կո���Ϊ�ָ���
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


void C��Ӣ���������Dlg::OnBnClickedButton4()			//դ���������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString code,clearcode;
	int lan;
	GetDlgItemText(IDC_EDIT8, code);
	lan=GetDlgItemInt(IDC_EDIT9);
	if (lan > code.GetLength() || lan <= 0)
	{
		MessageBox(_T("������Ӧ�������ĳ��Ȼ�С����"), 0, 0);
		return;
	}
	clearcode=zhalan(code, lan);
	SetDlgItemText(IDC_EDIT1, clearcode);

}


void C��Ӣ���������Dlg::OnBnClickedButton5()			//16���ƽ���
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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


void C��Ӣ���������Dlg::OnBnClickedButton6()				//URL����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
			if (data[i]>'9')								//�ж��Ƿ�ΪA-F
			{
				tranf = data[i];
				num_url = (int(tranf) - 55) * 16;
			}
			else
			{
				temp = temp + data[i];
				num_url = _ttoi(temp) * 16;					//ת��Ϊ10����
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
void C��Ӣ���������Dlg::OnBnClickedButton7()			//��������
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString temp;
	temp.Format(_T("%d"), g_file_num++);
	BOOL isOpen = FALSE;        //�Ƿ��(����Ϊ����)  
	CString defaultDir = L"D:\\";   //Ĭ�ϴ򿪵��ļ�·��  
	CString fileName = _T("code")+temp+_T(".txt");         //Ĭ�ϴ򿪵��ļ���  
	CString filter = L"�ļ� (*.txt)|*.txt||";   //�ļ����ǵ�����  
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


void C��Ӣ���������Dlg::OnBnClickedButton8()			//Ħ˹����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString code,temp,clear;
	GetDlgItemText(IDC_EDIT11, code);										//�ײ����ո�
	code += _T(' ');
	for (int i = 0; i<code.GetLength(); i++)
	{
		if (code[i] != ' ')								//�Կո���Ϊ�ָ���
		if (code[i] != '.'&&code[i] != '-')
		{
			MessageBoxW(_T("Ħ˹���ĸ�ʽ������ο�����"));
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


void C��Ӣ���������Dlg::OnBnClickedButton9()		//SQL����
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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



void C��Ӣ���������Dlg::On32775()
{
	// TODO:  �ڴ���������������
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


void C��Ӣ���������Dlg::OnExit()
{
	// TODO:  �ڴ���������������
	DestroyWindow();
}


void C��Ӣ���������Dlg::On32777()
{
	// TODO:  �ڴ���������������
	MessageBoxW(_T("������磬δ����Ȩ��������ҵ��;"));
}


void C��Ӣ���������Dlg::On32774()
{
	// TODO:  �ڴ���������������
	MessageBoxW(_T("����ʱ���Կո�ֿ�"));
}


void C��Ӣ���������Dlg::����()
{
	// TODO:  �ڴ���������������
	MessageBoxW(_T("�����������ѡ����ܺ��ļ�����λ�ã�Ȼ��򿪲鿴����"));
}


void C��Ӣ���������Dlg::դ��()
{
	// TODO:  �ڴ���������������
	MessageBoxW(_T("����ǰ��������������"));
}


void C��Ӣ���������Dlg::Ħ˹()
{
	// TODO:  �ڴ���������������
	MessageBoxW(_T("���ĸ�ʽΪ��.���͡�-������ʽ�����Կո���Ϊÿ������ķָ�"));
}


void C��Ӣ���������Dlg::ON������()
{
	// TODO:  �ڴ���������������
	WinExec("calc.exe", SW_SHOW);
}


void C��Ӣ���������Dlg::OnASC()
{
	// TODO:  �ڴ���������������
	ASCbiao one;
	one.DoModal();
}
