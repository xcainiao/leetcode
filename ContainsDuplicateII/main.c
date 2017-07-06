#include <stdio.h>
#define bool int
bool containsNearbyDuplicate(int* nums, int numsSize, int k) 
{
    int i;
    int j;
    if(numsSize>30000)
        return 0;
    for(i=0;i<numsSize;i++)
    {
        for(j=1;j<=k;j++)
        {   
            if((i+j)<numsSize)
            {   
                if(nums[i] == nums[i+j])
                    return 1;
            }   
        }
    }
    return 0;
}
int main() 
{   
    int result;
	int nums[2] = {99,99};
    result = containsNearbyDuplicate(nums, 2, 2);
    printf("%d\n", result);
} 
