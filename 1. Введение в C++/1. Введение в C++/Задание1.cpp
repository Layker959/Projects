#include <iostream>
using namespace std;

int start()
{
	//1
	int a = 42;
	cout << "Exit: " << a << endl;
	//2
	int b = 10;
	b++;
	//3
	int layk = 2;
	cout << "layk: " << layk << endl;
	return 0;
}
	//4
int main()
{
	int euros_count = 0;
	int dollar = 0;
	cout << "Vvod Evro:";
	cin >> euros_count;
	dollar = euros_count * 1.25;
	cout << "Dollar: " << dollar << endl;
}	
