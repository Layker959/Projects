/*
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	
	int a, b, o;

	cout << "Введите первое число: ";
	while (!(cin >> a)) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Ошибка! Введите первое число: ";
	}

	cout << "Введите второе число: ";
	while (!(cin >> b)) 
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Ошибка! Введите второе число: ";
	}

	o = (a + b);
	cout << "Сумма = " << o << endl;
	o = (a - b);
	cout << "Разность = " << o << endl;
	o = (a * b);
	cout << "Произведение = " << o << endl;
	o = (a / b);
	if (a != 0)
	{
		cout << "Частное = " << o << endl;
	}
	else
	{
		cout << "На ноль делить нельзя" << endl;
	}
	return 0;
}
*/