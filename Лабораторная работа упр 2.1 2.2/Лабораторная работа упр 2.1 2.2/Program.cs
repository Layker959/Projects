using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Лабораторная_работа_упр_2._1_2._2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //2.1
            string a = "";
            Console.WriteLine("Введите ваше имя");
            a = Console.ReadLine();
            Console.WriteLine($"Приветствую, {a}");

            //2.2
            int b, c, result;

            Console.Write("Введите первое число -> ");
            b = Convert.ToInt32(Console.ReadLine());

            Console.Write("Введите второе число -> ");
            c = Convert.ToInt32(Console.ReadLine());

            try
            {
                if (c == 0)
                {
                    throw new DivideByZeroException("Нельзя делить на ноль");
                }

                result = b / c;

                Console.WriteLine("Результат деления: " + result);
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine("Ошибка: " + e.Message);
            }

            //Вариант 23 упр 1
            Console.WriteLine("Введите число для нахождения его делителей");
            int num = Convert.ToInt32(Console.ReadLine());
            Console.Write("Divisors of " + num + ": ");
            for (int i = 1; i <= num; i++)
            {
                if (num % i == 0)
                {
                    Console.Write(i + " ");
                }
            }

            //Вариант 23 упр 2
            Console.Write("Введите вашу любимую книгу: ");
            string favoriteBook = Console.ReadLine();

            if (favoriteBook.ToLower() == "гарри поттер")
            {
                Console.WriteLine($"Ваша любимая книга - {favoriteBook}");
                Console.WriteLine("Гарри Поттер - магия и приключения, которые захватывают с первой страницы до последней!");
            }
            else
            {
                Console.WriteLine($"Ваша любимая книга - {favoriteBook}");
                Console.WriteLine("Извините, данная книга не найдена.");
            }

            Console.ReadKey();
        }
    }
}
