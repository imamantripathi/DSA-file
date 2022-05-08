// Q 9. WAP to calculate sum of each rows and columns and total
//of all element of matrix.
#include <stdio.h>  
   
int main()  
{  
    int rows, cols, sumRow, sumCol;  
  
      
    //Initialize matrix a  
    int a[][3] = {     
                    {1, 2, 3},  
                    {4, 5, 6},  
                    {7, 8, 9}  
                };  
      
    //Calculates number of rows and columns present in given matrix  
    rows = (sizeof(a)/sizeof(a[0]));  
    cols = (sizeof(a)/sizeof(a[0][0]))/rows;  
      
    //Calculates sum of each row of given matrix  
    for(int i = 0; i < rows; i++){  
        sumRow = 0;  
        for(int j = 0; j < cols; j++){  
          sumRow = sumRow + a[i][j];  
        }  
        printf("Sum of %d row: %d\n", (i+1), sumRow);  
    }  
      
    //Calculates sum of each column of given matrix  
    for(int i = 0; i < cols; i++){  
        sumCol = 0;  
        for(int j = 0; j < rows; j++){  
          sumCol = sumCol + a[j][i];  
        }  
        printf("Sum of %d column: %d\n", (i+1), sumCol);  
    }  
          
    return 0;  
}  