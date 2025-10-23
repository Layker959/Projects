#include <iostream>
using namespace std;

class Numbers
{
public:
	int x, y;
	void set(int z, int c)
	{
		x = z;
		y = c;
	}
	 void print()
	{
		 cout << "Numbers(" << x << ", " << y << ")" << endl;
	}
};

int main()
{
	Numbers n1;
	n1.set(3, 3); // инициализируем объект n1 значениями 3 и 3
	Numbers n2{ 4, 4 }; // инициализируем объект n2 значениями 4 и 4
	n1.print();
	n2.print();
	return 0;
}
/*
Результат:
Numbers(3, 3)
Numbers(4, 4)
*/