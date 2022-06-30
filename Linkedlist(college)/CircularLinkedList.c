#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node*root=NULL;
struct node *tail=NULL;
int len;

void append();
int length();
void display();
void addafter();
void reverse_list();
void addatbeg();
void sort1();
void sort2();
void delete();


void main()
{
    int ch;
    while(1)
    {
        printf("\nSingle Circular Linked List Operations: \n");
        printf("1. Append\n");
        printf("2. Add After\n");
        printf("3. Length\n");
        printf("4. Display\n");
        printf("5. Delete\n");
        printf("6. Add At Beginning\n");
        /*printf("8. Selection Sort\n");
        printf("9. Bubble Sort\n");*/
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:append();
            break; 
            case 2:addafter();
            break;
            case 3:len=length();
            printf("Length is: %d\n", len);
            break;
            case 4:display();
            break;
            case 5:delete();
            break;
            case 6: addatbeg();
            break;
            case 7:exit(1);
            default:printf("Invalid Input");
        }
    }    
    
}
void append()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d", &temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
        tail=temp;
        temp->link=root;
    }
    else
    {
        struct node *p;
        p=root;
        while(p->link!=root)
        {
            p=p->link;
        }
        p->link=temp;
        temp->link=root;
        tail=temp;
    }
}

int length()
{
    int count=0;
    struct node *temp;
    temp=root;
    while(temp->link!=root)
    {
        ++count;
        temp=temp->link;
    }
    return count+1;
}

void display()
{
    struct node *temp;
    temp=root;
    if(temp==NULL)
    {
        printf("List is empty\n\n");
    }
    else
    {
        while(temp->link!=root)
        {
            printf("%d ", temp->data);
            temp=temp->link;
        }
        printf("%d ", temp->data);
        printf("\n\n");
    }
}

void addafter()
{
    struct node *temp;
    struct node *p;
    int loc, len,i;
    i=1;
    printf("Enter Location: ");
    scanf("%d", &loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location\n");
        printf("Currently list is having %d nodes: ", len);
    }
    else
    {
        p=root;
        while(i<loc)
        {
            p=p->link;
            ++i;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->link=p->link;
        p->link=temp;
    }
    
}

void delete()
{
    struct node *temp;
    int loc;
    printf("Enter Location to Delete: ");
    scanf("%d", &loc);
    if(loc>length())
    {
        printf("Invalid Location\n");
    }
    else if(loc==1)
    {
        temp=root;
        root=temp->link;
        tail->link=root;
        free(temp);
    }
    else
    {
        struct node *p=root;
        struct node *q;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            ++i;
        }
        if(loc==length())
        {
            tail=p->link;
            q=p->link;
            p->link=q->link;
            free(q);
        }
        else
        {
            q=p->link;
            p->link=q->link;
            free(q);
        }
    }
}

void addatbeg()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
        tail->link=temp;
    }
    
}


/*void reverse_list()
{
    struct node *prevnode, *nextnode, *currentnode;
    prevnode = NULL;
    currentnode = nextnode = root;
    while(nextnode != NULL){
        nextnode = nextnode->link;
        currentnode->link = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
        root = prevnode;
}

void sort1()
{
    struct node *i,*j;
    int temp;
    for(i=root;i->link!=NULL;i=i->link)
    {
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}

void sort2()
{
    struct node *p , *q, *end;
    int temp;
    for(end=NULL;end!=root->link;end=p)
    {
        for(p=root;p->link!=end;p=p->link)
        {
            q=p->link;
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
        }
    }
}
*/
