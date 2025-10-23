#include <iostream>
#include <cstdlib> // функции rand и srand
#include <ctime> // функция time
using namespace std;

const int array_size = 20; // Размер массива

// Функция для перестановки элементов массива в обратном порядке
void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int numbers[array_size]; // Объявление массива

    // Заполнение массива случайными числами от 1 до 100
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < array_size; ++i) {
        numbers[i] = rand() % 100 + 1;
    }

    // Вывод исходного массива
    cout << "The source array:" << endl; //Массив до перестановки
    for (int i = 0; i < array_size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // Перестановка элементов массива в обратном порядке
    reverseArray(numbers, array_size);

    // Вывод массива после перестановки
    cout << "The array after being rearranged in reverse order:" << endl; //Массив после перестановки в обратном порядке
    for (int i = 0; i < array_size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}