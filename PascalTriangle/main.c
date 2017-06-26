#include <stdio.h>
#define bool int
int** generate(int numRows, int** columnSizes) 
{
       int i, j;
       int **result;
       *columnSizes = (int *)malloc(sizeof(int)*numRows);
        result = (int **)malloc(sizeof(int *)*numRows);
        for(i=0;i<numRows;i++)
        {
            (*columnSizes)[i] = i + 1;
            result[i] = (int *)malloc(sizeof(int)*(i+1));
            for(j=0;j<(i+1);j++)
            {
                if(j==0||j==i)
                {
                    result[i][j] = 1;
                    printf("%d\t", result[i][j]);
                }
                else
                {
                    result[i][j] = result[i-1][j-1] + result[i-1][j];
                    printf("%d\t", result[i][j]);
                }
            }
            printf("\n");
          }
}
int main() 
{   
    int** result;
    int *columnSizes;
    result = generate(5, &columnSizes);
} 
