#include <stdio.h>
int min(float average, int *nums, int numsSize)
{
    int result;
    int i;
    float tmp;
    result = nums[0];
    tmp = fabs(nums[0]-average);
    for(i=1;i<numsSize;i++)
    {
        if(tmp>abs(nums[i]-average))
        {
            tmp = fabs(nums[i]-average);
            result = nums[i];
        }
    }
    return result;
}
int minMoves2(int* nums, int numsSize)  
{
   int i;
   int sum = 0;
   float tmp;
   int average;
   int result = 0;
   for(i=0;i<numsSize;i++)
   {
        sum = sum + nums[i];
   }
   tmp = (float)sum/numsSize;
   average = min(tmp, nums, numsSize);
   printf("----%d\n", average);
   for(i=0;i<numsSize;i++)
   {
       result = result + abs(nums[i]-average);
   }
   return result;
   //printf("%d\n", result);
}
int main() 
{     
   int result;
   int *nums;
   int numsSize = 5;
   nums = (int *)malloc(sizeof(int)*numsSize); 
   nums[0] = 1;
   nums[1] = 0;
   nums[2] = 0;
   nums[3] = 8;
   nums[4] = 6;
   result = minMoves2(nums, numsSize);
   printf("%d\n", result);
   
} 
