//Инкапсуляция
using System;

class Person
{

    private string name;

    public string Name
    {
        get { return name; }
        set { name = value; }
    }
}
class Program1
{
    static void Main()
    {
        Person person = new Person();
        person.Name = "John"; // Установка значения свойства Name
        Console.WriteLine(person.Name); // Вывод значения свойства Name
    }
}