#include<iostream>
#include<string>
#include<cmath>
using namespace std;

CString zhalan(CString code,int lan)
{
	CString c = code;					//∑≈÷√’§¿∏√‹¬Î
	CString m;			
	int temp = c.GetLength();
	int zu = temp / lan;											
	for (int j = 0; j<zu; j++)								//’§¿∏√‹¬∑÷◊È
	{
		for (int t = 0; t < lan; t++)
			m+=c[j + zu*t];								
	}
	return m;
}