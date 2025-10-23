#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
//1
int main1() {
    const int size = 10;
    int numbers[size];

    for (int i = 0; i < size; ++i)
    {
        numbers[i] = i + 1;
    }
    cout << "Array elements from 1 to 10:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}

//2

void reverse(int numbers[], int size)
{
    reverse(numbers, numbers + size);
}

int main2() 
{
    const int size = 20;
    int numbers[size];
    reverse(numbers, size);
    cout << numbers << endl;
    return 0;
}

//3
int main3() 
{
    vector <int> vec;
    for (int i = 1; i <= 10; i++)
    {
        vec.push_back(i * 10);
    }
    return 0;
}
