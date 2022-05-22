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
// Deletion of node at beginning of linked list
struct Node *deleteAtBeginning(struct Node *head)
{

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// Deleting of node in between of linked list
struct Node *deleteAtBetween(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
// Deleting of node from the last 
struct Node *deleteAtLast(struct Node *head)
{

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
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
    printf("Linked List Before Deletion : \n");
    linkedListTraversal(head);
    // head = deleteAtBeginning(head); // deleted from the beginning
    // head = deleteAtBetween(head, 1); // deleted from between
      head = deleteAtLast(head); // deleted from last 
    printf("Linked List After Deletion : \n");
    linkedListTraversal(head);
    return 0;
}
