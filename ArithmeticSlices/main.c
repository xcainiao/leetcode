#include <stdio.h>
int numberOfArithmeticSlices(int* A, int ASize) 
{
    int i;
    int j;
    int count = 0;
    int result = 0;
    for(i=0;i<ASize-2;i++)
    {
        if((A[i+2]-A[i+1])==(A[i+1]-A[i]))
        {
            count++; 
        }
        else
        {
            for(j=count;j>0;j--)
            {
               result = result + j; 
               count = 0;
            }
        }
    }
    for(j=count;j>0;j--)
    {
         result = result + j; 
    }
    return result;
}
int main() 
{     
    int result;
    int *A;
    int ASize;
    ASize = 7;
    A = (int *)malloc(sizeof(int)*ASize);
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 5;
    A[4] = 2;
    A[5] = 3;
    A[6] = 4;
    result = numberOfArithmeticSlices(A, ASize);
    printf("%d\n", result);
} 
