#include <iostream>
using namespace std;

int main()
{
	//1
	int a = 42;
	cout << "Exit: " << a << endl;
	//2
	int b = 10;
	b++;
	cout << b << endl;
	//3
	int layk = 2;
	cout << "layk: " << layk << endl;
	//4
	int euros_count = 0;
	int dollar = 0;
	cout << "Vvod Evro:";
	cin >> euros_count;
	dollar = euros_count * 1.25;
	cout << "Dollar: " << dollar << endl;
	return 0;
}
