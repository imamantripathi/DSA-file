#include <stdio.h>
#include <stdlib.h>
// #define Max 5;
int Max = 5;
int stack[5];
int top = -1;

int isEmpty() { return (top == -1) ? 1 : 0; }
int isFull() { return (top == Max - 1) ? 1 : 0; }

void push(int data)
{
    if (isFull() == 1)
    {
        printf("Overflow");
    }
    else
    {
        top += 1;
        stack[top] = data;
        printf("Push Successfully");
    }
}
int pop()
{
    int temp;
    if (isEmpty() == 0)
    {
        temp = stack[top];
        top -= 1;
    }
    else
        printf("Underflow");
    return temp;
}
void peek()
{
    if (isEmpty() == 0)
    {
        printf("%d", stack[top]);
    }
    else
        printf("Stack is Empty");
}
void display()
{
    if (isEmpty() == 0)
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d \n", stack[i]);
        }
    }
}
void main()
{
    int input;
    int data;
    while (1)
    {
        printf(" \n0. Exit \n");
        printf("1. Push \n");
        printf("2. Pop \n");
        printf("3. peek \n");
        printf("4. Display \n");
        printf("5. Check Empty or not \n");
        printf("6. Check Full or not \n");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printf("Deleted element is %d.", pop());
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty() == 1)
                printf("Stack is Empty");
            else
                printf("Stack is not Empty");
            break;
        case 6:
            if (isFull() == 1)
            {
                printf("Stack is full");
            }
            else
                printf("Stack is not full");

            break;
        default:
            printf("Wrong input");
            break;
        }
    }
}
