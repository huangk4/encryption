#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>
using namespace std;
void out(char *t, int i,CString path)										//�����ļ������
{
	fstream myfile;
	myfile.open(path,ios::out | ios::app);
	if (!myfile)
	{
		cerr << "����ʧ��\n";
		system("pause");
	}
	for (int j = 0; j < i; j++)
		myfile << t[j];
	myfile << endl;
	myfile.close();
}
void kais(CString code,CString path)//ȫ�ֱ���
{
	int nSize = code.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, code, nSize, NULL, 0, NULL, NULL);
	char *m = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, code, nSize, m, len, NULL, NULL);
	m[len] = '\0';
	const int n = strlen(m);									//���Ĵ�С
	char *t;
	t = new char[n];
	int change = 0;

	for (int i = 0; i < 127; i++)							//127��ASCii����
	{
		for (int i = 0; i <n; i++)
		{
			t[i] = m[i];
			t[i] = (t[i] + change) % 127;
		}
		change++;
		out(t, n,path);
	}
}

void kais2(CString code, CString path)//�����Ľ��Ϊ��ĸ��ת��
{
	int nSize = code.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, code, nSize, NULL, 0, NULL, NULL);
	char *m = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, code, nSize, m, len, NULL, NULL);
	m[len] = '\0';
	const int n = strlen(m);									//���Ĵ�С
	char *t;
	t = new char[n];
	int change = 0;
	int temp;
	for (int i = 0; i < 127; i++)							//127��ASCii����
	{
		for (int i = 0; i <n; i++)
		{
			t[i] = m[i];
			temp = (t[i] + change) % 127;
			if ((temp <= 90 && temp >= 65) || (temp <= 122 && temp >= 97))
				t[i] = temp;
		}
		change++;
		out(t, n, path);
	}
}

void kais3(CString code, CString path)//������Ϊ��ĸʱ��ת��
{
	int nSize = code.GetLength();
	int len = WideCharToMultiByte(CP_ACP, 0, code, nSize, NULL, 0, NULL, NULL);
	char *m = new char[len + 1];
	WideCharToMultiByte(CP_ACP, 0, code, nSize, m, len, NULL, NULL);
	m[len] = '\0';
	const int n = strlen(m);									//���Ĵ�С
	char *t;
	t = new char[n];
	int change = 0;
	for (int i = 0; i < 26; i++)							//26��ASCii����
	{
		for (int i = 0; i <n; i++)
		{
			t[i] = m[i];
			if ((t[i] <= 90 && t[i] >= 65))
				t[i] = (t[i] + change-65) % 26 +65;
			else if ((t[i] <= 122 && t[i] >= 97))
				t[i] = (t[i] + change-97) % 26 + 97;
		}
		change++;
		out(t, n, path);
	}
}