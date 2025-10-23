/*
// Задание 1
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int a;
	char c;
	bool v = true;
	enum levelsName
	{
		Parking = -1,
		Shop,
		Bank,
		InsuranceCompany,
		StockExchange,
		ExhibitionHall,
		Pharmacy,
		Restaurant,
		Roof
	};

	cout << "Добро пожаловать в Умный лифт. На какой этаж едем? (От -1 до 7)" << endl;

	do
	{
		cin >> a;
		

		switch (static_cast<levelsName>(a))
		{
		case Parking:
			cout << "Вы сейчас на этаже Parking" << endl;
			break;
		case Shop:
			cout << "Вы сейчас на этаже Shop" << endl;
			break;
		case Bank:
			cout << "Вы сейчас на этаже Bank" << endl;
			break;
		case InsuranceCompany:
			cout << "Вы сейчас на этаже InsuranceCompany" << endl;
			break;
		case StockExchange:
			cout << "Вы сейчас на этаже StockExchange" << endl;
			break;
		case ExhibitionHall:
			cout << "Вы сейчас на этаже ExhibitionHall" << endl;
			break;
		case Pharmacy:
			cout << "Вы сейчас на этаже Pharmacy" << endl;
			break;
		case Restaurant:
			cout << "Вы сейчас на этаже Restaurant" << endl;
			break;
		case Roof:
			cout << "Вы сейчас на этаже Roof" << endl;
			break;
		default:
			break;
		}
		if (a < -1 || a > 7) 
		{
			cout << "Ошибка! Выберите этаж (От -1 до 7)" << endl;
		}
		else 
		{
			cout << "Выйти из лифта? Y/N" << endl;
			cin >> c;
			if (c == 'Y' || c == 'y') 
			{
				cout << "Вы вышли из лифта на " << a << " этаже" << endl;

				v = false;
			}
			else if (c == 'N' || c == 'n') 
			{
				cout << "Выберите этаж" << endl;
			}
			else 
			{
				cout << "Ввод будет учтён как 'N', выберите этаж" << endl;
			}
		}
	} while (v);
	return 0;
}
*/