#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int i;
    int *result;
    int tmp = 0;
    int tmpi[digitsSize+1];
    result = (int*)malloc(sizeof(int)*(digitsSize+1));
    
    if(digits[digitsSize-1] == 9)
    {
        tmpi[digitsSize-1] = 0;
        tmp = 1;
    }
    else
    {
        tmpi[digitsSize-1] = digits[digitsSize-1] + 1;
    }
    for(i=(digitsSize-2);i>=0;i--)
    {
        if((digits[i]+tmp) == 10)
        {
            tmpi[i] = 0;
            tmp = 1;
            //printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
        }
        else
        {
            tmpi[i] = digits[i] + tmp;
            tmp = 0;
        }
    }
    if(tmp==1)
    {
        *returnSize = digitsSize + 1;
        result[0] = 1;
        for(i=1;i<*returnSize;i++)
        {
            result[i] = 0;
        }
    }
    else
    {
        *returnSize = digitsSize;
        for(i=0;i<*returnSize;i++)
        {
            result[i] = tmpi[i];
            printf("%d\n", result[i]);
        }
    }
    return result;
}

int main() 
{   
    int i;
    int *result;
    int digits[10] = {9,8,7,6,5,4,3,2,1,0};
    int returnSize;
    result = plusOne(digits, 10, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        //printf("%d\n", result[i]);
    }
} 
