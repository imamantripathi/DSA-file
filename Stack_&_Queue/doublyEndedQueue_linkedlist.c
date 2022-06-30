#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next ;
    struct node *prev ;

};
struct node *head ;
void insertatFront(int x){
    struct node *newnode = (struct node *)malloc(sizeof (struct node));
    newnode ->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head == NULL){
        head = newnode;

    }
    else{
        head ->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insertAtEnd(int x){
    struct node *newnode ;
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL ;
    newnode->prev = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node *temp ;
        temp = head ;
        while(temp->next != NULL){
            temp = temp ->next ;

        }
        temp ->next = newnode;
        newnode->prev = temp ;
        newnode->next = NULL;
    }

}

void deletefromfront(){
    struct node *temp = head;
    if(head == NULL){
        printf("The list is Empty !");
    }
    else{
        temp = head;
        head = head->next ;
        head->prev = NULL ;
        printf("\nThe deleted element is : %d\n",temp->data);
        free(temp);
    }
}
void deletefromend(){
    struct node *temp = head;
    if(head == NULL){
        printf("The list is Empty !");

    }
    else if(head ->next == NULL){
        head = NULL;
    }
    else{
        while(temp ->next != NULL){
            temp = temp ->next ;

        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void insertAtposition(int x , int pos){
    int i = 1;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev= NULL;
    if(head == NULL){
        head = newnode;
        newnode->prev = NULL ;
        newnode->next = NULL ;
    }
    else if(pos== 1){
        insertatFront(x);
    }
    else{
        struct node *temp = head;
        while(i<pos-1){
            temp = temp->next ;
            i++;
        }
        newnode->next = temp ->next ;
        newnode->prev = temp ;
        temp ->next = newnode;
        temp->next ->prev = newnode;
    }
    printf("The element get inserted at index %d\n",pos);
}

void deletefrompos(int pos){
    struct node *position ;

    int i = 1;
    if(head == NULL){
        printf("The list is Empty !");
    }
    else if (pos==1){
        deletefromfront();
    }
    else{
        struct node *temp = head;
        while (i < pos-1 ){
            temp = temp->next ;
            i++;
        }
        position= temp->next ;
        if(position->next != NULL){
            position->next ->prev = temp ;
        }
        temp->next =  position ->next ;
        printf("The node at index %d is %d deleted Now !\n",pos,position->data);
        free(position);

    }
    
}

void display(){
    struct node *temp ;
    if(head ==NULL){
        printf("The list is Empty ! ");
    }
    else{
        temp = head;
        while(temp!=NULL){
            printf("%d\n",temp ->data );
            temp = temp->next ;
        }
    }
}
int main(){
    insertatFront(10);
    insertatFront(20);
    insertatFront(30);
    insertAtEnd(100);
    insertAtEnd(200);
    insertAtEnd(300);
    insertAtposition(10000,3);
    printf("\nBefore deletion operation ! ---------\n");
    display();
    printf("After the deletion Operation !-----");
    // deletefromfront();
    // deletefromfront();
    deletefrompos(3);
    // deletefromend();
    // deletefromend();
    display();
    return 0;
}