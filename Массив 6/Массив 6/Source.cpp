#include <iostream>
#include <cstdlib> // Для функций rand и srand
#include <ctime> // Для функции time

const int array_size = 10; // Размер массива

int main() {
    int numbers[array_size]; // Объявление массива
    double sum = 0.0; // Переменная для хранения суммы элементов

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение массива случайными числами от 1 до 100
    for (int i = 0; i < array_size; ++i) {
        numbers[i] = rand() % 100 + 1;
        sum += numbers[i]; // Подсчет суммы элементов
    }

    // Вычисление среднего арифметического
    double average = sum / array_size;

    // Вывод массива на экран
    std::cout << "Array of numbers:";
    for (int i = 0; i < array_size; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // Вывод среднего арифметического на экран
    std::cout << "Arithmetic mean:" << average << std::endl;

    return 0;
}