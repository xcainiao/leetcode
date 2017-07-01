#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    int *result;
    int i;
    int j;
    for(i=0;i<numsSize;i++)
    {   
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j] == target)
                goto result;
        }
    }   
result:
    * returnSize = 2;
    result =(int *)malloc(sizeof(int)*2);
    result[0] = i+1;
    result[1] = j+1;
    printf("%d\n", result[0]);
    printf("%d\n", result[1]);
    return result;
}

int main() 
{   
    int* result;
	int size = 0;
    int nums[4] = {2, 7, 11, 15};
    result = twoSum(nums, 4, 9, &size);
} 
