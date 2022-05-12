// WAP to for selection Sort to Sort Elements in An Order.

#include <stdio.h>
void swap(int arr[], int first, int second)
{
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}
int getMaxIndex(int arr[], int start, int end)
{
    int max = start;
    for (int i = start; i < end; i++)
    {
        if (arr[max] < arr[i])
        {
            max = i;
        }
    }
    return max;
}
void selectionSort(int arr[], int length)
{

    for (int i = 0; i < length; i++)
    {
        // find the max item in remaining array and swap with correct with correct index
        int last = length - i - 1;
        int maxIndex = getMaxIndex(arr, 0, last);
        swap(arr, maxIndex, last);
    }
}

void main()

{
    int size = 0;
    printf("Enter the Size of array : ");
    scanf("%d", &size);
    int array[size];
    int length = sizeof(array) / sizeof(int);
    printf("Enter the Elements in array ⤵");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    selectionSort(array, size);
    printf("Sorted Elements are  ⤵ ");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
}