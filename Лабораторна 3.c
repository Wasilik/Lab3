#include <stdio.h>
#include <math.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
    int choice;

#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    printf("\nМеню:\n");
    printf("1 - (варіант 102) Перпендикулярність прямих / кут між ними\n");
    printf("2 - (варіант 109) Найбільше, найменше, середнє з трьох чисел\n");
    printf("3 - (варіант 15) Прямокутники на столі\n");
    printf("4 - (варіант 52) Точка всередині трикутника\n");
    printf("5 - (варіант 113) Середнє середніх чисел двох трійок\n");
    printf("6 - (варіант 91) Парність суми номерів квартир\n");
    printf("7 - (варіант 105) Існування та гострокутність трикутника\n");
    printf("8 - (варіант 48) Прямокутний трикутник і гіпотенуза\n");
    printf("9 - (варіант 39) Ворожіння на ромашці\n");
    printf("10 - (варіант 84) Рівнобедрений трикутник\n");
    printf("Ваш вибір: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        double A1, B1, C1, A2, B2, C2, c, kut;

        printf("Введіть A1, B1, C1: ");
        scanf("%lf %lf %lf", &A1, &B1, &C1);
        printf("Введіть A2, B2, C2: ");
        scanf("%lf %lf %lf", &A2, &B2, &C2);

        if (A1 * A2 + B1 * B2 == 0)
            printf("Прямі перпендикулярні\n");
        else
        {
            c = fabs(A1 * A2 + B1 * B2) / (sqrt(A1 * A1 + B1 * B1) * sqrt(A2 * A2 + B2 * B2));
            if (c > 1)
                c = 1;
            kut = acos(c) * 180 / 3.14159265;
            printf("Прямі не перпендикулярні\n");
            printf("Кут між ними: %.2lf градусів\n", kut);
        }
        break;
    }
    case 2:
    {
        int a, b, c;

        printf("Введіть три різних цілих числа: ");
        scanf("%d %d %d", &a, &b, &c);

        if (a > b && a > c)
            printf("а) найбільше - перше\n");
        else if (b > a && b > c)
            printf("а) найбільше - друге\n");
        else
            printf("а) найбільше - третє\n");

        if (a < b && a < c)
            printf("б) найменше - перше\n");
        else if (b < a && b < c)
            printf("б) найменше - друге\n");
        else
            printf("б) найменше - третє\n");

        if ((a > b && a < c) || (a < b && a > c))
            printf("в) середнє - перше\n");
        else if ((b > a && b < c) || (b < a && b > c))
            printf("в) середнє - друге\n");
        else
            printf("в) середнє - третє\n");
        break;
    }
    case 3:
    {
        int a, b, c, d, n1, n2;

        printf("Введіть розміри столу a і b (a > b): ");
        scanf("%d %d", &a, &b);
        printf("Введіть розміри прямокутника c і d (c > d): ");
        scanf("%d %d", &c, &d);
        
        n1 = (a / c) * (b / d);
        n2 = (b / c) * (a / d);
        printf("Вздовж довгої сторони столу: %d шт.\n", n1);
        printf("Вздовж короткої сторони столу: %d шт.\n", n2);

        if (n1 > n2)
            printf("Краще розміщувати вздовж довгої сторони столу\n");
        else if (n2 > n1)
            printf("Краще розміщувати вздовж короткої сторони столу\n");
        else
            printf("Обидва способи дають однакову кількість\n");
        break;
    }
    case 4:
    {
        double x1, y1, x2, y2, x3, y3, x, y, d1, d2, d3;

        printf("Введіть координати вершини A: ");
        scanf("%lf %lf", &x1, &y1);
        printf("Введіть координати вершини B: ");
        scanf("%lf %lf", &x2, &y2);
        printf("Введіть координати вершини C: ");
        scanf("%lf %lf", &x3, &y3);
        printf("Введіть координати точки: ");
        scanf("%lf %lf", &x, &y);

        d1 = (x1 - x) * (y2 - y1) - (x2 - x1) * (y1 - y);
        d2 = (x2 - x) * (y3 - y2) - (x3 - x2) * (y2 - y);
        d3 = (x3 - x) * (y1 - y3) - (x1 - x3) * (y3 - y);

        if ((d1 > 0 && d2 > 0 && d3 > 0) || (d1 < 0 && d2 < 0 && d3 < 0))
            printf("Точка лежить всередині трикутника\n");
        else
            printf("Точка не лежить всередині трикутника\n");
        break;
    }
    case 5:
    {
        double a1, a2, a3, b1, b2, b3, m1, m2;

        printf("Введіть першу трійку чисел: ");
        scanf("%lf %lf %lf", &a1, &a2, &a3);
        printf("Введіть другу трійку чисел: ");
        scanf("%lf %lf %lf", &b1, &b2, &b3);

        if ((a1 > a2 && a1 < a3) || (a1 < a2 && a1 > a3))
            m1 = a1;
        else if ((a2 > a1 && a2 < a3) || (a2 < a1 && a2 > a3))
            m1 = a2;
        else
            m1 = a3;
        if ((b1 > b2 && b1 < b3) || (b1 < b2 && b1 > b3))
            m2 = b1;
        else if ((b2 > b1 && b2 < b3) || (b2 < b1 && b2 > b3))
            m2 = b2;
        else
            m2 = b3;

        printf("Середнє число першої трійки: %g\n", m1);
        printf("Середнє число другої трійки: %g\n", m2);
        printf("Середнє арифметичне: %g\n", (m1 + m2) / 2);
        break;
    }
    case 6:
    {
        int n, a, k;
        printf("Введіть кількість квартир n: ");
        scanf("%d", &n);
        printf("Введіть номер першої квартири a: ");
        scanf("%d", &a);

        if (n % 2 == 0)
            k = n / 2;
        else if (a % 2 == 1)
            k = (n + 1) / 2;
        else
            k = (n - 1) / 2;

        if (k % 2 == 0)
            printf("Сума номерів квартир - парне число\n");
        else
            printf("Сума номерів квартир - непарне число\n");
        break;
    }
    case 7:
    {
        double a, b, c;

        printf("Введіть три додатні числа: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a + b > c && a + c > b && b + c > a)
        {
            printf("Трикутник побудувати можна\n");
            if (a * a + b * b > c * c && a * a + c * c > b * b && b * b + c * c > a * a)
                printf("Він гострокутний\n");
            else
                printf("Він не гострокутний\n");
        }
        else
            printf("Трикутник побудувати не можна\n");
        break;
    }
    case 8:
    {
        double a, b, c;
        printf("Введіть сторони трикутника a, b, c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (fabs(a * a + b * b - c * c) < 0.0001)
            printf("Трикутник прямокутний, гіпотенуза - сторона c\n");
        else if (fabs(a * a + c * c - b * b) < 0.0001)
            printf("Трикутник прямокутний, гіпотенуза - сторона b\n");
        else if (fabs(b * b + c * c - a * a) < 0.0001)
            printf("Трикутник прямокутний, гіпотенуза - сторона a\n");
        else
            printf("Трикутник не прямокутний\n");
        break;
    }
    case 9:
    {
        int n;
        printf("Введіть кількість пелюсток: ");
        scanf("%d", &n);

        if (n % 2 == 1)
            printf("Любить\n");
        else
            printf("Не любить\n");
        break;
    }
    case 10:
    {
        double a, b, c;
        printf("Введіть сторони трикутника a, b, c: ");
        scanf("%lf %lf %lf", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b || a == c || b == c)
                printf("Трикутник рівнобедрений\n");
            else
                printf("Трикутник не рівнобедрений\n");
        }
        else
            printf("Такого трикутника не існує\n");
        break;
    }
    default:
        printf("Невірний пункт меню\n");
    }

    return 0;
}