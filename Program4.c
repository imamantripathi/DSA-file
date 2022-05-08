// Q 4. WAP to print Fibonacci series using function.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...

#include <stdio.h>
void fibonacci(int range)
{

    int a = 0, b = 1, c;
    while (a <= range)
    {
        printf("%d\t", a);
        c = a + b;
        a = b;
        b = c;
    }
}
void main()
{
    int limit = 0;
    printf("Enter the Limit of the series : ");
    scanf("%d", &limit);
    printf("The fibonacci series is : ");
    fibonacci(limit);
}
