// C program to Demonstrate Priority Queue
#include <stdio.h>
#include <limits.h>
#define MAX 100
int idx = -1;
int pqVal[MAX];
int pqPriority[MAX];
int isEmpty()
{
    return idx == -1;
}
int isFull()
{
    return idx == MAX - 1;
}

void enqueue(int data, int priority)
{
    if (!isFull())
    {

        // Increase the index
        idx++;

        // Insert the element in priority queue
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}

int peek()
{
    int maxPriority = INT_MIN;
    int indexPos = -1;

    // Linear search for highest priority
    for (int i = 0; i <= idx; i++)
    {
        // If two items have same priority choose the one with
        // higher data value
        if (maxPriority == pqPriority[i] && indexPos > -1 && pqVal[indexPos] < pqVal[i])
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
        else if (maxPriority < pqPriority[i])
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }

    // Return index of the element where
    return indexPos;
}

void dequeue()
{
    if (!isEmpty())
    {
        // Get element with highest priority
        int indexPos = peek();
        for (int i = indexPos; i < idx; i++)
        {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }

        // reduce size of priority queue by 1
        idx--;
    }
}

void display()
{
    for (int i = 0; i <= idx; i++)
    {
        printf("(%d, %d)\n", pqVal[i], pqPriority[i]);
    }
}
// Driver Code
int main()
{
    // To enqueue items as per priority
    enqueue(5, 1);
    enqueue(10, 3);
    enqueue(15, 4);
    enqueue(20, 5);
    enqueue(500, 2);

    printf("Before Dequeue : \n");
    display();

    // Dequeue the top element
    dequeue(); // 20 dequeued
    dequeue(); // 15 dequeued

    printf("\nAfter Dequeue : \n");
    display();

    return 0;
}