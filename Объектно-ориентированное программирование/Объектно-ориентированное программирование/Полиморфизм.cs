//Полиморфизм
using System;
class Animal
{
    public virtual void Speak()
    {
        Console.WriteLine("Animal makes a sound");
    }
}
class Cat : Animal
{
    public override void Speak()
    {
        Console.WriteLine("Cat purrs");
    }
}
class Dog : Animal
{
    public override void Speak()
    {
        Console.WriteLine("Dog barks");
    }
}
class Program3
{
    static void Main()
    {
        Animal animal = new Animal();

        Animal cat = new Cat();

        Animal dog = new Dog();

        animal.Speak(); // Выведет: "Animal makes a sound" cat,Speak(); 
        cat.Speak();    // Выведет: "Cat purrs" dog, Speak(); 
        dog.Speak();    // Выведет: "Dog barks"
    }
}
