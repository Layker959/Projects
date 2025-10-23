using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int Summary1 = 6;
            int Summary2 = 5;
            int Summary3 = 8;
            int Summary4 = 7;

            bool solutionFound = false;
            Console.WriteLine($" 4x1 + 2x2 + x3 + 2x4 = {Summary1} \n x1 + 4x2 + 2x3 + x4 = {Summary2} \n 2x1 + 6x2 + x3 + 3x4 = {Summary3} \n 2x1 + 5x2 + 2x3 + 2x4 = {Summary4}");
            // Ищем решение для Summary1 = 6
            for (int x1 = 0; x1 <= Summary1; x1++)
            {
                for (int x2 = 0; x2 <= Summary1; x2++)
                {
                    for (int x3 = 0; x3 <= Summary1; x3++)
                    {
                        for (int x4 = 0; x4 <= Summary1; x4++)
                        {
                            if (4 * x1 + 2 * x2 + x3 + 2 * x4 == Summary1 && x1 + 4 * x2 + 2 * x3 + x4 == Summary2 && 2 * x1 + 6 * x2 + x3 + 3 * x4 == Summary3 && 2 * x1 + 5 * x2 + 2 * x3 + 2 * x4 == Summary4)
                            {
                                Console.WriteLine($"Ответ: x1 = {x1}, x2 = {x2}, x3 = {x3}, x4 = {x4}");
                                solutionFound = true;
                                break;
                            }
                            else {
                            break; }
                        }
                        if (solutionFound) break;
                    }
                    if (solutionFound) break;
                }
                if (solutionFound) break;
            }

            if (!solutionFound)
            {
                Console.WriteLine("Ответа нет");
            }
            Console.WriteLine("Выполнил Иммис");
        }
    }
}