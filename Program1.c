
// Q 1. WAP to find greatest among 3 number using conditional operator.

#include <stdio.h>
void main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int max = 0;

    // input from user
    printf("Enter the value of num1 : ");
    scanf("%d", &num1);
    printf("Enter the value of num2 : ");
    scanf("%d", &num2);
    printf("Enter the value of num3 : ");
    scanf("%d", &num3);

    // logic for program
    max = (num1 > num2) ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);

    // Output of Program
    printf("Maximum Number among three : %d", max);
    printf("\n");
}