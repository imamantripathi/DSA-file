//  Q 13. WAP to calculate sum of digit of number.
#include <stdio.h>
int sumOfDigit(int num)
{
    int sum = 0;
    while (num > 0)
    {
        int d = num % 10;
        sum += d;
        num /= 10;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int num = 0;
    printf("Enter the Number to find the sum : ");
    scanf("%d", &num);
    int sum = sumOfDigit(num);
    printf("The Sum of Digit of %d is %d.", num, sum);
    return 0;
}
