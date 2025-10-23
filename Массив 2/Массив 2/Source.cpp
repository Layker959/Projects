#include <iostream>
#include <cstdlib> // ������� rand � srand
#include <ctime> // ������� time
using namespace std;

const int array_size = 20; // ������ �������

// ������� ��� ������������ ��������� ������� � �������� �������
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int numbers[array_size]; // ���������� �������

    // ���������� ������� ���������� ������� �� 1 �� 100
    srand(time(NULL)); // ������������� ���������� ��������� �����
    for (int i = 0; i < array_size; ++i) {
        numbers[i] = rand() % 100 + 1;
    }

    // ����� ��������� �������
    cout << "The source array:" << endl; //������ �� ������������
    for (int i = 0; i < array_size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // ������������ ��������� ������� � �������� �������
    reverseArray(numbers, array_size);

    // ����� ������� ����� ������������
    cout << "The array after being rearranged in reverse order:" << endl; //������ ����� ������������ � �������� �������
    for (int i = 0; i < array_size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}