#include <stdio.h>

#define bool int

bool containsDuplicate(int* nums, int numsSize) 
{
    int i,j;
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize;j++)
        {
            if(nums[i]==nums[j]&&i!=j)
                return 1;
        }
    }
    return 0;
}
int main(int argc, char *argv[])
{
	int nums[5] = {1,1,2,3,1};
	int result;
	int len;
	len = sizeof(nums)/sizeof(int);
	result = containsDuplicate(nums, len);
	printf("%d\n", result);
}
