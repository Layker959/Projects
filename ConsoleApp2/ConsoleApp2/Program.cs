using System;

namespace GraphicalRootFinding
{
    internal class Program
    {
        static double Function(double x)
        {
            return Math.Pow(x, 3) + 4 * x - 2;
        }

        static double Derivative(double x)
        {
            return 3 * Math.Pow(x, 2) + 4;
        }

        static double Phi(double x)
        {
            return cbrt(2 - 4 * x);
        }

        static double cbrt(double x)
        {
            return Math.Pow(x, 1.0 / 3.0);
        }

        

        static double BisectionMethod(double a, double b, double epsilon)
        {
            if (Function(a) * Function(b) >= 0)
            {
                Console.WriteLine("Метод деления отрезка пополам не применим.");
                return double.NaN;
            }

            double c = a;
            while ((b - a) / 2 > epsilon)
            {
                c = (a + b) / 2;
                if (Function(c) == 0.0 || (b - a) / 2 < epsilon)
                    break;
                else if (Function(a) * Function(c) < 0)
                    b = c;
                else
                    a = c;
            }
            return c;
        }

        static double NewtonsMethod(double x0, double epsilon)
        {
            double x = x0;

            while (Math.Abs(Function(x)) > epsilon)
            {
                x -= Function(x) / Derivative(x);
            }
            return x;
        }

        static double SimpleIterationMethod(double x0, double epsilon)
        {
            double currentX = x0;

            while (Math.Abs(Function(currentX)) > epsilon)
            {
                currentX = Phi(currentX);
            }
            return currentX;
        }

        static void Main(string[] args)
        {

            // Пример интервала для метода деления отрезка пополам
            double a = 0.47, b = 2;
            double epsilon = 0.1;

            Console.WriteLine($"\nМетод деления отрезка пополам: {BisectionMethod(a, b, epsilon)}");

            // Пример начального приближения для метода Ньютона
            double x0_newton = 2;
            Console.WriteLine($"\nМетод Ньютона: {NewtonsMethod(x0_newton, epsilon)}");

            // Пример начального приближения для метода простой итерации
            double x0_simple = 0.47;
            Console.WriteLine($"\nМетод простой итерации: {SimpleIterationMethod(x0_simple, epsilon)}");
        }
    }
}