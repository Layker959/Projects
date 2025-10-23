#include <iostream>
using namespace std;

// ������� ��� ��������� ������
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // ���������� ������ ��������, ���� ������
        }
    }
    return -1; // ���������� -1, ���� ������� �� ������
}

int main() {
    const int array_size = 5;
    int numbers[array_size] = { 10, 20, 30, 40, 50 }; // ������ �������

    int target = 30; // ��������, ������� �� ����

    // ��������� �������� �����
    int index = linearSearch(numbers, array_size, target);

    // ��������� ��������� ������
    if (index != -1) {
        cout << "The element was found in the position:" << index << endl; //������� ������ � �������:
    }
    else {
        cout << "The element was not found" << endl; //������� �� ������
    }

    return 0;
}