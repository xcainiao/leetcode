#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int i;
    int j;
    int res = 0;
    int tmp = 0;
    for(i=0;i<numsSize;i++)
    {   
        tmp = 0;
        for(j=0;j<numsSize;j++)
        {
            if(nums[i] == nums[j])
            {
                tmp++;
            }
        }
        if(tmp>numsSize/2)
        {
            res = nums[i];
            break;
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
	int result;
	int nums[10] = {1,1,1,1,1,1,2,3,2,2};
    int len;
    len = sizeof(nums)/sizeof(int);
	result = majorityElement(nums, len); 
	printf("%d\n", result);
}
