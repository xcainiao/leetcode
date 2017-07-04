#include <stdio.h>
int findUnsortedSubarray(int* nums, int numsSize) 
{
    int i,j;
    int tmp1=-1;
    int tmp2=-1;
    for(i=0;i<numsSize;i++)
    {
        for(j=i;j<numsSize;j++)
        {
            if(nums[i]>nums[j])
            {
                tmp1 = i;
                //printf("aaaaaaaaaa\n");
                //break;
                goto next;
            }
        }
    }
next:
    if(tmp1==-1)
        return 0;
    for(i=numsSize-1;i>=0;i--)
    {
        for(j=i;j>=0;j--)
        {
            if(nums[i]<nums[j])
            {
                tmp2 = i;
                goto over;
            }
        }
    }
over:
    //printf("%d\n", tmp2);
    return tmp2-tmp1+1;
}

int main() 
{   
    int result;
	char nums[] = {2, 1};
    result = findUnsortedSubarray(nums, 2);
    printf("%d\n", result);
} 
