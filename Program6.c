// Q 6. WAP to sort a given list of no in ascending order and print
// original and sorted list using function.

#include <stdio.h>
// Sort the array in ascending order
void sort(int arr[], int length)
{
    int temp = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    // Initialize array
    int n = 0;
    printf("Enter the Size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Element of the Array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Calculate length of array arr
    int length = sizeof(arr) / sizeof(arr[0]);

    // Displaying elements of original array
    printf("Elements of original array: \n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    sort(arr, length);

    printf("\n");

    // Displaying elements of array after sorting
    printf("Elements of array sorted in ascending order: \n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}