// Q 12. WAP to check weather number is palindrome.
#include <stdio.h>
int palindrome(int num)
{
    int temp = 0;
    int duplicate = num;
    while (num > 0)
    {
        int d = num % 10;
        temp = temp * 10 + d;
        num = num / 10;
    }
    // printf("%d",temp);
    if (duplicate == temp)
    {
        return 1;
    }
    else
        return 0;
}
void main()
{
    int num = 0;
    printf("Enter the Number to check Palindrome or Not : ");
    scanf("%d", &num);
    // palindrome(num);
    int ans = palindrome(num);
    if (ans == 0)
        printf("Not Palindrome");
    else if (ans == 1)
        printf("Palindrome");
}