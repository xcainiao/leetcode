#include <stdio.h>
#define bool int
int singleNonDuplicate(int* nums, int numsSize) 
{
    int i;
    for(i=0;i<numsSize;i=i+2)
    {
        if(nums[i]!=nums[i+1])
            return nums[i]; 
    }
    return 0;
}
int main() 
{   
    int result;
	int nums[5] = {1,1,2,3,3};
    result = singleNonDuplicate(nums, 5);
    printf("%d\n", result);
} 
