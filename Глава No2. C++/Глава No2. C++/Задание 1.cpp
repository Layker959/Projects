/*
// ������� 1
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

	cout << "����� ���������� � ����� ����. �� ����� ���� ����? (�� -1 �� 7)" << endl;

	do
	{
		cin >> a;
		

		switch (static_cast<levelsName>(a))
		{
		case Parking:
			cout << "�� ������ �� ����� Parking" << endl;
			break;
		case Shop:
			cout << "�� ������ �� ����� Shop" << endl;
			break;
		case Bank:
			cout << "�� ������ �� ����� Bank" << endl;
			break;
		case InsuranceCompany:
			cout << "�� ������ �� ����� InsuranceCompany" << endl;
			break;
		case StockExchange:
			cout << "�� ������ �� ����� StockExchange" << endl;
			break;
		case ExhibitionHall:
			cout << "�� ������ �� ����� ExhibitionHall" << endl;
			break;
		case Pharmacy:
			cout << "�� ������ �� ����� Pharmacy" << endl;
			break;
		case Restaurant:
			cout << "�� ������ �� ����� Restaurant" << endl;
			break;
		case Roof:
			cout << "�� ������ �� ����� Roof" << endl;
			break;
		default:
			break;
		}
		if (a < -1 || a > 7) 
		{
			cout << "������! �������� ���� (�� -1 �� 7)" << endl;
		}
		else 
		{
			cout << "����� �� �����? Y/N" << endl;
			cin >> c;
			if (c == 'Y' || c == 'y') 
			{
				cout << "�� ����� �� ����� �� " << a << " �����" << endl;

				v = false;
			}
			else if (c == 'N' || c == 'n') 
			{
				cout << "�������� ����" << endl;
			}
			else 
			{
				cout << "���� ����� ���� ��� 'N', �������� ����" << endl;
			}
		}
	} while (v);
	return 0;
}
*/