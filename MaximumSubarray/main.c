#include <stdio.h>

#define INT_MIN -10000

int maxVal(int *nums, int size)
{
    int i;
    int max;
    int tmp;
    max = nums[0];
    tmp = 0;
    for(i=0;i<size;i++)
    {
        tmp = tmp + nums[i];
        if(tmp>max)
        {
            max = tmp;
        }
    }
    return max;    
}

int maxSubArray(int* nums, int numsSize) 
{
    int i;
    int tmp;
    int max = INT_MIN;
    for(i=0;i<numsSize;i++)
    {
        //printf("%d\n", i);
        tmp = maxVal(nums+i, numsSize-i);
        if(tmp>max)
            max = tmp;
    }
    return max;
}

int main() 
{   
    int result;
    int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
    result = maxSubArray(nums, 9);
    printf("%d\n", result);
} 
