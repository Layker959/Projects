/*
#include <iostream>
#include <string>
#include <array>
using namespace std;

// typedef int Ivan;
// using Yan = int;

struct nums 
{
	int chis;
	int znam;
};
double multiply(nums x, nums y) 
{
	
	return (x.chis/x.znam)*(y.chis/y.znam);
}
int main()
{
	setlocale(LC_ALL, "rus");

	nums a;
	nums b;
	cout << "������� ������ ���������" << endl;
	cin >> a.chis;
	cout << "������� ������ �����������" << endl;
	cin >> a.znam;
	cout << "������� ������ ���������" << endl;
	cin >> b.chis;
	cout << "������� ������ �����������" << endl;
	cin >> b.znam;
	if (a.znam == 0 || b.znam == 0) 
	{
		cout << "����������� �� ����� ���� ����� ����";
	}
	else 
	{
		cout <<"�����: " << multiply(a, b);
	}
}
*/