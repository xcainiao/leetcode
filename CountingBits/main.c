#include <stdio.h>

int* countBits(int num, int* returnSize) 
{
    int i;
    int *result;
    *returnSize = num + 1;
    result = (int *)malloc(sizeof(int)*(num+1));
    result[0] = 0;
    for(i=0;i<(num+1);i++)
    {
        if(i&1==1)
            result[i] = result[i>>1]+1;
        else
            result[i] = result[i>>1];
    }
    return result;
}

int main(int argc, char *argv[])
{
    int num = 4;
    int returnSize;
    int *result;
    int i;
    result = countBits(num, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n", result[i]);
    }
}

