#include <iostream>
using namespace std;

// Функция для линейного поиска
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Возвращаем индекс элемента, если найден
        }
    }
    return -1; // Возвращаем -1, если элемент не найден
}

int main() {
    const int array_size = 5;
    int numbers[array_size] = { 10, 20, 30, 40, 50 }; // Пример массива

    int target = 30; // Значение, которое мы ищем

    // Выполняем линейный поиск
    int index = linearSearch(numbers, array_size, target);

    // Проверяем результат поиска
    if (index != -1) {
        cout << "The element was found in the position:" << index << endl; //Элемент найден в позиции:
    }
    else {
        cout << "The element was not found" << endl; //Элемент не найден
    }

    return 0;
}