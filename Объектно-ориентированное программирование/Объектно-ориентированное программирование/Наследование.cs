//Наследование
using System;

// Базовый класс
class Animal

{

    public void Eat()
    {
        Console.WriteLine("Animal is eating");
    }
}

// Производный класс
class Dog : Animal
{

    public void Bark()
    {
        Console.WriteLine("Dog is barking");
    }
}
class Program2
{
    static void Main()
    {
        Dog myDog = new Dog();
        myDog.Eat(); // Метод унаследован от базового класса Апsmal myDog.Bark(); 
        myDog.Bark(); // Метод из производного класса Dog
    }
}