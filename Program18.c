#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ans;
    ans='Y';
    while(ans=='Y'||ans=='y'){
    int rows,cols;
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);
    int arr[rows+1][cols+1];
    int flag, flag1;
    flag=0;
    flag1=0;
    printf("Enter the elements of the matrix: \n");
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            if(j>i && arr[i][j]!=0)
            {
                flag=1;
                break;
            }
        }
    }
    
    if(flag==0)
    {
        printf("The entered Matrix is a Lower Triangular Sparse Matrix\n");
    }
    else
    {
        printf("The entered Matrix is not a Lower Triangular Sparse Matrix\n");
    }
    
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            if(j<i &&  arr[i][j]!=0)
            {
                flag1=1;
                break;
            }
        }
    }
    
    if(flag1==0)
    {
        printf("The entered Matrix is a Upper Triangular Sparse Matrix\n");
    }
    else 
    {
        printf("The entered Matrix is not a Upper Triangular Sparse Matrix\n");
    }
    
    printf("If you want to run the program again press Y: ");
    scanf(" %c", &ans);
    if(ans!='Y'&& ans!='y')
    {
        printf("Exiting the program");
        exit(0);
    }
    printf("\n");
}
    return 0;
}