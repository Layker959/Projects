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
	cout << "¬ведите первый числитель" << endl;
	cin >> a.chis;
	cout << "¬ведите первый знаменатель" << endl;
	cin >> a.znam;
	cout << "¬ведите второй числитель" << endl;
	cin >> b.chis;
	cout << "¬ведите второй знаменатель" << endl;
	cin >> b.znam;
	if (a.znam == 0 || b.znam == 0) 
	{
		cout << "«наменатель не может быть равен нулю";
	}
	else 
	{
		cout <<"ќтвет: " << multiply(a, b);
	}
}
*/