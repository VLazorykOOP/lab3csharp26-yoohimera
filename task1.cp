using System;
using System.Collections.Generic;
using System.Linq;

// Клас DRomb (ромб)
class DRomb
{
    // Захищені поля: діагоналі (d1, d2) та колір (c)
    protected int d1;
    protected int d2;
    protected int c;

    // Конструктор для створення екземпляра із заданими довжинами
    public DRomb(int d1, int d2, int color)
    {
        this.d1 = d1;
        this.d2 = d2;
        this.c = color;
    }

    // Властивості для отримання-встановлення довжин
    public int D1
    {
        get { return d1; }
        set { if (value > 0) d1 = value; }
    }

    public int D2
    {
        get { return d2; }
        set { if (value > 0) d2 = value; }
    }

    // Властивість для отримання кольору (тільки для читання)
    public int Color
    {
        get { return c; }
    }

    // Метод: вивести довжини на екран
    public void ShowLengths()
    {
        Console.WriteLine($"Діагоналі: {d1} та {d2}");
    }

    // Метод: розрахувати периметр ромба
    public double GetPerimeter()
    {
        // Сторона ромба a = sqrt((d1/2)^2 + (d2/2)^2)
        double side = Math.Sqrt(Math.Pow(d1 / 2.0, 2) + Math.Pow(d2 / 2.0, 2));
        return 4 * side;
    }

    // Метод: розрахувати площу ромба
    public double GetArea()
    {
        return (d1 * d2) / 2.0;
    }

    // Метод: встановити, чи є даний ромб квадратом
    public bool IsSquare()
    {
        return d1 == d2;
    }

    // Допоміжний метод для зручного виводу
    public void ShowFullInfo()
    {
        Console.WriteLine($"Колір: {c} | d1: {d1}, d2: {d2} | Площа: {GetArea():F1} | Периметр: {GetPerimeter():F1} | Квадрат: {IsSquare()}");
    }
}

class Program
{
    static void Main()
    {
        // 1. Створення масиву ромбів
        DRomb[] rombs = new DRomb[]
        {
            new DRomb(10, 10, 5), // Квадрат
            new DRomb(12, 8, 2),
            new DRomb(6, 6, 1),   // Квадрат
            new DRomb(15, 5, 3),
            new DRomb(8, 14, 2)
        };

        // 2. Впорядкування за кольорами
        Console.WriteLine("--- Ромби, впорядковані за кольорами ---");
        foreach (var r in rombs.OrderBy(r => r.Color)) r.ShowFullInfo();

        // 3. Впорядкування за площею
        Console.WriteLine("\n--- Ромби, впорядковані за площею ---");
        foreach (var r in rombs.OrderBy(r => r.GetArea())) r.ShowFullInfo();

        // 4. Впорядкування за периметром
        Console.WriteLine("\n--- Ромби, впорядковані за периметром ---");
        foreach (var r in rombs.OrderBy(r => r.GetPerimeter())) r.ShowFullInfo();

        // 5. Кількість квадратів
        int squareCount = rombs.Count(r => r.IsSquare());
        Console.WriteLine($"\nКількість квадратів у масиві: {squareCount}");
    }
}
