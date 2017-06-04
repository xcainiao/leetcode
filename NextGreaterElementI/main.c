#include <stdio.h>

int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) 
{       
    int i, j;
    int tmp[65535];
    int *result;
    int count = 0;
    memset(tmp, 0, 1000);
    for(i=0;i<numsSize;i++)
    {
        tmp[nums[i]] = i + 1;
    }
    result = (int *)malloc(sizeof(int)*findNumsSize);
    *returnSize = findNumsSize;
    for(i=0;i<findNumsSize;i++)
    {
        if(tmp[findNums[i]] != 0 && (tmp[findNums[i]]<(numsSize)))
        {
            for(j=tmp[findNums[i]];j<numsSize;j++)
            {
                if(nums[j]>nums[tmp[findNums[i]]-1])
                {
                   result[count] = nums[j];
                   break;
                }
            }
        }
        else
        {
            result[count] = -1; 
        }
        if(j == numsSize)
        {
            result[count] = -1; 
        }
        count++;
    }
    return result;
}

int main(int argc, char *argv[])
{
    int findNums[3] = {4, 1, 2};
    int findNumsSize = 3;
    int nums[4] = {1, 3, 4, 2};
    int numsSize = 4;
    int i;
    int returnSize;
    int *result;
    result = nextGreaterElement(findNums, findNumsSize, nums, numsSize, &returnSize);
    for(i=0;i<returnSize;i++)
    {
        printf("%d\n", result[i]);
    }
}
