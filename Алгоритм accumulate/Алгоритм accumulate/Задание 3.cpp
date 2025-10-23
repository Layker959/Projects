#include <iostream>
#include <cstdlib> // ��� ������� rand() � srand()
#include <ctime> // ��� ������� time()
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));    // ������������� ���������� ��������� �����

    int number = rand() % 100 + 1;     // ������������� ���������� ����� ��� ����
    int a;
    int popbltka = 7;     // 7 ������� ������� �����

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

        // �������� ������ �� ������������ �����
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

    // ���� ������������ �� ������ �����, ������� ���������� �����
    if (popbltka == 0)
    {
        cout << "Sorry, you lose. The correct number was " << number << "." << endl;
    }

    // �������� ������������, �� ����� �� �� ������� ��� ���
    char again;
    do
    {
        cout << "Would you like to play again (Y/N)? ";
        cin >> again;
    } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

    if (again == 'y' || again == 'Y') // ������ ���� ������
    {
        main();
    }
    else if (again == 'n' || again == 'N') // ����� �� ���������

    {
        cout << "Thanks for playing." << endl;
    }
    return 0;
}
