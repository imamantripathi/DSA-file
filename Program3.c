
// Q 3. WAP to calculate factorial of a number.

#include <stdio.h>

int fact(int num)
{
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

void main()
{
    int num = 0;
    printf("Enter the Number to find Factorial : ");
    scanf("%d", &num);
    int fac = fact(num);
    printf("%d", fac);
}