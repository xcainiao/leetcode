#include <stdio.h>

int thirdMax(int* nums, int numsSize) 
{
    int max1 = -2147483647L-1;
    int max2 = -2147483647L-1;
    int max3 = -2147483647L-1;
    int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max1)
            max1 = nums[i];
    }
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max2 && nums[i]<max1)
            max2 = nums[i];
    }
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]>max3 && nums[i]<max1 && nums[i]<max2)
            max3 = nums[i];
    }
    if(max3 == -2147483647L-1)
        return max1;
    return max3;
}

int main() 
{   
    int result;
    int nums[3] = {2, 2, 3};
    result = thirdMax(nums, 3); 
    printf("%d\n", result);
} 
