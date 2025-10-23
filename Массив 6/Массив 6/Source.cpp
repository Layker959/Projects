#include <iostream>
#include <cstdlib> // ��� ������� rand � srand
#include <ctime> // ��� ������� time

const int array_size = 10; // ������ �������

int main() {
    int numbers[array_size]; // ���������� �������
    double sum = 0.0; // ���������� ��� �������� ����� ���������

    // ������������� ���������� ��������� �����
    srand(time(NULL));

    // ���������� ������� ���������� ������� �� 1 �� 100
    for (int i = 0; i < array_size; ++i) {
        numbers[i] = rand() % 100 + 1;
        sum += numbers[i]; // ������� ����� ���������
    }

    // ���������� �������� ���������������
    double average = sum / array_size;

    // ����� ������� �� �����
    std::cout << "Array of numbers:";
    for (int i = 0; i < array_size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // ����� �������� ��������������� �� �����
    std::cout << "Arithmetic mean:" << average << std::endl;

    return 0;
}