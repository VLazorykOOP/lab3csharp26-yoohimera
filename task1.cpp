using System;
using System.Collections.Generic;
using System.Linq;

// 1. Базовий клас (Персона)
class Person
{
    // Захищені поля класу
    protected string name;
    protected int age;

    public Person(string name, int age)
    {
        this.name = name;
        this.age = age;
    }

    // Віртуальний метод для виведення даних
    public virtual void Show()
    {
        Console.WriteLine($"[Персона] Ім'я: {name}, Вік: {age}");
    }
}

// 2. Похідний клас Студент (успадковує Person)
class Student : Person
{
    protected int course;

    public Student(string name, int age, int course) : base(name, age)
    {
        this.course = course;
    }

    public override void Show()
    {
        Console.WriteLine($"[Студент] Ім'я: {name}, Вік: {age}, Курс: {course}");
    }
}

// 3. Похідний клас Викладач (успадковує Person)
class Teacher : Person
{
    protected string subject;

    public Teacher(string name, int age, string subject) : base(name, age)
    {
        this.subject = subject;
    }

    public override void Show()
    {
        Console.WriteLine($"[Викладач] Ім'я: {name}, Вік: {age}, Предмет: {subject}");
    }
}

// 4. Похідний клас Завідувач кафедри (успадковує Teacher)
class HeadOfDepartment : Teacher
{
    protected string department;

    public HeadOfDepartment(string name, int age, string subject, string department) 
        : base(name, age, subject)
    {
        this.department = department;
    }

    public override void Show()
    {
        Console.WriteLine($"[Зав. кафедри] Ім'я: {name}, Кафедра: {department}, Предмет: {subject}");
    }
}

class Program
{
    static void Main()
    {
        // Створення масиву базового класу
        List<Person> people = new List<Person>();

        // Наповнення масиву різними об'єктами через функцію
        FillArray(people);

        Console.WriteLine("Масив, впорядкований за типами класів:");
        Console.WriteLine("--------------------------------------");

        // Сортування масиву за назвою типу класу
        var sortedList = people.OrderBy(p => p.GetType().Name).ToList();

        // Виведення інформації
        foreach (var person in sortedList)
        {
            person.Show();
        }
    }

    // Функція для наповнення масиву
    static void FillArray(List<Person> list)
    {
        list.Add(new Student("Олексій", 19, 2));
        list.Add(new Teacher("Іван Петрович", 45, "Програмування"));
        list.Add(new HeadOfDepartment("Марія Іванівна", 52, "Математика", "Кафедра ІТ"));
        list.Add(new Person("Микола", 30));
        list.Add(new Student("Тетяна", 18, 1));
    }
}
