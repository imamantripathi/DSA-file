#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Insertion of node at beginning of linked list
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// Insertion of node at given index of linked list
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Insertion of node at end of linked list
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

    ptr->next = head;

    return ptr;
}
struct Node *insertAfterNode(struct Node *head,struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
   ptr->next=prevNode->next;
   prevNode->next= ptr;
   return head;

}
int main(int argc, char const *argv[])
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    //  Link first and second node
    head->data = 7;
    head->next = second;
    // Link second and third nodes
    second->data = 11;
    second->next = third;
    // Terminate the list at the third node
    third->data = 66;
    third->next = NULL;
    printf("Linked List Before Insertion : \n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 21); // inserted at first
    // head = insertAtIndex(head, 56, 1); // inserted at given index
    // head = insertAtEnd(head, 56); // inserted in the end
    head = insertAfterNode(head,second,43);
    printf("Linked List After Insertion : \n");
    linkedListTraversal(head);
    return 0;
}
