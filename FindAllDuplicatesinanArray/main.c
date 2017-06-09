#include <stdio.h>

int* findDuplicates(int* nums, int numsSize, int* returnSize) 
{
    int i;
    int tmp[65535];
    int *result;
    for(i=0;i<65535;i++)
    {
        tmp[i] = 2;
    }
    result = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = 0;
    for(i=0;i<numsSize;i++)
    {
        tmp[nums[i]]--;
        if(tmp[nums[i]] == 0 )
        {
            result[*returnSize] = nums[i];
            (*returnSize)++;
        }
    }
    return result;
}

int main() 
{     
    int returnSize;
    int nums[10] = {1,1,2,3,4,5,6,7,7,9};
    int *result;
    int i;
    result = findDuplicates(nums, 10, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n", result[i]);
    }
}  
