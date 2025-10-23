//Задание 3
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) 
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = 0; j < n - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    vector<int> array{ 12, 2145, 8, 4016, 4, 2, 1, 1000, 3, 10004, 10, 15, 235, 6 };

    bubbleSort(array); // Сортировка пузырьком

    cout << "Masiv sortirovan:" << endl;
    for (int num : array) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
