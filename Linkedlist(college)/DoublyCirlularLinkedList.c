#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root=NULL;
struct node *tail=NULL;
int len;

void append();
void display();
int length();
void addatbegin();
void addafter();
void delaloc();

int main()
{
    int ch;
    while(1)
    {
        printf("\nDouble Circular Linked List Operations: \n");
        printf("1. Append\n");
        //printf("2. Add At Beginning\n");
        printf("2. Add At Beginning\n");
        printf("3. Length\n");
        printf("4. Display\n");
        printf("5. Add after a Particular Location\n");
        printf("6. Delete at a Certain Location\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:append();
            break; 
            case 2:addatbegin();
            break;
            case 3:len=length();
            printf("Length is: %d\n", len);
            break;
            case 4:display();
            break;
            case 5:addafter();
            break;
            case 6: delaloc();
                    display();
            break;
            case 7:exit(1);
            default:printf("Invalid Input");
        }
    }

    return 0;
}

void append()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->left=NULL;
    newnode->right=NULL;
    if(tail==NULL)
    {
        tail=newnode;
        root=newnode;
        tail->right=newnode;
        root->left=newnode;
    }
    else
    {
        newnode->left=tail;
        newnode->right=root;
        tail->right=newnode;
        tail=newnode;
        
    }
    
}

void display()
{
    struct node *temp;
    if(root==NULL)
    {
        printf("Empty List\n");
    }
    else if(root==tail)
    {
        printf("%d\n", root->data);
    }
    else
    {
        temp=root;
        while(temp!=tail)
        {
            printf("%d ", temp->data);
            temp=temp->right;
        }
        printf("%d ", temp->data);
    }
    
    
}


int length()
{
    struct node *temp=root;
    int count=0;
    while(temp!=tail)
    {
        ++count;
        temp=temp->right;
    }
    return count+1;
}

void addatbegin()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
        tail=temp;
        temp->right=tail;
        temp->left=tail;
    }
    else
    {
        temp->left=tail;
        temp->right=root;
        root->left=temp;
        tail->right=temp;
        root=temp;
        
    }
}

void addafter()
{
    struct node *temp, *p;
    int loc,len,i=1;
    printf("Enter Location: ");
    scanf("%d", &loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location\n");
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->left=NULL;
        temp->right=NULL;
        p=root;
        while(i<loc)
        {
            p=p->right;
            ++i;
        }
        
        if(loc==len)
        {
            temp->right=p->right;
            p->right->left=temp;
            temp->left=p;
            p->right=temp;
            tail=temp;
        }
        else
        {
            temp->right=p->right;
            p->right->left=temp;
            temp->left=p;
            p->right=temp;
        }
    }
}

void delaloc()
{
    int loc,len;
    printf("Enter the location to delete from: ");
    scanf("%d", &loc);
    len=length();
    if(len==0)
    {
        printf("Empty List\n");
    }
    else if(loc>len)
    {
        printf("Invalid Location\n");
    }
    else if(root==tail)
    {
        struct node *temp;
        temp=root;
        root=NULL;
        tail=NULL;
        free(temp);
    }
    else if(loc==1)
    {
        struct node *temp;
        temp=root;
        root=root->right;
        root->left=tail;
        free(temp);
    }
    else if(loc==len)
    {
        struct node *temp;
        temp=tail;
        tail=tail->left;
        tail->right=root;
        free(temp);
    }
    else
    {
        struct node *p, *q;
        p=root;
        int i=1;
        while(i<loc-1)
        {
            p=p->right;
            ++i;
        }
        q=p->right;
        p->right=q->right;
        q->right->left=p;
        free(q);
        
    }
}
