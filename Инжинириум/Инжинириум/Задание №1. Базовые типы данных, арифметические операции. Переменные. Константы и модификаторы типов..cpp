/*
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	int a, b, o;

	cout << "������� ������ �����: ";
	while (!(cin >> a)) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "������! ������� ������ �����: ";
	}

	cout << "������� ������ �����: ";
	while (!(cin >> b)) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "������! ������� ������ �����: ";
	}

	o = (a + b);
	cout << "����� = " << o << endl;
	o = (a - b);
	cout << "�������� = " << o << endl;
	o = (a * b);
	cout << "������������ = " << o << endl;
	o = (a / b);
	if (a != 0)
	{
		cout << "������� = " << o << endl;
	}
	else
	{
		cout << "�� ���� ������ ������" << endl;
	}
	return 0;
}
*/