#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));    // Инициализация генератора случайных чисел

    int number = rand() % 100 + 1;     // Генерирование случайного числа для игры
    int a;
    int popbltka = 7;     // 7 попыток угадать число

    cout << "Hi!nLet's play a game. I'm thinking of a number (1-100). You have 7 tries." << endl;

    while (popbltka > 0)
    {
        cout << "Popbltka #" << 8 - popbltka << ": ";
        try
        {
            cin >> a;
            if (a > 100 || a < 1)
            {
                throw runtime_error("Sorry, your number not correct. Enter a number from 1 to 100.");
            }
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        // Проверка угадал ли пользователь число
        if (a == number)
        {
            cout << "Correct! You win!" << endl;
            break;
        }
        else if (a > number)
        {
            cout << "Your number is too high." << endl;
        }
        else
        {
            cout << "Your number is too low." << endl;
        }
        popbltka--;
    }

    // Если пользователь не угадал число, вывести правильный ответ
    if (popbltka == 0)
    {
        cout << "Sorry, you lose. The correct number was " << number << "." << endl;
    }

    // Спросить пользователя, не хочет ли он сыграть еще раз
    char again;
    do
    {
        cout << "Would you like to play again (Y/N)? ";
        cin >> again;
    } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

    if (again == 'y' || again == 'Y') // Начать игру заново
    {
        main();
    }
    else if (again == 'n' || again == 'N') // Выйти из программы

    {
        cout << "Thanks for playing." << endl;
    }
    return 0;
}
