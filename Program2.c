/*
Q 2. WAP to print table of a number using do while loop.
*/

#include <stdio.h>
void main()
{
    int num = 0;
    // User Input
    printf("Enter the Number for table : ");
    scanf("%d", &num);

    // Logic
    int i = 1;
    int temp = 0;
    do
    {
        temp = i * num;
        printf("%d x %d = %d", i, num, temp);
        printf("\n");
        i++;
    } while (i <= 10);
    temp = 0;
}