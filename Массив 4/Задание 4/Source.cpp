#include <iostream>
using namespace std;

// Функция для сортировки пузырьком
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен значениями, если предыдущий элемент больше следующего
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;

    // Ввод размера массива
    cout << "Enter the size of the array:"; //Введите размер массива:
    cin >> size;

    int* numbers = new int[size]; // Динамическое выделение памяти

    // Ввод элементов массива
    cout << "Enter the array elements:"; //Введите элементы массива:
    for (int i = 0; i < size; ++i) {
        cin >> numbers[i];
    }

    // Сортировка массива с помощью сортировки пузырьком
    bubbleSort(numbers, size);

    // Вывод отсортированного массива
    cout << "Sorted array:"; //Отсортированный массив:
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    delete[] numbers; // Освобождаем память после использования

    return 0;
}
