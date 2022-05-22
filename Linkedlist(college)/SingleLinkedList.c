#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
int len;

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Node Data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL)
        {
          p=  p->link;
        }
        p->link = temp;
    }
}
int length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("List Empty \n\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d   ", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}
void addAfter()
{
    struct node *temp;
    struct node *p;
    int loc, len, c = 1;
    printf("Enter Location: ");
    scanf("%d",&loc);
    len = length();
    if (loc > len)
    {
        printf("Invalid Location\n");
        printf("Currently List is having %d nodes", len);
    }
    else
    {
        p = root;
        while (c < loc)
        {
            p = p->link;
            c++;
        }
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter Node Data :");
        scanf("%d",&temp->data);
        temp->link = p->link;
        p->link = temp;
    }
}
void addAtBegin(){
printf("Sorry! No function found...");
}
void delete(){
    struct node * temp;
    int loc;
printf("Enter Location to delete: ");
scanf("%d",&loc);
if (loc>length())
{
  printf("Invalid Location \n");
}
else if (loc==1)
{
    temp=root;
    root=temp->link;
    temp->link=NULL;
    free(temp);

}
else{
    struct node * p = root,*q;
    int i = 1;
    while (i<loc-1)
    {
        p=p->link;
        i++;

    }
    q=p->link;
    p->link=q->link;
    q->link=NULL;
    free(q);
    

}
}
void main()
{
    int ch;
    while (1)
    {
        printf("Single Linkedlist operations: \n");
        printf("1. Append \n");
        printf("2. Add at beginning \n");
        printf("3. Add after \n");
        printf("4. Length \n");
        printf("5. Display \n");
        printf("6. Delete \n");
        printf("7. Quit \n");
        printf("Enter Your Choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            append();
            break;
        case 2:
            addAtBegin();
            break;
        case 3:
            addAfter();
            break;
        case 4:
            len = length();
            printf("Length: %d\n", len);
            break;
        case 5:
            display();
            break;
        case 6:
            delete ();
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Invalid Input \n");
            break;
        }
    }
}
