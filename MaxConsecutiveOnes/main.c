#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) 
{

       int i;
       int count1 = 0;
       int count2 = 0;
       int flag = 0;

       for(i=0;i<numsSize;i++)
       {
            if(nums[i]==1)
            {
                count1++;
            }
            else
            {
                count1 = 0;
            }
            if(count1>count2)
            {
                count2 = count1;
            }
       }
       return count2;
}

int main() 
{     
    int result;
    int nums[1] = {1}; 
    result = findMaxConsecutiveOnes(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", result);
} 

