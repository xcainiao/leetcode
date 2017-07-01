#include <stdio.h>

int subarraySum(int* nums, int numsSize, int k) 
{
    int i = 0;
    int j = 0;
    int sum=0;
    int result = 0;
    for(i=0;i<numsSize;i++)
    {
        j = i;
        while(j<numsSize)
        {
            sum = sum + nums[j];
            if(sum == k)
                result++;
            j++;
        }
        sum = 0;
    }
    return result;
}

int main() 
{   
    int result;
    int nums[3] = {1, 1, 1};
    result = subarraySum(nums, 3, 2);
    printf("%d\n", result);
} 
