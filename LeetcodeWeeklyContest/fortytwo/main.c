#include <stdio.h>
int* findErrorNums(int* nums, int numsSize, int* returnSize) 
{
    int tmp[numsSize + 1];
    int i;
    int *result;
    int result1 = 0;
    int result2 = 0;
    *returnSize = 2;
    result = (int*)malloc(sizeof(int)*2);
    for(i=0; i<=numsSize; i++)
    {
        tmp[i] = 0;
    }
    for(i=0; i<numsSize; i++)
    {
        tmp[nums[i]]  = tmp[nums[i]] + 1;
    }
    for(i=1; i<=numsSize; i++)
    {
        if(tmp[i] == 0)
        {
            //printf("%d\n", i);
            result2 = i;
            //printf("%d\n", result2);
        }
        if(tmp[i] == 2)
        {
            //printf("%d\n", i);
            result1 = i;
            //printf("%d\n", result1);
        }
    }
    result[0] = result1;
    result[1] = result2;
    return result;
}
int main()
{
    int i;
    int *result;
    int returnSize;
    int nums[4] = {1, 2, 2, 4};
    result = findErrorNums(nums, 4, &returnSize); 
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n", result[i]);
    }
}
