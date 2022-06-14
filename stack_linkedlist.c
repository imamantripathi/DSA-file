#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *link;
};
struct stack *top = 0;
void push(int item)
{
    struct stack *newNode;
    newNode = (struct stack *)malloc(sizeof(struct stack));
    newNode->data = item;
    newNode->link = top;
    top = newNode;
}
int pop()
{
    struct stack *temp;
    temp = top;
    if (top == NULL)
        printf("Stack is Empty");
    else
    {
        top = temp->link;
        // top= top->link;
        free(temp);
    }
    return top->data;
}
void peek()
{
    if (top == NULL)
    {
      
        printf("Stack is Empty");
    }
    else
    {
        printf("%d", top->data);
    }
}
void display()
{
    struct stack *temp = top;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->link;
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
        default:
            printf("Wrong input");
            break;
        }
    }
}