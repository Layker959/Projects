#include <iostream>
using namespace std;

int main() {
    const int array_size = 10; 
    int numbers[array_size];  

    for (int i = 0; i < array_size; ++i) 
    {
        numbers[i] = i + 1;
    }

    cout << "Elements array:" << endl;
    for (int i = 0; i < array_size; ++i) 
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}