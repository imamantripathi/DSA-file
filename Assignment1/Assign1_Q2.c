#include <stdio.h>
int c = 0;
void bubble(int a[], int n) // function to implement bubble sort
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                c++;
            }
        }
    }
}

int search(int arr[], int n, int x)

{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int size = 0;
    printf("Enter the size of Array: ");
    scanf("%d", &size);

    int arr[size];
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter the elements in Array: \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d" , &arr[i]);
    }

    bubble(arr,n);
    printf("The Sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",arr[i]);
    }
    printf("\n");
    printf("The Number of swapping in Bubble Sort : %d\n",c);

    // Function call
    int x = 0;
    printf("Enter the Element for search : ");
    scanf("%d", &x);
    int result = search(arr, n, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}